#ifndef ROUTESIMULATOR_H
#define ROUTESIMULATOR_H

#include <QObject>
#include <QGeoCoordinate>
#include <QTimer>
#include <QList>

class RouteSimulator : public QObject {
    Q_OBJECT
    // Expose các biến này ra QML
    Q_PROPERTY(QGeoCoordinate currentPosition READ currentPosition NOTIFY positionChanged)
    Q_PROPERTY(double heading READ heading NOTIFY headingChanged)
    Q_PROPERTY(double speedKmh READ speedKmh WRITE setSpeedKmh NOTIFY speedChanged)

public:
    explicit RouteSimulator(QObject *parent = nullptr);

    QGeoCoordinate currentPosition() const { return m_currentPosition; }
    double heading() const { return m_heading; }
    double speedKmh() const { return m_speedKmh; }
    void setSpeedKmh(double speed);

    // Hàm nhận mảng tọa độ từ API (được gọi từ C++ hoặc QML)
    Q_INVOKABLE void setRoute(const QVariantList &coordinates);
    Q_INVOKABLE void startSimulation();
    Q_INVOKABLE void stopSimulation();

signals:
    void positionChanged();
    void headingChanged();
    void speedChanged();

private slots:
    void updateTick(); // Hàm được QTimer gọi liên tục

private:
    QList<QGeoCoordinate> m_route;
    int m_currentIndex;
    QGeoCoordinate m_currentPosition;
    double m_heading;
    double m_speedKmh;

    QTimer *m_timer;
    const int TICK_RATE_MS = 50; // Cập nhật mỗi 50ms (20 FPS)
};

#endif // ROUTESIMULATOR_H
