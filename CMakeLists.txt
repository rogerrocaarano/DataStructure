cmake_minimum_required(VERSION 3.23)
project(DataStructure)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        DataStructure
        main.cpp
        MEMORIARRA.cpp
        MEMORIARRA.h
        LISTARRA.cpp
        LISTARRA.h
        polinomio/polynomialList.cpp
        polinomio/polynomialList.h
        lista/listVector.cpp
        lista/listVector.h
        lista/listPtr.cpp
        lista/listPtr.h
        polinomio/polynomialVector.cpp
        polinomio/polynomialVector.h
        polinomio/polynomialVectorDouble.cpp
        polinomio/polynomialVectorDouble.h
        POLINOMIORRA.cpp
        POLINOMIORRA.h
        polinomio/polynomialPtr.cpp
        polinomio/polynomialPtr.h
)

set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} "-static")