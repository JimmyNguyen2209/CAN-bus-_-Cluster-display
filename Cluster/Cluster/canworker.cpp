#include "canworker.h"
#include <unistd.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <linux/can.h>
#include <linux/can/raw.h>
#include <string.h>

CanWorker::CanWorker(QObject *parent)
    : QObject(parent), sock(-1), m_notifier(nullptr), current_speed(0), current_battery(100)
{
}

CanWorker::~CanWorker()
{
    if (sock >= 0) {
        close(sock);
    }
}

void CanWorker::start()
{
    struct sockaddr_can addr;
    struct ifreq ifr;

    sock = socket(PF_CAN, SOCK_RAW, CAN_RAW);
    if (sock < 0) {
        qCritical() << "LỖI: Không thể mở Socket CAN!";
        return;
    }

    strcpy(ifr.ifr_name, "can0");
    if (ioctl(sock, SIOCGIFINDEX, &ifr) < 0) {
        qCritical() << "LỖI: Không tìm thấy thiết bị can0!";
        close(sock);
        return;
    }

    memset(&addr, 0, sizeof(addr));
    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        qCritical() << "LỖI: Bind socket CAN thất bại!";
        close(sock);
        return;
    }

    qDebug() << "SocketCAN kết nối thành công qua QSocketNotifier!";

    // Sử dụng QSocketNotifier để giám sát Socket.
    // Khi có dữ liệu CAN từ ESP32, nó sẽ tự động kích hoạt slot readCanFrame.
    m_notifier = new QSocketNotifier(sock, QSocketNotifier::Read, this);
    connect(m_notifier, &QSocketNotifier::activated, this, &CanWorker::readCanFrame);
}

// Hàm này tự động chạy mỗi khi có gói tin CAN lọt vào cổng can0
void CanWorker::readCanFrame()
{
    struct can_frame frame;
    int nbytes = read(sock, &frame, sizeof(struct can_frame));

    if (nbytes > 0) {
        // GÓI TIN 0x100: TỐC ĐỘ (Từ ESP32 số 1)
        if (frame.can_id == 0x100) {
            // Ráp High-Byte và Low-Byte lại
            current_speed = frame.data[0] | (frame.data[1] << 8);

            // Tạm thời fix cứng pin 85% chờ mạch thật
            current_battery = 85;

            emit canDataReceived(current_speed, current_battery);
        }
        // GÓI TIN 0x101: 5 ĐÈN CẢNH BÁO (Từ ESP32 số 2)
        else if (frame.can_id == 0x101) {
            bool left  = (frame.data[0] == 1);
            bool right = (frame.data[1] == 1);
            bool cos   = (frame.data[2] == 1);
            bool pha   = (frame.data[3] == 1);
            bool belt  = (frame.data[4] == 1);

            emit warningDataReceived(left, right, cos, pha, belt);
        }

        else if (frame.can_id == 0x103) {
            union {
                float val;
                uint8_t bytes[4];
            } lat, lng;

            // Ráp 4 byte đầu thành Vĩ độ, 4 byte sau thành Kinh độ
            for(int i = 0; i < 4; i++) {
                lat.bytes[i] = frame.data[i];
                lng.bytes[i] = frame.data[i + 4];
            }

            emit gpsDataReceived(lat.val, lng.val);
        }
    }
}

void CanWorker::sendWarningCommand(bool left, bool right, bool cos, bool pha, bool belt)
{
    if (sock < 0) return;

    struct can_frame frame;
    frame.can_id = 0x102; // ID 0x102 chuyên dùng để Pi ra lệnh cho ESP32
    frame.can_dlc = 5;

    frame.data[0] = left ? 1 : 0;
    frame.data[1] = right ? 1 : 0;
    frame.data[2] = cos ? 1 : 0;
    frame.data[3] = pha ? 1 : 0;
    frame.data[4] = belt ? 1 : 0;

    // Bắn thẳng gói tin vào mạng CAN Bus
    write(sock, &frame, sizeof(struct can_frame));
}
