cmake_minimum_required(VERSION 3.23)
project(inf220)

set(CMAKE_CXX_STANDARD 17)
# Ejecutable de desarrollo
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
# Ejecutables de entregas realizadas
add_executable(
        act2_SMemoria
        entregas/act2_SMemoria/Proyrra.cpp
        entregas/act2_SMemoria/rraCSMemoria.cpp
        entregas/act2_SMemoria/rraCSMemoria.h
)
add_executable(
        act3_Listas
        entregas/act3_Listas/rra.cpp
        entregas/act3_Listas/ListaRRA.cpp
        entregas/act3_Listas/ListaRRA.h
        entregas/act3_Listas/rraCSMemoria.cpp
        entregas/act3_Listas/rraCSMemoria.h
)
add_executable(
        parcial1op2
        entregas/parcial1op2/main.cpp
        entregas/parcial1op2/SMemoria.cpp
        entregas/parcial1op2/MEMRRA.h
        entregas/parcial1op2/LISTARRA.cpp
        entregas/parcial1op2/LISTARRA.h
        entregas/parcial1op2/POLINOMIORRA.cpp
        entregas/parcial1op2/POLINOMIORRA.h
)

set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS})