//
// Created by rogerroca on 16/1/2023.
//

#include "colaVectorDesp.h"

colaVectorDesp::colaVectorDesp() {
    firstCola = lastCola = 0;
}

bool colaVectorDesp::vacia() {
    return firstCola == lastCola;
}

void colaVectorDesp::poner(colaVectorDesp::DATA_TYPE e) {
    if (lastCola < COLA_SIZE) {
        Cola[lastCola] = e;
        lastCola++;
    }
}

void colaVectorDesp::sacar(colaVectorDesp::DATA_TYPE &e) {
    if (vacia()) {
        return;
    }
    e = Cola[0];
    // Realizar el desplazamiento de los elementos del vector
    for (int i = 0; i < lastCola; i++)
        Cola[i] = Cola[i + 1];
    lastCola--;
}

colaVectorDesp::DATA_TYPE colaVectorDesp::primero() {
    if (!vacia())
        return Cola[0];
}

std::string colaVectorDesp::to_str() {
    std::string s = "<<";
    int e;
    auto *aux = new colaVectorDesp();
    while (!vacia()) {
        sacar(e);
        aux->poner(e);
        s += std::to_string(e);
        if (!vacia())
            s += ",";
    }
    while (!aux->vacia()) {
        aux->sacar(e);
        poner(e);
    }
    return s + "<<";
}

void colaVectorDesp::mostrar() {
    std::cout << to_str() << std::endl;
}
