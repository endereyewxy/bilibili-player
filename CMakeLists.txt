cmake_minimum_required(VERSION 3.17)
project(bilibili-player)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Network REQUIRED)
find_package(Qt5Multimedia REQUIRED)
find_package(Qt5MultimediaWidgets REQUIRED)

aux_source_directory(src/entity SRCS_ENTITY)
aux_source_directory(src/gui SRCS_GUI)
aux_source_directory(src/util SRCS_UTIL)

add_executable(bilibili-player src/main.cpp ${SRCS_ENTITY} ${SRCS_GUI} ${SRCS_UTIL} src/resource.qrc)
target_link_libraries(bilibili-player Qt5::Widgets Qt5::Network Qt5::Multimedia Qt5::MultimediaWidgets)