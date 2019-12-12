cmake_minimum_required(VERSION 3.15)
project(.)

set(CMAKE_CXX_STANDARD 14)

set(Tutorial_VERSION_MAJOR 1)
set(Tutorial_VERSION_MINOR 0)

message(STATUS "..")
message(STATUS "${PROJECT_BINARY_DIR}")

configure_file(
        "TutorialConfig.h.in"
        "${PROJECT_BINARY_DIR}/TutorialConfig.h")

include_directories("${PROJECT_BINARY_DIR}")

add_executable(. main.cpp MathFunctions/mysqrt.cpp)