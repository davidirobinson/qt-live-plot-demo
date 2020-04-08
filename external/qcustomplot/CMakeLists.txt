cmake_minimum_required(VERSION 3.5)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_library(qcustomplot SHARED
    qcustomplot.cc
    qcustomplot.h
)

target_link_libraries(qcustomplot PRIVATE Qt5::Widgets)
