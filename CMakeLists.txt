cmake_minimum_required(VERSION 2.8)
project(Jetson-Vision)

if (CMAKE_VERSION VERSION_LESS "3.1")
    if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        set (CMAKE_CXX_FLAGS "-std=gnu++11 ${CMAKE_CXX_FLAGS}")
    endif ()
else ()
    set (CMAKE_CXX_STANDARD 11)
endif ()

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/Modules)
#set(OpenCV_DIR $ "C:/opencv/build/x64/vc15")

find_package(OpenCV REQUIRED)

set(PROJECT_SOURCE_DIR src)

set(PROJECT_BINARY_DIR include)

include_directories(${CMAKE_CURRENT_BINARY_DIR} ${OpenCV_INCLUDE_DIRS} ${Protobuf_INCLUDE_DIRS})

set(SOURCE_FILES ${PROJECT_SOURCE_DIR}/)
#set(SOURCE_FILES src/camera_calibration.cpp)
#set(SOURCE_FILES src/cpu_main.cpp)

add_executable(Jetson_Vision ${SOURCE_FILES}/JetsonVision.cpp src/JetsonVision.cpp src/JetsonVision.hpp)

target_link_libraries(Jetson_Vision ${OpenCV_LIBS})