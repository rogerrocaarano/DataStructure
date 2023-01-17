//
// Created by rogerroca on 16/1/2023.
//

#include "colaPtr.h"

colaPtr::colaPtr() {
    firstCola = lastCola = nullptr;
}

bool colaPtr::vacia() {
    return firstCola == nullptr;
}

void colaPtr::poner(colaPtr::DATA_TYPE e) {
    auto *newNodo = new NodoC();
    newNodo->elemento = e;
    newNodo->sig = nullptr;
    // Colocar al final de la cola
    if (vacia()) {
        firstCola = lastCola = newNodo;
    } else {
        lastCola->sig = newNodo;
        lastCola = newNodo;
    }
}

void colaPtr::sacar(colaPtr::DATA_TYPE &e) {
    if (vacia())
        return;
    // Sacar el primer elemento de la cola
    e = firstCola->elemento;
    NodoC *delNodo = firstCola;
    // Si es el único elemento en la cola, esta deberá apuntar a nulo
    if (firstCola == lastCola)
        firstCola = lastCola = nullptr;
    else
        firstCola = firstCola->sig;
    delete delNodo;
}

colaPtr::DATA_TYPE colaPtr::primero() {
    if (!vacia())
        return firstCola->elemento;
}

std::string colaPtr::to_str() {
    std::string s = "<<";
    int e;
    auto *aux = new colaPtr();
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

void colaPtr::mostrar() {
    std::cout << to_str() << std::endl;
}

void dicolaPtr::poner_frente(colaPtr::DATA_TYPE e) {
    auto *aux = new NodoC();
    if (vacia())
        firstCola = lastCola = aux;
    else {
        aux->elemento = e;
        aux->sig = firstCola;
        firstCola = aux;
    }
}

void dicolaPtr::sacar_final(DATA_TYPE &e) {
    if (vacia()) {
        return;
    }
    e = lastCola->elemento;
    NodoC *sacar = lastCola;
    if (firstCola == lastCola)
        firstCola = lastCola = nullptr;
    else {
        NodoC *ant = firstCola;
        while (ant->sig != lastCola)
            ant = ant->sig;
        ant->sig = nullptr;
        lastCola = ant;
    }
    delete sacar;
}
