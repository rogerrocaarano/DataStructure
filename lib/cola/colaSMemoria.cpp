//
// Created by rogerroca on 16/1/2023.
//

#include "colaSMemoria.h"
#include "iostream"

colaSMemoria::colaSMemoria() {
    firstCola = lastCola = NULL_VALUE;
}

bool colaSMemoria::vacia() {
    return firstCola == NULL_VALUE;
}

void colaSMemoria::poner(colaSMemoria::DATA_TYPE e) {
    memDir newNodo = mem.new_espacio(NODO);
    mem.poner_dato(newNodo, ELEMENTO, e);
    mem.poner_dato(newNodo, SIG, NULL_VALUE);
    // Colocar al final de la cola
    if (vacia()) {
        firstCola = lastCola = newNodo;
    } else {
        mem.poner_dato(lastCola, SIG, newNodo);
        lastCola = newNodo;
    }
}

void colaSMemoria::sacar(colaSMemoria::DATA_TYPE &e) {
    if (vacia())
        return;
    // Sacar el primer elemento de la cola
    e = mem.obtenerDato(firstCola, ELEMENTO);
    memDir delNodo = firstCola;
    // Si es el único elemento en la cola, esta deberá apuntar a nulo
    if (firstCola == lastCola)
        firstCola = lastCola = NULL_VALUE;
    else
        firstCola = mem.obtenerDato(firstCola, SIG);
    mem.delete_espacio(delNodo);
}

colaSMemoria::DATA_TYPE colaSMemoria::primero() {
    if (!vacia())
        return mem.obtenerDato(firstCola, ELEMENTO);
}

std::string colaSMemoria::to_str() {
    std::string s = "<<";
    int e;
    auto *aux = new colaSMemoria();
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

void colaSMemoria::mostrar() {
    std::cout << to_str() << std::endl;
}
