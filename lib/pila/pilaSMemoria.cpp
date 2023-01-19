//
// Created by rogerroca on 15/1/2023.
//

#include "pilaSMemoria.h"

pilaSMemoria::pilaSMemoria() {
    m = SMemoria();
    tope = NULL_VALUE;
}

bool pilaSMemoria::vacia() {
    return m.Espacio_Disponible() == MAX_MEM_SPACE;
}

void pilaSMemoria::meter(pilaSMemoria::DATA_TYPE e) {
    // Pedir espacio de memoria
    memDir newMemSpace = m.new_espacio("elem,sig");
    if (newMemSpace == NULL_VALUE) {
        return;
    }
    m.poner_dato(newMemSpace, "->elem", e);
    m.poner_dato(newMemSpace, "->sig", tope);
    tope = newMemSpace;
}

void pilaSMemoria::sacar(pilaSMemoria::DATA_TYPE &e) {
    if (vacia()) {
        return;
    }
    memDir dir = tope;
    e = m.obtenerDato(dir, "->elem");
    tope = m.obtenerDato(dir, "->sig");
    m.delete_espacio(dir);
}

pilaSMemoria::DATA_TYPE pilaSMemoria::cima() {
    if (vacia()) {
        return 0;
    }
    return m.obtenerDato(tope, "->elem");
}

std::string pilaSMemoria::toStr() {
    std::string pilaStr = "";
    pilaSMemoria aux;
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
