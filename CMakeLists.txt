cmake_minimum_required(VERSION 3.23)
project(RAMSimulator)

set(CMAKE_CXX_STANDARD 17)

add_executable(RAMSimulator main.cpp simRAM.cpp simRAM.h listSimRAM.cpp listSimRAM.h Polynomial.cpp Polynomial.h)
