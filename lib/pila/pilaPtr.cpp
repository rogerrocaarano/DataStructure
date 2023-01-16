//
// Created by rogerroca on 16/12/2022.
//

#include <iostream>
#include "pilaPtr.h"

pilaPtr::pilaPtr() {
    tope = nullptr;
}

bool pilaPtr::vacia() {
    return tope == nullptr;
}

void pilaPtr::meter(pilaPtr::DATA_TYPE e) {
    dir x = new NodoPila;
    x->elemento = e;
    x->sig = tope;
    tope = x;
}

void pilaPtr::sacar(pilaPtr::DATA_TYPE &e) {
    // Suprime el elemento situado en el tope de la pila y lo retorna
    if (vacia()) {
        std::cout << "Error: La pila esta vacia." << std::endl;
        return;
    }
    e = cima();
    dir topeAnterior = tope;
    tope = topeAnterior->sig;
    delete topeAnterior;
}

pilaPtr::DATA_TYPE pilaPtr::cima() {
    if (!vacia()) {
        return tope->elemento;
    } else {
        std::cout << "Error: La pila esta vacia." << std::endl;
    }
}

std::string pilaPtr::toStr() {
    std::string pilaStr = "";
    pilaPtr aux;
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
