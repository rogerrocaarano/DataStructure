cmake_minimum_required(VERSION 3.23)
project(inf220)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        dev
        main.cpp
        lib/SMemoria.cpp
        lib/SMemoria.h
        lib/polinomioListaSMemoria.cpp
        lib/polinomioListaSMemoria.h
        lib/listaVector.cpp
        lib/listaVector.h
        lib/listaPtr.cpp
        lib/listaPtr.h
        lib/listaSMemoria.cpp
        lib/listaSMemoria.h
        lib/polinomioVector.cpp
        lib/polinomioVector.h
        lib/polinomioVectorDouble.cpp
        lib/polinomioVectorDouble.h
        lib/polinomioPtr.cpp
        lib/polinomioPtr.h
)

add_executable(
        parcial1op2
        parcial1op2/main.cpp
        parcial1op2/SMemoria.cpp
        parcial1op2/MEMRRA.h
        parcial1op2/LISTARRA.cpp
        parcial1op2/LISTARRA.h
        parcial1op2/POLINOMIORRA.cpp
        parcial1op2/POLINOMIORRA.h
)

set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} "-static")