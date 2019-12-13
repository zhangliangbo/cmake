cmake_minimum_required(VERSION 3.15)
project(Tutorial)

set(CMAKE_CXX_STANDARD 14)

set(Tutorial_VERSION_MAJOR 1)
set(Tutorial_VERSION_MINOR 0)

message(STATUS "..")
message(STATUS "${PROJECT_BINARY_DIR}")

#配置
configure_file(
        "TutorialConfig.h.in"
        "${PROJECT_BINARY_DIR}/TutorialConfig.h")

#依赖
include_directories("${PROJECT_BINARY_DIR}")

option(USE_MYMATH "Use tutorial provided math implementation" ON)
#条件依赖
if (USE_MYMATH)
    include_directories("${PROJECT_SOURCE_DIR}/MathFunctions")
    add_subdirectory(MathFunctions)
    set(EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif ()

#构建
add_executable(Tutorial main.cpp)
target_link_libraries(Tutorial ${EXTRA_LIBS})
#测试
include(CTest)
#定义测试宏(宏和函数的区别？)
macro(do_test arg res)
    add_test(TutorialComp${arg} Tutorial ${arg})
    set_tests_properties(TutorialComp${arg} PROPERTIES PASS_REGULAR_EXPRESSION ${res})
endmacro()
#使用测试宏
do_test(25 "25 is 5")
do_test(-25 "-25 is 0")
#安装
set(CMAKE_INSTALL_PREFIX "D:/clib")
install(TARGETS Tutorial DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h" DESTINATION include)


