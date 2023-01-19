//
// Created by rogerroca on 17/1/2023.
//

// NOTAS:
// - El valor NULO para la memoria es -1.
// - El primer indice de la memoria es 0.

#include "SMemoria.h"
#include "colaPrioridad.h"
#include "iostream"

int elem;

void mostrar(int e) {
    if (elem == 0)
        return;
    std::cout << "ULTIMO ELEMENTO SACADO DE LA COLA:" << elem << std::endl;
}

auto *M = new SMemoria();
auto *pRRA = new ColaPrioridadRRA(M);

int main() {
    pRRA->poner(10, 1);
    pRRA->poner(200, 2);
    pRRA->poner(1000, 3);
    pRRA->poner(300, 2);
    pRRA->asignar_frecuencia_prioridad(2, 1);
    pRRA->asignar_frecuencia_prioridad(2, 2);
    pRRA->asignar_frecuencia_prioridad(1, 3);
    M->mostrar();
    pRRA->sacar(elem);
    mostrar(elem);
    pRRA->sacar(elem);
    mostrar(elem);
    pRRA->sacar(elem);
    mostrar(elem);
    M->mostrar();
    return 0;
}