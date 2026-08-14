import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtWebEngine 1.8 // Import module WebEngine để chạy file HTML

Window {
    id: root
    visible: true
    width: 800
    height: 480
    title: "Lamborghini Revuelto Cluster"
    color: "#03040A"

    // ── BIẾN ĐIỀU KHIỂN HỆ THỐNG VÀ HIỆU ỨNG ─────────────────
    property bool isWelcomeActive: true
    property int  welcomeSpeed: 0
    property int  welcomeBattery: 0

    property int  realSpeedVal:    0
    property int  realBatteryVal:  85

    property int  speedVal:    isWelcomeActive ? welcomeSpeed : realSpeedVal
    property int  batteryVal:  isWelcomeActive ? welcomeBattery : realBatteryVal

    property string songTitle:   "Dang doi ket noi..."
    property string songArtist:  "Spotify"
    property string albumArtUrl: ""
    property bool   spIsPlaying: false

    // Chuyển đổi màn hình giữa Bản đồ và Nghe nhạc
    property bool   showMapView: true

    // Trạng thái 5 đèn cảnh báo (Từ ESP32)
    property bool warnTurnLeft:  false
    property bool warnCos:       false
    property bool warnPha:       false
    property bool warnBelt:      false
    property bool warnTurnRight: false

    property string driveMode: {
        if (realSpeedVal > 250) return "CORSA";
        if (realSpeedVal > 150) return "SPORT+";
        if (realSpeedVal > 80)  return "SPORT";
        return "STRADA";
    }

    property color mainThemeColor: {
        if (driveMode === "CORSA") return "#E60000"
        if (driveMode === "SPORT" || driveMode === "SPORT+") return "#FF5500"
        return "#9A7A2A"
    }

    onSpeedValChanged: speedCanvas.requestPaint()

    // ── ANIMATION KHỞI ĐỘNG ──
    Component.onCompleted: welcomeAnimation.start()

    SequentialAnimation {
        id: welcomeAnimation
        running: false
        PauseAnimation { duration: 200 }
        ParallelAnimation {
            NumberAnimation { target: root; property: "welcomeSpeed"; from: 0; to: 320; duration: 1200; easing.type: Easing.OutQuad }
            NumberAnimation { target: root; property: "welcomeBattery"; from: 0; to: 100; duration: 1200; easing.type: Easing.OutQuad }
        }
        PauseAnimation { duration: 150 }
        ParallelAnimation {
            NumberAnimation { target: root; property: "welcomeSpeed"; from: 320; to: 0; duration: 1000; easing.type: Easing.InOutQuad }
            NumberAnimation { target: root; property: "welcomeBattery"; from: 100; to: root.realBatteryVal; duration: 1000; easing.type: Easing.InOutQuad }
        }
        PropertyAction { target: root; property: "isWelcomeActive"; value: false }
    }


    // ── TOP BAR ──────────────────────────────────────────────
    Rectangle {
        id: topBar
        width: parent.width; height: 36
        color: "#020308"
        Rectangle { anchors.bottom: parent.bottom; width: parent.width; height: 1; color: "#0E1520" }

        Text {
            anchors.left: parent.left; anchors.leftMargin: 20
            anchors.verticalCenter: parent.verticalCenter
            text: Qt.formatTime(new Date(), "hh:mm") + "  \u2022  23\u00b0C"
            font.pixelSize: 11; font.letterSpacing: 2; color: "#28313E"
            Timer { interval: 30000; running: true; repeat: true; onTriggered: parent.text = Qt.formatTime(new Date(), "hh:mm") + "  \u2022  23\u00b0C" }
        }
        Text {
            anchors.centerIn: parent
            text: "M R T R U O N G S O N"
            font.pixelSize: 12; font.bold: true; font.letterSpacing: 5; color: root.mainThemeColor
            Behavior on color { ColorAnimation { duration: 400 } }
        }
        Text {
            anchors.right: parent.right; anchors.rightMargin: 20
            anchors.verticalCenter: parent.verticalCenter
            text: "23\u00b0C   HCM"
            font.pixelSize: 11; font.letterSpacing: 2; color: "#28313E"
        }
    }

    // ── MAIN AREA ─────────────────────────────────────────────
    Item {
        id: mainArea
        anchors.top: topBar.bottom
        anchors.bottom: bottomBar.top
        anchors.left: parent.left
        anchors.right: parent.right

        // ── LEFT PANEL: ĐỒNG HỒ TỐC ĐỘ ────────────────────────
        Item {
            id: leftPanel
            width: 230
            anchors.top: parent.top; anchors.bottom: parent.bottom; anchors.left: parent.left
            Rectangle { anchors.right: parent.right; width: 1; anchors.top: parent.top; anchors.bottom: parent.bottom; color: "#0A0E16" }

            Canvas {
                id: speedCanvas
                width: 196; height: 196
                anchors.centerIn: parent; anchors.verticalCenterOffset: -28
                onPaint: {
                    var ctx = getContext("2d"); ctx.reset()
                    var cx = 98, cy = 98, r = 80, startA = Math.PI * 0.72, totalA = Math.PI * 1.56
                    var pct = Math.min(root.speedVal / 320.0, 1.0)
                    ctx.beginPath(); ctx.arc(cx, cy, r, startA, startA + totalA)
                    ctx.strokeStyle = "#080C14"; ctx.lineWidth = 10; ctx.lineCap = "round"; ctx.stroke()
                    if (pct > 0) {
                        ctx.beginPath()
                        var currentAngle = root.isWelcomeActive ? (startA + totalA * (root.speedVal / 320.0)) : (startA + totalA * pct)
                        ctx.arc(cx, cy, r, startA, currentAngle)
                        ctx.strokeStyle = root.speedVal > 250 ? "#C02020" : root.mainThemeColor
                        ctx.lineWidth = 10; ctx.lineCap = "round"; ctx.stroke()
                    }
                    for (var i = 0; i <= 14; i++) {
                        var a = startA + (totalA / 14) * i, big = (i % 7 === 0)
                        ctx.beginPath()
                        ctx.moveTo(cx + Math.cos(a)*(big?r-16:r-10), cy + Math.sin(a)*(big?r-16:r-10))
                        ctx.lineTo(cx + Math.cos(a)*(r-2),           cy + Math.sin(a)*(r-2))
                        ctx.strokeStyle = big ? "#1E2A3A" : "#0D1420"
                        ctx.lineWidth = big ? 1.5 : 0.5; ctx.stroke()
                    }
                }
                Text {
                    anchors.centerIn: parent; anchors.verticalCenterOffset: -10
                    text: root.speedVal
                    font.pixelSize: 60; font.weight: Font.Light; color: "#C8C4BC"
                }
                Text {
                    anchors.centerIn: parent; anchors.verticalCenterOffset: 36
                    text: "KM / H"
                    font.pixelSize: 10; font.bold: true; font.letterSpacing: 4; color: root.mainThemeColor
                    Behavior on color { ColorAnimation { duration: 400 } }
                }
            }

            Rectangle {
                width: 44; height: 44
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: parent.bottom; anchors.bottomMargin: 28
                color: "transparent"; border.color: root.mainThemeColor; border.width: 1; radius: 3
                Behavior on border.color { ColorAnimation { duration: 400 } }
                Text {
                    anchors.centerIn: parent
                    text: root.speedVal === 0 ? "N" : root.speedVal < 50 ? "1" : root.speedVal < 100 ? "2" : root.speedVal < 150 ? "3" : root.speedVal < 200 ? "4" : root.speedVal < 270 ? "5" : root.speedVal < 320 ? "6" : "7"
                    font.pixelSize: 22; font.weight: Font.Light; color: root.mainThemeColor
                    Behavior on color { ColorAnimation { duration: 400 } }
                }
            }
        }

        // ── CENTER PANEL: INFOTAINMENT (MAP + MEDIA) ──────────────
        Item {
            id: centerPanel
            anchors.left: leftPanel.right
            anchors.right: rightPanel.left
            anchors.top: parent.top; anchors.bottom: parent.bottom

            // Biến quản lý trạng thái Tab: 0 = Bản đồ, 1 = Nhạc Spotify
            property int activeTab: 0

            // ═════════════════════════════════════════════════
            // THANH TIÊU ĐỀ: CHIA ĐÔI THÀNH 2 TAB NHẤN
            // ═════════════════════════════════════════════════
            Rectangle {
                id: centerHeader
                width: parent.width; height: 32 // Tăng nhẹ độ cao để làm nút bấm cho đẹp
                color: "#010206"
                Rectangle { anchors.bottom: parent.bottom; width: parent.width; height: 1; color: "#0A0E16" }

                Row {
                    id: tabRow
                    width: parent.width; height: parent.height

                    // NỬA TRÁI: NÚT BẤM MAP
                    Rectangle {
                        width: parent.width / 2; height: parent.height
                        color: "transparent"
                        Text {
                            anchors.centerIn: parent
                            text: "\ud83d\uddfa  NAVIGATION"
                            font.pixelSize: 9; font.letterSpacing: 1.5; font.bold: true
                            // Chữ sáng lên màu chủ đề khi được chọn, ngược lại mờ đi
                            color: centerPanel.activeTab === 0 ? root.mainThemeColor : "#3A4858"
                            Behavior on color { ColorAnimation { duration: 200 } }
                        }
                        MouseArea {
                            anchors.fill: parent
                            onClicked: centerPanel.activeTab = 0 // Chuyển sang Tab Map
                        }
                    }

                    // NỬA PHẢI: NÚT BẤM MEDIA
                    Rectangle {
                        width: parent.width / 2; height: parent.height
                        color: "transparent"
                        Text {
                            anchors.centerIn: parent
                            text: "\u266b  SPOTIFY"
                            font.pixelSize: 9; font.letterSpacing: 1.5; font.bold: true
                            color: centerPanel.activeTab === 1 ? root.mainThemeColor : "#3A4858"
                            Behavior on color { ColorAnimation { duration: 200 } }
                        }
                        MouseArea {
                            anchors.fill: parent
                            onClicked: centerPanel.activeTab = 1 // Chuyển sang Tab Nhạc
                        }
                    }
                }

                // THANH TRƯỢT DƯỚI CHÂN CÁC TAB (Hiệu ứng di chuyển gạch chân)
                Rectangle {
                    id: tabIndicator
                    width: parent.width / 2; height: 2
                    anchors.bottom: parent.bottom
                    color: root.mainThemeColor
                    // Tự động tính toán vị trí X: Tab 0 thì X=0, Tab 1 thì X nhảy sang một nửa màn hình
                    x: centerPanel.activeTab * (parent.width / 2)

                    // Hiệu ứng trượt ngang mượt mà cho thanh gạch chân
                    Behavior on x { NumberAnimation { duration: 250; easing.type: Easing.OutQuad } }
                    Behavior on color { ColorAnimation { duration: 400 } }
                }
            }

            // ═════════════════════════════════════════════════
            // KHUNG NỘI DUNG TRUNG TÂM (CÓ HIỆU ỨNG CHUYỂN CẢNH)
            // ═════════════════════════════════════════════════
            Item {
                id: contentArea
                width: parent.width
                anchors.top: centerHeader.bottom
                anchors.bottom: warningBar.top

                // ── KHUNG 1: BẢN ĐỒ DẪN ĐƯỜNG ──
                Item {
                    id: mapCard
                    anchors.fill: parent
                    // Hiệu ứng mờ dần (Cross-fade) bằng cách thay đổi Opacity động
                    opacity: centerPanel.activeTab === 0 ? 1.0 : 0.0
                    visible: opacity > 0.0 // Ẩn hoàn toàn khi không kích hoạt để tiết kiệm phần cứng

                    // Kích hoạt hiệu ứng mượt khi opacity thay đổi
                    Behavior on opacity { NumberAnimation { duration: 300; easing.type: Easing.InOutQuad } }

                    WebEngineView {
                        id: mapView
                        anchors.fill: parent
                        url: "qrc:/map.html"
                    }
                }

                // ── KHUNG 2: NGHE NHẠC SPOTIFY ──
                Item {
                    id: mediaCard
                    anchors.fill: parent
                    opacity: centerPanel.activeTab === 1 ? 1.0 : 0.0
                    visible: opacity > 0.0

                    Behavior on opacity { NumberAnimation { duration: 300; easing.type: Easing.InOutQuad } }

                    Rectangle { anchors.bottom: parent.bottom; width: parent.width; height: 1; color: "#0A0E16" }

                    Rectangle {
                        id: albumBox
                        width: 110; height: 110 // Trả lại kích thước lớn sang xịn mịn như cũ
                        anchors.left: parent.left; anchors.leftMargin: 18
                        anchors.verticalCenter: parent.verticalCenter
                        color: "#07090F"; border.color: albumArtImg.visible ? root.mainThemeColor : "#141C28"
                        border.width: albumArtImg.visible ? 2 : 1; radius: 6; clip: true

                        Image { id: albumArtImg; anchors.fill: parent; fillMode: Image.PreserveAspectCrop; source: root.albumArtUrl; visible: root.albumArtUrl !== "" }
                        Column {
                            anchors.centerIn: parent; spacing: 6; visible: !albumArtImg.visible
                            Text { anchors.horizontalCenter: parent.horizontalCenter; text: "\u266b"; font.pixelSize: 36; color: "#2A3A50" }
                            Text { anchors.horizontalCenter: parent.horizontalCenter; text: "SPOTIFY"; font.pixelSize: 9; font.letterSpacing: 2; color: "#1A2030" }
                        }
                        MouseArea { anchors.fill: parent; onClicked: clusterManager.pauseResume() }
                    }

                    Column {
                        anchors.left: albumBox.right; anchors.leftMargin: 16
                        anchors.right: parent.right; anchors.rightMargin: 16
                        anchors.verticalCenter: parent.verticalCenter
                        spacing: 6

                        Text { text: root.songTitle !== "" ? root.songTitle.toUpperCase() : "DANG DOI KET NOI..."; font.pixelSize: 14; font.bold: true; color: "#C8C4BC"; elide: Text.ElideRight; width: parent.width }
                        Text { text: root.songArtist.toUpperCase() + "  \u2022  SPOTIFY"; font.pixelSize: 10; color: "#3A4858"; elide: Text.ElideRight; width: parent.width }

                        Rectangle {
                            width: parent.width; height: 2; color: "#0E1520"; radius: 1
                            Rectangle {
                                id: progressFill; height: parent.height; radius: 1; color: root.mainThemeColor
                                NumberAnimation on width { running: root.spIsPlaying; from: 0; to: progressFill.parent.width; duration: 210000; loops: Animation.Infinite }
                            }
                        }

                        Row {
                            spacing: 12
                            Text {
                                text: "\u23ee"; font.pixelSize: 16; color: prevArea.containsMouse ? root.mainThemeColor : "#3A4858"; anchors.verticalCenter: parent.verticalCenter
                                MouseArea { id: prevArea; anchors.fill: parent; hoverEnabled: true; onClicked: clusterManager.previousTrack() }
                            }
                            Rectangle {
                                width: 30; height: 30; color: "transparent"; border.color: root.mainThemeColor; border.width: 1; radius: 15
                                Text { anchors.centerIn: parent; text: root.spIsPlaying ? "\u23f8" : "\u25b6"; font.pixelSize: 11; color: root.mainThemeColor }
                                MouseArea { anchors.fill: parent; onClicked: clusterManager.pauseResume() }
                            }
                            Text {
                                text: "\u23ed"; font.pixelSize: 16; color: nextArea.containsMouse ? root.mainThemeColor : "#3A4858"; anchors.verticalCenter: parent.verticalCenter
                                MouseArea { id: nextArea; anchors.fill: parent; hoverEnabled: true; onClicked: clusterManager.nextTrack() }
                            }
                        }
                    }
                }
            }

            // ── WARNING BAR DƯỚI ĐÁY (Giữ nguyên) ──
            Rectangle {
                id: warningBar
                width: parent.width; height: 52
                anchors.bottom: parent.bottom; color: "#020308"
                Rectangle { anchors.top: parent.top; width: parent.width; height: 1; color: "#0A0E16" }

                Row {
                    anchors.centerIn: parent; spacing: 0
                    Repeater {
                        model: [
                            { lbl: "\u25c4",     tip: "XI NHAN T",   col: root.mainThemeColor, prop: "warnTurnLeft"  },
                            { lbl: "\ud83d\udca1", tip: "DEN COS",     col: "#1DB954",           prop: "warnCos"       },
                            { lbl: "\ud83d\udca1", tip: "DEN PHA",     col: "#2060B0",           prop: "warnPha"       },
                            { lbl: "\ud83d\udede", tip: "DAY AN TOAN", col: "#C02020",           prop: "warnBelt"      },
                            { lbl: "\u25ba",     tip: "XI NHAN P",   col: root.mainThemeColor, prop: "warnTurnRight" }
                        ]
                        delegate: Rectangle {
                            width: warningBar.width / 5; height: warningBar.height
                            color: isActive ? Qt.darker(modelData.col, 6) : "transparent"
                            border.color: "#0A0E16"; border.width: 1
                            property bool isActive: root[modelData.prop]

                            SequentialAnimation on opacity {
                                running: isActive && (modelData.prop === "warnTurnLeft" || modelData.prop === "warnTurnRight") || (root.driveMode === "CORSA" && isActive)
                                loops: Animation.Infinite
                                NumberAnimation { to: 0.15; duration: (root.driveMode === "CORSA") ? 200 : 450 }
                                NumberAnimation { to: 1.0;  duration: (root.driveMode === "CORSA") ? 200 : 450 }
                            }

                            Column {
                                anchors.centerIn: parent; spacing: 2
                                Text { anchors.horizontalCenter: parent.horizontalCenter; text: modelData.lbl; font.pixelSize: 16; color: isActive ? modelData.col : "#1A2030"; opacity: isActive ? 1.0 : 0.4 }
                                Text { anchors.horizontalCenter: parent.horizontalCenter; text: modelData.tip; font.pixelSize: 7; font.letterSpacing: 0.8; color: isActive ? modelData.col : "#1A2030"; opacity: isActive ? 0.85 : 0.3 }
                            }

                            MouseArea {
                                anchors.fill: parent
                                onClicked: {
                                    if (modelData.prop === "warnPha" && !root.warnCos) return;
                                    root[modelData.prop] = !root[modelData.prop]
                                    if (modelData.prop === "warnCos" && !root.warnCos) root.warnPha = false;
                                    if (modelData.prop === "warnTurnLeft" && root.warnTurnLeft) root.warnTurnRight = false;
                                    if (modelData.prop === "warnTurnRight" && root.warnTurnRight) root.warnTurnLeft = false;
                                    clusterManager.toggleWarningFromUI(root.warnTurnLeft, root.warnTurnRight, root.warnCos, root.warnPha, root.warnBelt)
                                }
                            }
                        }
                    }
                }
            }
        }
        // ── RIGHT PANEL: BATTERY ───────────────────────────────
        Item {
            id: rightPanel
            width: 190
            anchors.top: parent.top; anchors.bottom: parent.bottom; anchors.right: parent.right
            Rectangle { anchors.left: parent.left; width: 1; anchors.top: parent.top; anchors.bottom: parent.bottom; color: "#0A0E16" }

            Column {
                anchors.centerIn: parent; spacing: 14
                Item {
                    width: 56; height: 116; anchors.horizontalCenter: parent.horizontalCenter
                    Rectangle { width: 20; height: 7; anchors.top: parent.top; anchors.horizontalCenter: parent.horizontalCenter; color: "#2A3040"; radius: 2 }
                    Rectangle {
                        width: 56; height: 106; anchors.bottom: parent.bottom; color: "transparent"; border.color: "#2A3040"; border.width: 2; radius: 5
                        Rectangle {
                            width: parent.width - 10; anchors.horizontalCenter: parent.horizontalCenter; anchors.bottom: parent.bottom; anchors.bottomMargin: 5; radius: 3
                            height: (parent.height - 10) * (root.batteryVal / 100.0)
                            color: root.isWelcomeActive ? root.mainThemeColor : (root.batteryVal <= 20 ? "#C02020" : root.batteryVal <= 50 ? "#9A7A2A" : "#1DB954")
                            Behavior on height { NumberAnimation { duration: 350; easing.type: Easing.OutCubic } }
                        }
                    }
                }
                Text { anchors.horizontalCenter: parent.horizontalCenter; text: root.batteryVal + "%"; font.pixelSize: 26; font.weight: Font.Light; color: "#C8C4BC" }
                Text { anchors.horizontalCenter: parent.horizontalCenter; text: "BATTERY"; font.pixelSize: 9; font.letterSpacing: 2; color: "#28313E" }
                Text {
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: "~" + Math.round(root.batteryVal * 3.95) + " KM"
                    font.pixelSize: 14; font.bold: true; font.letterSpacing: 1
                    color: root.isWelcomeActive ? root.mainThemeColor : (root.batteryVal <= 20 ? "#C02020" : root.batteryVal <= 50 ? "#9A7A2A" : "#1DB954")
                }
                Text { anchors.horizontalCenter: parent.horizontalCenter; text: "ESTIMATED RANGE"; font.pixelSize: 9; font.letterSpacing: 2; color: "#28313E" }
            }
        }
    }

    // ── BOTTOM BAR ────────────────────────────────────────────
    Rectangle {
        id: bottomBar
        width: parent.width; height: 34
        anchors.bottom: parent.bottom; color: "#020308"
        Rectangle { anchors.top: parent.top; width: parent.width; height: 1; color: "#0E1520" }

        Text { anchors.left: parent.left; anchors.leftMargin: 20; anchors.verticalCenter: parent.verticalCenter; text: "ODO  12,847 KM"; font.pixelSize: 9; font.letterSpacing: 2; color: "#1A2030" }
        Text {
            anchors.centerIn: parent; text: "READY  \u2022  " + root.driveMode
            font.pixelSize: 10; font.bold: true; font.letterSpacing: 3; color: root.mainThemeColor
            Behavior on color { ColorAnimation { duration: 400 } }
        }
        Text { anchors.right: parent.right; anchors.rightMargin: 20; anchors.verticalCenter: parent.verticalCenter; text: "LDVI  ACTIVE"; font.pixelSize: 9; font.letterSpacing: 2; color: "#1A2030" }
    }

    // ── KẾT NỐI DATA C++ VÀ ĐẨY XUỐNG BẢN ĐỒ ─────────────────
    Connections {
        target: clusterManager

        function onCanDataReceived(speed, battery) {
            root.realSpeedVal   = speed
            root.realBatteryVal = battery

            // ĐẨY TỐC ĐỘ VÀO BẢN ĐỒ (Nếu đang mở bản đồ thì ép xe chạy)
            if (root.showMapView) {
                mapView.runJavaScript("updateCarSpeed(" + speed + ");")
            }
        }

        function onWarningDataReceived(left, right, cos, pha, belt) {
            root.warnTurnLeft  = left
            root.warnTurnRight = right
            root.warnCos       = cos
            root.warnPha       = pha
            root.warnBelt      = belt
        }

        function onSpotifyChanged(title, artist, albumArt) {
            root.songTitle   = title
            root.songArtist  = artist
            root.albumArtUrl = albumArt
        }

        function onIsPlayingChanged() {
            root.spIsPlaying = clusterManager.isPlaying
        }
    }
}
