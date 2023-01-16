//
// Created by rogerroca on 15/1/2023.
//

#include "pilaVector.h"

pilaVector::pilaVector() {
    tope = -1;
}

bool pilaVector::vacia() {
    return tope == -1;
}

void pilaVector::meter(pilaVector::DATA_TYPE e) {
    if (tope == MAX_VECTOR_SIZE - 1) {
        return;
    }
    tope++;
    elementos[tope] = e;
}

void pilaVector::sacar(pilaVector::DATA_TYPE &e) {
    if (vacia()) {
        return;
    }
    e = elementos[tope];
    tope--;
}

pilaVector::DATA_TYPE pilaVector::cima() {
    return elementos[tope];
}

std::string pilaVector::toStr() {
    std::string pilaStr = "";
    pilaVector aux;
    // Sacar los elementos de la pila original e introducirlos en una pila auxiliar
    while (!vacia()) {
        DATA_TYPE e;
        sacar(e);
        pilaStr.append(std::to_string(e) + " ");
        aux.meter(e);
    }
    // Vaciar la pila auxiliar y meter los elementos en la pila original
    while (!aux.vacia()) {
        DATA_TYPE e;
        aux.sacar(e);
        meter(e);
    }
    return pilaStr;
}
