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
set(CMAKE_INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/Headers)
set(CMAKE_INCLUDE_PATH /usr/local/lib)
#set(OpenCV_DIR $ "C:/opencv/build/x64/vc15")

find_package(OpenCV REQUIRED)

set(PROJECT_SOURCE_DIR src)
SET(PROJECT_BINARY_DIR Headers)

include_directories(${CMAKE_CURRENT_BINARY_DIR} ${OpenCV_INCLUDE_DIRS} ${Protobuf_INCLUDE_DIRS})

set(SOURCE_FILES ${PROJECT_SOURCE_DIR}/JetsonVision.cpp ${PROJECT_SOURCE_DIR}/CalibrateCamera.cpp ${PROJECT_SOURCE_DIR}/CornerDetection.cpp ${PROJECT_SOURCE_DIR}/PoseEstimation.cpp src/BoardDetection.cpp Headers/BoardDetection.hpp)
set(HEADER_FILES ${PROJECT_HEADER_DIR}/PoseEstimation.hpp ${PROJECT_HEADER_DIR}/JetsonVision.hpp ${PROJECT_HEADER_DIR}/CornerDetection.hpp ${PROJECT_HEADER_DIR}/CalibrateCamera.hpp)

add_executable(Jetson_Vision ${SOURCE_FILES})

target_link_libraries(Jetson_Vision ${OpenCV_LIBS})