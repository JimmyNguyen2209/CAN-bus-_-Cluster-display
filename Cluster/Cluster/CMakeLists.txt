cmake_minimum_required(VERSION 3.16)
project(Cluster VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ── Thêm Location và Positioning vào find_package chung ──
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Quick Network Location Positioning)

if(QT_VERSION_MAJOR EQUAL 6)
    find_package(Qt6 REQUIRED COMPONENTS Core Quick Network WebEngineQuick WebEngineWidgets Location Positioning)
else()
    find_package(Qt5 REQUIRED COMPONENTS Core Quick Network WebEngine WebEngineWidgets Location Positioning)
endif()

set(PROJECT_SOURCES
        main.cpp
        qml.qrc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Cluster
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(Cluster SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(Cluster
          ${PROJECT_SOURCES}
          canworker.h canworker.cpp
          spotifyworker.h spotifyworker.cpp
          clustermanager.h
          route_simulator.h
          route_simulator.cpp
          test_camera.py # Đảm bảo có cả file cpp của manager nếu có
        )
    endif()
endif()

if(QT_VERSION_MAJOR EQUAL 6)
    target_link_libraries(Cluster
      PRIVATE
        Qt6::Core
        Qt6::Quick
        Qt6::Network
        Qt6::WebEngineQuick
        Qt6::WebEngineWidgets
        Qt6::Location       # ── Thêm liên kết thư viện cho Qt6
        Qt6::Positioning    # ── Thêm liên kết thư viện cho Qt6
    )
else()
    target_link_libraries(Cluster
      PRIVATE
        Qt5::Core
        Qt5::Quick
        Qt5::Network
        Qt5::WebEngine
        Qt5::WebEngineWidgets
        Qt5::Location       # ── Thêm liên kết thư viện cho Qt5
        Qt5::Positioning    # ── Thêm liên kết thư viện cho Qt5
    )
endif()

if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Cluster)
endif()

set_target_properties(Cluster PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Cluster
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_import_qml_plugins(Cluster)
    qt_finalize_executable(Cluster)
endif()
