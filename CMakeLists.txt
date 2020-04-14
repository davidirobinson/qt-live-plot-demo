cmake_minimum_required(VERSION 3.5)

project(qt-live-plot-demo LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets Core Gui PrintSupport REQUIRED)
set(qtlibs Qt5::Widgets Qt5::Core Qt5::Gui Qt5::PrintSupport)

add_executable(qt-live-plot-demo
    main.cc
    mainwindow.cc
    mainwindow.h
    mainwindow.ui
    qcustomplot.cc
    qcustomplot.h
)

target_link_libraries(qt-live-plot-demo PRIVATE ${qtlibs} pthread)
