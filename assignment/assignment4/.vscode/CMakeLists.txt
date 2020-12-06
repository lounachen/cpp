set(CMAKE_C_FLAGS "-g -Wall  -I C:\\mingw-w64\\x86_64-8.1.0-posix-seh-rt_v6-rev0\\mingw64\\include -L C:\\mingw-w64\\x86_64-8.1.0-posix-seh-rt_v6-rev0\\mingw64\\lib")#  
  
set(CMAKE_CXX_COMPILER "g++")#设置C++编译器  
set(CMAKE_CXX_FLAGS "-g -Wall  -I C:\\mingw-w64\\x86_64-8.1.0-posix-seh-rt_v6-rev0\\mingw64\\include -L C:\\mingw-w64\\x86_64-8.1.0-posix-seh-rt_v6-rev0\\mingw64\\lib")  
  
PROJECT (MATRIX CXX)  
SET(SRC_LIST matrix.hpp matrix.cpp)  
ADD_EXECUTABLE(MATRIX ${SRC_LIST})  
  
MESSAGE(STATUS "This is BINARY dir " ${HELLO_BINARY_DIR})  
MESSAGE(STATUS "This is SOURCE dir " ${HELLO_SOURCE_DIR}) 