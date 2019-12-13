cmake_minimum_required(VERSION 3.15)
project(Tutorial)

set(CMAKE_CXX_STANDARD 14)

#版本号
set(Tutorial_VERSION_MAJOR 1)
set(Tutorial_VERSION_MINOR 0)

#系统自检
include(CheckFunctionExists)
check_function_exists(log HAVE_LOG)
check_function_exists(exp HAVE_EXP)

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
#安装
set(CMAKE_INSTALL_PREFIX "D:/clib")
install(TARGETS Tutorial DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h" DESTINATION include)
#测试
include(CTest)
set (CTEST_PROJECT_NAME "Tutorial")
#定义测试宏(宏和函数的区别？)
macro(do_test arg res)
    add_test(TutorialComp${arg} Tutorial ${arg})
    set_tests_properties(TutorialComp${arg} PROPERTIES PASS_REGULAR_EXPRESSION ${res})
endmacro()
#使用测试宏
do_test(25 "25 is 5")
do_test(-25 "-25 is 0")
#安装器
# build a CPack driven installer package
include (InstallRequiredSystemLibraries)
include (CPack)
set (CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set (CPACK_PACKAGE_VERSION_MAJOR "${Tutorial_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${Tutorial_VERSION_MINOR}")
