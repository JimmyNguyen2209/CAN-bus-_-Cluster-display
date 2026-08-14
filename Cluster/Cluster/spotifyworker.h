#ifndef SPOTIFYWORKER_H
#define SPOTIFYWORKER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QTimer>

class SpotifyWorker : public QObject
{
    Q_OBJECT

public:
    explicit SpotifyWorker(QObject *parent = nullptr);

signals:
    void spotifyChanged(const QString &title, const QString &artist, const QString &album);
    void playbackStateChanged(bool isPlaying);
    void loginSuccess();

public slots:
    void start();
    void pauseResume();
    void nextTrack();
    void previousTrack();

private slots:
    void refreshAccessToken();
    void fetchAndActivateDevice();
    void fetchCurrentPlayback();
    void onPlaybackReceived(QNetworkReply *reply);
    void onControlReplyFinished(QNetworkReply *reply);

private:
    void sendPlayerCommand(const QByteArray &method, const QString &endpoint, const QByteArray &body = "");

    const QString m_clientId     = "3fc43a84157b4bda8d8eed7281b1d686";
    const QString m_clientSecret = "eac6f3543dc744418a930f1bb36e8a87";
    const QString m_refreshToken = "AQCbzRscZNagYbpFhol1MfcYi3YLIiBVFg5fOH1pB2acUAknYAtt1hVuM8cq_wTW2kqcS2OgAhx7YXkq9IT894aU2AbIzy9TDaYgQrBGzHvrfr5GUN_ALFsTglp2hj3xiC0";

    QNetworkAccessManager *m_networkManager  = nullptr;
    QNetworkAccessManager *m_controlManager  = nullptr;
    QTimer                *m_pollTimer       = nullptr;
    QTimer                *m_tokenRefreshTimer = nullptr;
    QString                m_accessToken;
    QString                m_deviceId;
    bool                   m_isPlaying = false;
};

#endif // SPOTIFYWORKER_H
