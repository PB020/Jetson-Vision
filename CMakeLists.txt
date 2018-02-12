cmake_minimum_required(VERSION 2.8)
project(Jetson-Vision)

if (CMAKE_VERSION VERSION_LESS "3.1")
    if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        set (CMAKE_CXX_FLAGS "-std=gnu++11 ${CMAKE_CXX_FLAGS}")
    endif ()
else ()
    set (CMAKE_CXX_STANDARD 11)
endif ()

find_package(OpenCV REQUIRED)

set(PROJECT_SOURCE_DIR src)
SET(PROJECT_BINARY_DIR Headers)

include_directories(${CMAKE_CURRENT_BINARY_DIR} ${OpenCV_INCLUDE_DIRS} ${Protobuf_INCLUDE_DIRS})

set(SOURCE_FILES ${PROJECT_SOURCE_DIR}/BoardDetection.cpp ${PROJECT_SOURCE_DIR}/BoardCreation.cpp)
set(HEADER_FILES ${PROJECT_HEADER_DIR}/BoardDetection.hpp ${PROJECT_HEADER_DIR}/BoardCreation.hpp)

add_executable(Jetson_Vision ${SOURCE_FILES})

target_link_libraries(Jetson_Vision ${OpenCV_LIBS})