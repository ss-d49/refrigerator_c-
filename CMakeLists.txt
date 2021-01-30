cmake_minimum_required(VERSION 3.17)
project(untitled)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -Os -s -fno-math-errno -fno-exceptions -fno-stack-protector -fno-unwind-tables -fno-asynchronous-unwind-tables -fno-unroll-loops -fmerge-all-constants -fno-ident -mfpmath=387 -ffunction-sections -fdata-sections")

add_executable(untitled main.cpp ObjectIO.cpp foodItem.cpp fridgeInventory.cpp main.h)
