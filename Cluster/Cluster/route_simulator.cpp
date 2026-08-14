#include "route_simulator.h"
#include <QDebug>

RouteSimulator::RouteSimulator(QObject *parent)
    : QObject(parent), m_currentIndex(0), m_heading(0.0), m_speedKmh(60.0) {
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &RouteSimulator::updateTick);
}

void RouteSimulator::setSpeedKmh(double speed) {
    if (m_speedKmh != speed) {
        m_speedKmh = speed;
        emit speedChanged();
    }
}

void RouteSimulator::setRoute(const QVariantList &coordinates) {
    m_route.clear();
    for (const QVariant &var : coordinates) {
        if (var.canConvert<QGeoCoordinate>()) {
            m_route.append(var.value<QGeoCoordinate>());
        }
    }
    m_currentIndex = 0;
    if (!m_route.isEmpty()) {
        m_currentPosition = m_route.first();
        emit positionChanged();
    }
}

void RouteSimulator::startSimulation() {
    if (m_route.size() > 1) {
        m_timer->start(TICK_RATE_MS);
    }
}

void RouteSimulator::stopSimulation() {
    m_timer->stop();
}

void RouteSimulator::updateTick() {
    if (m_currentIndex >= m_route.size() - 1) {
        stopSimulation();
        qDebug() << "Destination reached!";
        return;
    }

    // 1. Tính quãng đường cần di chuyển trong 1 tick (met)
    // Tốc độ (m/s) = speedKmh / 3.6
    double speedMs = m_speedKmh / 3.6;
    double distanceToMove = speedMs * (TICK_RATE_MS / 1000.0);

    QGeoCoordinate targetPoint = m_route[m_currentIndex + 1];

    // Sử dụng Haversine có sẵn của Qt để tính khoảng cách đến điểm tiếp theo
    double distanceToTarget = m_currentPosition.distanceTo(targetPoint);

    // Cập nhật góc quay (Heading) để xe hướng về điểm tiếp theo
    double newHeading = m_currentPosition.azimuthTo(targetPoint);
    if (m_heading != newHeading) {
        m_heading = newHeading;
        emit headingChanged();
    }

    // 2. Nội suy vị trí
    if (distanceToMove >= distanceToTarget) {
        // Nếu quãng đường đi được lớn hơn khoảng cách tới điểm tiếp theo -> Nhảy thẳng tới điểm đó
        m_currentPosition = targetPoint;
        m_currentIndex++;
    } else {
        // Nội suy tuyến tính (Linear Interpolation)
        double ratio = distanceToMove / distanceToTarget;
        double interpLat = m_currentPosition.latitude() + (targetPoint.latitude() - m_currentPosition.latitude()) * ratio;
        double interpLon = m_currentPosition.longitude() + (targetPoint.longitude() - m_currentPosition.longitude()) * ratio;

        m_currentPosition = QGeoCoordinate(interpLat, interpLon);
    }

    // Báo cho QML biết tọa độ đã thay đổi để vẽ lại
    emit positionChanged();
}
