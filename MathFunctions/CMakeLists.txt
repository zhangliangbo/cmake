#first we add the executable that generates the table
add_executable(MakeTable MakeTable.cpp)
#add the command to generate the source code
add_custom_command(
        OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Table.h
        DEPENDS MakeTable
        COMMAND MakeTable ${CMAKE_CURRENT_BINARY_DIR}/Table.h
)
#add the binary tree directory to the search path for include files
include_directories(${CMAKE_CURRENT_BINARY_DIR})
#add the main library
add_library(MathFunctions MathFunctions.h mysqrt.cpp ${CMAKE_CURRENT_BINARY_DIR}/Table.h)
#安装
set(CMAKE_INSTALL_PREFIX "D:/clib")
install(TARGETS MathFunctions DESTINATION bin)
install(FILES MathFunctions.h ${CMAKE_CURRENT_BINARY_DIR}/Table.h DESTINATION include)