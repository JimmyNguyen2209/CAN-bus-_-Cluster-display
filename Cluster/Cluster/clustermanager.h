#ifndef CLUSTERMANAGER_H
#define CLUSTERMANAGER_H

#include <QObject>
#include <QString>

class ClusterManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString loginUrl  READ loginUrl  NOTIFY loginUrlChanged)
    Q_PROPERTY(bool    isPlaying READ isPlaying NOTIFY isPlayingChanged)
public:
    explicit ClusterManager(QObject *parent = nullptr)
        : QObject(parent)
        , m_loginUrl("")
        , m_isPlaying(false)
    {}

    QString loginUrl()  const { return m_loginUrl; }
    bool    isPlaying() const { return m_isPlaying; }

public slots:
    void handleCanData(int speed, int battery)
    {
        emit canDataReceived(speed, battery);
    }

    // ── SLOT MỚI: Tiếp nhận trạng thái 5 đèn cảnh báo từ CanWorker ──
    void handleWarningData(bool left, bool right, bool cos, bool pha, bool belt)
    {
        emit warningDataReceived(left, right, cos, pha, belt);
    }

    void handleSpotifyData(const QString &title, const QString &artist, const QString &albumArt)
    {
        emit spotifyChanged(title, artist, albumArt);
    }

    void handlePlaybackState(bool playing)
    {
        if (m_isPlaying != playing) {
            m_isPlaying = playing;
            emit isPlayingChanged();
        }
    }

    void setLoginUrl(const QString &url)
    {
        if (m_loginUrl != url) {
            m_loginUrl = url;
            emit loginUrlChanged();
        }
    }

    void handleLoginSuccess() { emit loginSuccess(); }

    Q_INVOKABLE void toggleWarningFromUI(bool left, bool right, bool cos, bool pha, bool belt)
    {
        emit requestSendWarningCommand(left, right, cos, pha, belt);
    }

    Q_INVOKABLE void pauseResume()    { emit requestPauseResume(); }
    Q_INVOKABLE void nextTrack()      { emit requestNextTrack(); }
    Q_INVOKABLE void previousTrack()  { emit requestPreviousTrack(); }

signals:
    void canDataReceived(int speed, int battery);
    // ── SIGNAL MỚI: Bắn tín hiệu 5 đèn lên màn hình QML ──
    void warningDataReceived(bool left, bool right, bool cos, bool pha, bool belt);

    void spotifyChanged(const QString &title, const QString &artist, const QString &albumArt);
    void loginUrlChanged();
    void loginSuccess();
    void isPlayingChanged();

    void requestPauseResume();
    void requestNextTrack();
    void requestPreviousTrack();

    void requestSendWarningCommand(bool left, bool right, bool cos, bool pha, bool belt);
private:
    QString m_loginUrl;
    bool    m_isPlaying;
};

#endif // CLUSTERMANAGER_H
