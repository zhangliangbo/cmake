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


option(USE_MYMATH "Use tutorial provided math implementation" ON)

if (USE_MYMATH)
    include_directories("${PROJECT_SOURCE_DIR}/MathFunctions")
    add_subdirectory(MathFunctions)
    set(EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif ()

add_executable(Tutorial main.cpp)
target_link_libraries(Tutorial ${EXTRA_LIBS})

install(TARGETS Tutorial DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h" DESTINATION include)