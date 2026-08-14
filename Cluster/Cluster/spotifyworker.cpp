#include "spotifyworker.h"
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

SpotifyWorker::SpotifyWorker(QObject *parent) : QObject(parent) {}

void SpotifyWorker::start()
{
    m_networkManager   = new QNetworkAccessManager(this);
    m_controlManager   = new QNetworkAccessManager(this);
    m_pollTimer        = new QTimer(this);
    m_tokenRefreshTimer = new QTimer(this);

    connect(m_pollTimer,         &QTimer::timeout,
            this,                &SpotifyWorker::fetchCurrentPlayback);
    connect(m_networkManager,    &QNetworkAccessManager::finished,
            this,                &SpotifyWorker::onPlaybackReceived);
    connect(m_controlManager,    &QNetworkAccessManager::finished,
            this,                &SpotifyWorker::onControlReplyFinished);
    connect(m_tokenRefreshTimer, &QTimer::timeout,
            this,                &SpotifyWorker::refreshAccessToken);

    refreshAccessToken();
}

// =========================================================
// LẤY ACCESS TOKEN MỚI TỪ REFRESH TOKEN
// =========================================================
void SpotifyWorker::refreshAccessToken()
{
    QNetworkRequest request;
    request.setUrl(QUrl("https://accounts.spotify.com/api/token"));
    request.setHeader(QNetworkRequest::ContentTypeHeader,
                      "application/x-www-form-urlencoded");

    QUrlQuery postData;
    postData.addQueryItem("grant_type",    "refresh_token");
    postData.addQueryItem("refresh_token", m_refreshToken);
    postData.addQueryItem("client_id",     m_clientId);
    postData.addQueryItem("client_secret", m_clientSecret);

    QNetworkAccessManager *authManager = new QNetworkAccessManager(this);
    QNetworkReply *reply = authManager->post(
        request, postData.toString(QUrl::FullyEncoded).toUtf8());

    connect(reply, &QNetworkReply::finished, this, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            QJsonObject json = QJsonDocument::fromJson(reply->readAll()).object();
            m_accessToken = json.value("access_token").toString();
            qDebug() << "Spotify: Lấy access token thành công.";

            emit loginSuccess();

            // Lấy danh sách device và kích hoạt, sau đó mới bắt đầu poll
            fetchAndActivateDevice();

            // Làm mới token mỗi 50 phút
            if (!m_tokenRefreshTimer->isActive())
                m_tokenRefreshTimer->start(3000000);
        } else {
            qDebug() << "Lỗi refresh token:" << reply->errorString();
            qDebug() << reply->readAll();
        }
        reply->deleteLater();
        authManager->deleteLater();
    });
}

// =========================================================
// LẤY DANH SÁCH DEVICE VÀ CHUYỂN PLAYBACK VỀ DEVICE ĐÓ
// =========================================================
void SpotifyWorker::fetchAndActivateDevice()
{
    if (m_accessToken.isEmpty()) return;

    QNetworkRequest request(QUrl("https://api.spotify.com/v1/me/player/devices"));
    request.setRawHeader("Authorization", "Bearer " + m_accessToken.toUtf8());

    QNetworkAccessManager *mgr = new QNetworkAccessManager(this);
    QNetworkReply *reply = mgr->get(request);

    connect(reply, &QNetworkReply::finished, this, [=]() {
        if (reply->error() != QNetworkReply::NoError) {
            qDebug() << "Lỗi lấy device list:" << reply->errorString();
            reply->deleteLater(); mgr->deleteLater(); return;
        }

        QJsonArray devices = QJsonDocument::fromJson(reply->readAll())
                                 .object().value("devices").toArray();

        if (devices.isEmpty()) {
            qDebug() << "Không có thiết bị Spotify nào. Hãy mở Spotify trên điện thoại hoặc máy tính.";
            reply->deleteLater(); mgr->deleteLater();
            // Vẫn bật poll để hiển thị trạng thái dừng
            if (!m_pollTimer->isActive()) m_pollTimer->start(2000);
            return;
        }

        // Ưu tiên device đang active; nếu không có thì lấy cái đầu tiên
        m_deviceId = "";
        for (const QJsonValue &d : devices) {
            if (d.toObject().value("is_active").toBool()) {
                m_deviceId = d.toObject().value("id").toString();
                break;
            }
        }
        if (m_deviceId.isEmpty())
            m_deviceId = devices.at(0).toObject().value("id").toString();

        qDebug() << "Spotify device:" << m_deviceId;

        // Chuyển playback context về device (không tự phát, chỉ chuyển)
        QJsonObject body;
        QJsonArray ids;
        ids.append(m_deviceId);
        body["device_ids"] = ids;
        body["play"] = false;
        sendPlayerCommand("PUT", "", QJsonDocument(body).toJson());

        reply->deleteLater(); mgr->deleteLater();

        if (!m_pollTimer->isActive()) m_pollTimer->start(2000);
    });
}

// =========================================================
// HÀM CHUNG GỬI LỆNH ĐIỀU KHIỂN (PUT / POST)
// =========================================================
void SpotifyWorker::sendPlayerCommand(const QByteArray &method,
                                      const QString &endpoint,
                                      const QByteArray &body)
{
    if (m_accessToken.isEmpty()) return;

    QString urlStr = "https://api.spotify.com/v1/me/player";
    if (!endpoint.isEmpty()) urlStr += "/" + endpoint;

    // Gắn device_id vào query (bắt buộc với play/pause/next/prev)
    if (!m_deviceId.isEmpty() && !endpoint.isEmpty())
        urlStr += "?device_id=" + m_deviceId;

    QUrl url(urlStr);
    QNetworkRequest request(url);
    request.setRawHeader("Authorization", "Bearer " + m_accessToken.toUtf8());
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    if (method == "PUT")
        m_controlManager->put(request, body);
    else if (method == "POST")
        m_controlManager->post(request, body);
}

// =========================================================
// XỬ LÝ RESPONSE CỦA LỆNH ĐIỀU KHIỂN
// Sau khi thành công → fetch lại ngay để UI cập nhật
// =========================================================
void SpotifyWorker::onControlReplyFinished(QNetworkReply *reply)
{
    int code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    QByteArray body = reply->readAll();
    qDebug() << "[Spotify] Control reply HTTP" << code << body;
    if (reply->error() == QNetworkReply::NoError || code == 204) {
        QTimer::singleShot(400, this, &SpotifyWorker::fetchCurrentPlayback);
    } else {
        qDebug() << "[Spotify] Control error:" << reply->errorString();
    }
    reply->deleteLater();
}

// =========================================================
// PAUSE / RESUME (TOGGLE)
// =========================================================
void SpotifyWorker::pauseResume()
{
    if (m_isPlaying)
        sendPlayerCommand("PUT", "pause");
    else
        sendPlayerCommand("PUT", "play");
}

// =========================================================
// CHUYỂN BÀI TIẾP THEO
// =========================================================
void SpotifyWorker::nextTrack()
{
    sendPlayerCommand("POST", "next");
}

// =========================================================
// CHUYỂN BÀI TRƯỚC
// =========================================================
void SpotifyWorker::previousTrack()
{
    sendPlayerCommand("POST", "previous");
}

// =========================================================
// LẤY TRẠNG THÁI NHẠC ĐANG PHÁT
// =========================================================
void SpotifyWorker::fetchCurrentPlayback()
{
    if (m_accessToken.isEmpty()) return;

    QNetworkRequest request(
        QUrl("https://api.spotify.com/v1/me/player/currently-playing"));
    request.setRawHeader("Authorization", "Bearer " + m_accessToken.toUtf8());
    m_networkManager->get(request);
}

// =========================================================
// PHÂN TÍCH JSON VÀ ĐẨY LÊN UI
// =========================================================
void SpotifyWorker::onPlaybackReceived(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError) {
        reply->deleteLater(); return;
    }

    int code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    if (code == 204) {
        m_isPlaying = false;
        emit playbackStateChanged(false);
        emit spotifyChanged("Đang dừng phát nhạc", "-", "");
        reply->deleteLater(); return;
    }

    QJsonObject json = QJsonDocument::fromJson(reply->readAll()).object();

    m_isPlaying = json.value("is_playing").toBool();
    emit playbackStateChanged(m_isPlaying);

    if (json.contains("item") && !json.value("item").isNull()) {
        QJsonObject item = json.value("item").toObject();
        QString title = item.value("name").toString();

        QJsonArray artistsArr = item.value("artists").toArray();
        QStringList artists;
        for (const QJsonValue &a : artistsArr)
            artists.append(a.toObject().value("name").toString());

        QString albumImageUrl;
        QJsonArray images = item.value("album").toObject()
                                .value("images").toArray();
        if (!images.isEmpty())
            albumImageUrl = images.at(0).toObject().value("url").toString();

        emit spotifyChanged(title, artists.join(", "), albumImageUrl);
    }
    reply->deleteLater();
}
