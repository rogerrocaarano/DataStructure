cmake_minimum_required(VERSION 3.23)
project(DataStructure)

set(CMAKE_CXX_STANDARD 17)

add_executable(DataStructure main.cpp simRAM.cpp simRAM.h list/listSimRAM.cpp list/listSimRAM.h polynomial/polynomialList.cpp polynomial/polynomialList.h list/listVector.cpp list/listVector.h list/listPtr.cpp list/listPtr.h polynomial/polynomialVector.cpp polynomial/polynomialVector.h polynomial/polynomialVectorDouble.cpp polynomial/polynomialVectorDouble.h polynomial/polynomialSimRAM.cpp polynomial/polynomialSimRAM.h)

set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} "-static")
