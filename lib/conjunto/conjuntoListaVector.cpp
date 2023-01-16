//
// Created by rogerroca on 5/12/2022.
//

#include <iostream>
#include "conjuntoListaVector.h"

conjuntoListaVector::conjuntoListaVector() {
    this->conjunto = new listaVector();
}

bool conjuntoListaVector::vacio() {
    return conjunto->longitud() == 0;
}

bool conjuntoListaVector::pertenece(DATA_TYPE e) {
    if (!vacio()) {
        dirV dir = conjunto->primero();
        while (dir != NULL_VALUE) {
            DATA_TYPE value = conjunto->recupera(dir);
            if (value == e)
                return true;
            else
                dir = conjunto->siguiente(dir);
        }
    }
    return false;
}

void conjuntoListaVector::inserta(DATA_TYPE e) {
    if (!pertenece(e)) {
        conjunto->inserta_primero(e);
    }
}

int conjuntoListaVector::cardinal() {
    // Devuelve la cantidad total de elementos
    return conjunto->longitud();
}

int conjuntoListaVector::ordinal(DATA_TYPE e) {
    // Devuelve el lugar que ocupa el elemento en el conjunto
    if (!vacio() && pertenece(e)) {
        int count = 1;
        dirV dir = conjunto->primero();
        while (dir != NULL_VALUE) {
            DATA_TYPE x = conjunto->recupera(dir);
            if (x == e)
                return count;
            else {
                count++;
                dir = conjunto->siguiente(dir);
            }
        }
    } else {
        return NULL_VALUE;
    }
}

void conjuntoListaVector::suprime(DATA_TYPE e) {
    if (pertenece(e)) {
        dirV dir = conjunto->primero();
        while (dir != NULL_VALUE) {
            DATA_TYPE x = conjunto->recupera(dir);
            if (x == e) {
                conjunto->suprime(dir);
                break;
            } else {
                dir = conjunto->siguiente(dir);
            }
        }
    }
}

DATA_TYPE conjuntoListaVector::muestrea() {
    if (!vacio()) {
        std::srand(time(0));
        int rnd = 1 + (rand() % conjunto->longitud());
        int x = 1;
        dirV dir = conjunto->primero();
        while (x != rnd) {
            dir = conjunto->siguiente(dir);
            x++;
        }
        return conjunto->recupera(dir);
    }
}
