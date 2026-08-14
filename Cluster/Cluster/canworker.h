#ifndef CANWORKER_H
#define CANWORKER_H

#include <QObject>
#include <QSocketNotifier>
#include <QDebug>

class CanWorker : public QObject
{
    Q_OBJECT
public:
    explicit CanWorker(QObject *parent = nullptr);
    ~CanWorker();

signals:
    void canDataReceived(int speed, int battery);
    void warningDataReceived(bool left, bool right, bool cos, bool pha, bool belt);
    void gpsDataReceived(float lat, float lng);

public slots:
    void start();
    void sendWarningCommand(bool left, bool right, bool cos, bool pha, bool belt);

private slots:
    void readCanFrame();

private:
    int sock;
    QSocketNotifier *m_notifier;
    int current_speed;
    int current_battery;
};

#endif // CANWORKER_H
