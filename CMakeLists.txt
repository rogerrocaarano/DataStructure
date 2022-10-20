cmake_minimum_required(VERSION 3.23)
project(DataStructure)

set(CMAKE_CXX_STANDARD 17)

add_executable(DataStructure main.cpp simRAM.cpp simRAM.h listSimRAM.cpp listSimRAM.h PolynomialList.cpp PolynomialList.h listVector.cpp listVector.h listPtr.cpp listPtr.h polynomialVector.cpp polynomialVector.h)

set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} "-static")
