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
add_executable(
        act2022-C1
        entregas/act2022-C1/main.cpp
        entregas/act2022-C1/conjuntoPtr.h
        entregas/act2022-C1/conjuntoPtr.cpp
)
add_executable(
        act2022-M1
        entregas/act2022-M1/main.cpp
        entregas/act2022-M1/matrizDispersaCSRVector.h
        entregas/act2022-M1/matrizDispersaCSRVector.cpp
)
add_executable(
        act2022-P1
        entregas/act2022-P1/main.cpp
        entregas/act2022-P1/aritmPila.h
        entregas/act2022-P1/aritmPila.cpp
        entregas/act2022-P1/pilaPtr.h
        entregas/act2022-P1/pilaPtr.cpp
)
add_executable(
        act2022-CL1
        entregas/act2022-CL1/main.cpp
        entregas/act2022-CL1/diColaPtr.cpp entregas/act2022-CL1/colaPrioridad.cpp)
# Ejecutables pruebas
add_executable(
        ConjuntoVector
        tests/conjunto/t_ConjuntoListaVector.cpp
        lib/conjunto/conjuntoListaVector.h
        lib/conjunto/conjuntoListaVector.cpp
        lib/lista/listaVector.h
        lib/lista/listaVector.cpp
)
add_executable(
        ConjuntoPtr
        tests/conjunto/t_ConjuntoPtr.cpp
        lib/conjunto/conjuntoPtr.h
        lib/conjunto/conjuntoPtr.cpp
        tests/matrizDispersa/t_matrizDispersaVector.cpp
)
add_executable(
        matrizDispersaVector
        tests/matrizDispersa/t_matrizDispersaVector.cpp
        lib/matrizDispersa/matrizDispersaVector.cpp
        lib/matrizDispersa/matrizDispersaVector.h
)
add_executable(
        matrizDispersaCSRvector
        tests/matrizDispersa/t_matrizDispersaCSRVector.cpp
        lib/matrizDispersa/matrizDispersaCSRVector.cpp lib/matrizDispersa/matrizDispersaCSRVector.h)
add_executable(
        pilaPtr
        tests/pila/t_pilaPtr.cpp
        lib/pila/pilaPtr.cpp lib/pila/pilaPtr.h)
add_executable(
        pilaLista
        tests/pila/t_pilaLista.cpp
        lib/pila/pilaLista.cpp lib/pila/pilaLista.h
        lib/lista/listaPtr.h lib/lista/listaPtr.cpp
)
add_executable(
        pilaVector
        tests/pila/t_pilaVector.cpp
        lib/pila/pilaVector.cpp lib/pila/pilaVector.h)
add_executable(
        pilaSMemoria
        tests/pila/t_pilaSMemoria.cpp
        lib/SMemoria.h lib/SMemoria.cpp
        lib/pila/pilaSMemoria.cpp lib/pila/pilaSMemoria.h)
add_executable(
        matrizDispersaSMemoria
        tests/matrizDispersa/t_matrizDispersaSMemoria.cpp
        lib/SMemoria.h lib/SMemoria.cpp
        lib/matrizDispersa/matrizDispersaSMemoria.cpp lib/matrizDispersa/matrizDispersaSMemoria.h)
add_executable(
        matrizDispersaPtr
        tests/matrizDispersa/t_matrizDispersaPtr.cpp
        lib/matrizDispersa/matrizDispersaPtr.cpp lib/matrizDispersa/matrizDispersaPtr.h)
add_executable(
        matrizDispersaCSRPtr
        tests/matrizDispersa/t_matrizDispersaCSRPtr.cpp
        lib/matrizDispersa/matrizDispersaCSRPtr.cpp lib/matrizDispersa/matrizDispersaCSRPtr.h)
add_executable(
        matrizDispersaCSRSMemoria
        tests/matrizDispersa/t_matrizDispersaCSRSMemoria.cpp
        lib/SMemoria.h lib/SMemoria.cpp
        lib/matrizDispersa/matrizDispersaCSRSMemoria.cpp lib/matrizDispersa/matrizDispersaCSRSMemoria.h)
set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS})