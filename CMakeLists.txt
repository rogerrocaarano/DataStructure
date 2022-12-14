cmake_minimum_required(VERSION 3.23)
project(inf220)

set(CMAKE_CXX_STANDARD 17)
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
# Ejecutables pruebas
add_executable(
        ConjuntoVector
        tests/t_ConjuntoListaVector.cpp
        lib/conjuntoListaVector.h
        lib/conjuntoListaVector.cpp
        lib/listaVector.h
        lib/listaVector.cpp
)
add_executable(
        ConjuntoPtr
        tests/t_ConjuntoPtr.cpp
        lib/conjuntoPtr.h
        lib/conjuntoPtr.cpp
)
set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS})