add_library(MathFunctions mysqrt.cpp)

set(CMAKE_INSTALL_PREFIX "D:/clib")
install(TARGETS MathFunctions DESTINATION bin)
install(FILES MathFunctions.h DESTINATION include)