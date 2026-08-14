#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QThread>

// Khởi tạo QtWebEngine dành cho bản đồ Google Maps
#include <QtWebEngine/QtWebEngine>

#include "canworker.h"
#include "spotifyworker.h"
#include "clustermanager.h"
#include "route_simulator.h" // <--- Thêm thư viện này


int main(int argc, char *argv[])
{
    // QUAN TRỌNG: QtWebEngine::initialize() phải gọi TRƯỚC khi tạo QGuiApplication
    QtWebEngine::initialize();

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    // Đăng ký class RouteSimulator cho QML với tên "ClusterApp" phiên bản 1.0
    qmlRegisterType<RouteSimulator>("ClusterApp", 1, 0, "RouteSimulator");

    QQmlApplicationEngine engine;
    // Tạo đối tượng trung tâm quản lý giao diện
    ClusterManager *manager = new ClusterManager(&app);

    // ─── LUỒNG XỬ LÝ CAN BUS ─────────────────────────────────
    QThread *canThread = new QThread(&app);
    CanWorker *canWorker = new CanWorker();
    canWorker->moveToThread(canThread);

    // Kết nối nhận dữ liệu Tốc độ & Pin
    QObject::connect(canWorker,  &CanWorker::canDataReceived,
                     manager,    &ClusterManager::handleCanData);

    // Kết nối nhận dữ liệu 5 Đèn cảnh báo (Thay thế cho phần báo cháy cũ)
    QObject::connect(canWorker,  &CanWorker::warningDataReceived,
                     manager,    &ClusterManager::handleWarningData);

    // Quản lý vòng đời luồng CAN
    QObject::connect(canThread,  &QThread::started,
                     canWorker,  &CanWorker::start);
    QObject::connect(canThread,  &QThread::finished,
                     canWorker,  &QObject::deleteLater);


    // ─── LUỒNG XỬ LÝ SPOTIFY ─────────────────────────────────
    QThread *spotifyThread = new QThread(&app);
    SpotifyWorker *spotifyWorker = new SpotifyWorker();
    spotifyWorker->moveToThread(spotifyThread);

    // Đồng bộ dữ liệu Nhạc từ Worker lên Manager để cập nhật giao diện
    QObject::connect(spotifyWorker, &SpotifyWorker::spotifyChanged,
                     manager,       &ClusterManager::handleSpotifyData);
    QObject::connect(spotifyWorker, &SpotifyWorker::loginSuccess,
                     manager,       &ClusterManager::handleLoginSuccess);
    QObject::connect(spotifyWorker, &SpotifyWorker::playbackStateChanged,
                     manager,       &ClusterManager::handlePlaybackState);

    // Truyền lệnh điều khiển Nhạc ngược từ QML -> Manager -> Worker (Thread-safe)
    QObject::connect(manager,       &ClusterManager::requestPauseResume,
                     spotifyWorker, &SpotifyWorker::pauseResume);
    QObject::connect(manager,       &ClusterManager::requestNextTrack,
                     spotifyWorker, &SpotifyWorker::nextTrack);
    QObject::connect(manager,       &ClusterManager::requestPreviousTrack,
                     spotifyWorker, &SpotifyWorker::previousTrack);

    // Quản lý vòng đời luồng Spotify
    QObject::connect(spotifyThread, &QThread::started,
                     spotifyWorker, &SpotifyWorker::start);
    QObject::connect(spotifyThread, &QThread::finished,
                     spotifyWorker, &QObject::deleteLater);

    QObject::connect(manager,    &ClusterManager::requestSendWarningCommand,
                     canWorker,  &CanWorker::sendWarningCommand);

    // ─── ĐẨY DỮ LIỆU SANG GIAO DIỆN QML ───────────────────────
    // Đăng ký tên biến "clusterManager" để sử dụng trực tiếp trong toàn bộ file QML
    engine.rootContext()->setContextProperty("clusterManager", manager);

    // Kích hoạt chạy các luồng ngầm
    canThread->start();
    spotifyThread->start();

    // Nạp giao diện hiển thị Lamborghini Revuelto
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
                         if (!obj && url == objUrl)
                             QCoreApplication::exit(-1);
                     }, Qt::QueuedConnection);
    engine.load(url);

    int result = app.exec();

    // ─── DỌN DẸP AN TOÀN KHI TẮT ỨNG DỤNG ────────────────────
    canThread->quit();
    canThread->wait();

    spotifyThread->quit();
    spotifyThread->wait();

    return result;
}
