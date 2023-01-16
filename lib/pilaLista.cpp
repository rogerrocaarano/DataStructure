//
// Created by rogerroca on 15/1/2023.
//

#include "pilaLista.h"

pilaLista::pilaLista() {
    L = listaPtr();
}

bool pilaLista::vacia() {
    return L.vacia();
}

void pilaLista::meter(DATA_TYPE e) {
    L.inserta(L.primero(), e);
}

void pilaLista::sacar(DATA_TYPE &e) {
    e = L.recupera(L.primero());
    L.suprime(L.primero());
}

DATA_TYPE pilaLista::cima() {
    return L.recupera(L.primero());
}

std::string pilaLista::toStr() {
    std::string pilaStr = "";
    pilaLista aux;
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
