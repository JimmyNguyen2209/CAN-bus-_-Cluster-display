#include <Arduino.h> 
#include <SPI.h>
#include <mcp2515.h>

#define POT_PIN 34 // Chân đọc biến trở (Chân giữa của biến trở cắm vào đây)
#define CS_PIN 5   // Chân CS nối với module MCP2515

MCP2515 mcp2515(CS_PIN);
struct can_frame canMsgSpeed;

unsigned long lastTime = 0;

void setup() {
Serial.begin(115200);
  while (!Serial); // Đợi Serial khởi động
  
  Serial.println("Đang khởi tạo MCP2515...");
  
  mcp2515.reset();
  // Kiểm tra cấu hình Bitrate
  if (mcp2515.setBitrate(CAN_500KBPS, MCP_8MHZ) == MCP2515::ERROR_OK) {
    Serial.println("Cấu hình Bitrate THÀNH CÔNG!");
  } else {
    Serial.println("LỖI: Không thể cấu hình Bitrate. Kiểm tra lại dây SPI!");
  }
  
  if (mcp2515.setNormalMode() == MCP2515::ERROR_OK) {
    Serial.println("Vào chế độ Normal THÀNH CÔNG!");
  } else {
    Serial.println("LỖI: Không thể vào Normal Mode!");
  }
}

void loop() {
  // Giãn cách 50ms gửi 1 lần (20 lần/giây) giúp xe trên QML chạy mượt mà không bị tràn bộ đệm CAN
  if (millis() - lastTime > 50) {
    
    // 1. Đọc giá trị analog từ biến trở (Từ 0 đến 4095)
    int potValue = analogRead(POT_PIN);

    // 2. Chuyển đổi giá trị đó sang tốc độ (Từ 0 đến 320 km/h)
    int speed = map(potValue, 0, 4095, 0, 320);

    // 3. Đóng gói dữ liệu vào khung chuẩn CAN
    canMsgSpeed.can_id  = 0x100;
    canMsgSpeed.can_dlc = 8; // Gửi đủ 8 bytes
    
    canMsgSpeed.data[0] = speed & 0xFF;         // Byte thấp của tốc độ
    canMsgSpeed.data[1] = (speed >> 8) & 0xFF;  // Byte cao của tốc độ
    
    // Các byte còn lại không dùng đến thì cho bằng 0 cho sạch
    for(int i = 2; i < 8; i++) {
      canMsgSpeed.data[i] = 0x00;               
    }

    // 4. Bắn gói tin lên đường dây CAN
    MCP2515::ERROR err = mcp2515.sendMessage(&canMsgSpeed);

    // 5. In ra Serial Monitor để ông dễ theo dõi
    if (err == MCP2515::ERROR_OK) {
      Serial.printf("Gui toc do: %d km/h OK\n", speed);
    } else {
      Serial.println("Loi gui CAN! Kiem tra lai day hoac Pi chua mo port.");
    }

    lastTime = millis();
  }
}