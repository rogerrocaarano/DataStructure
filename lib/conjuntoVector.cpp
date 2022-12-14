//
// Created by rogerroca on 6/12/2022.
//

#include <iostream>
#include "conjuntoVector.h"

conjuntoVector::conjuntoVector() {
    for (int i = 0; i < MAX_SIZE; i++) {
        V[i] = 0;
    }
    size = 0;
}

bool conjuntoVector::vacio() {
    return size == 0;
}

bool conjuntoVector::pertenece(int e) {
    return V[e] == 1;
}

void conjuntoVector::inserta(int e) {
    if (!pertenece(e)) {
        V[e] = 1;
        size++;
    }
}

int conjuntoVector::cardinal() {
    return size;
}

int conjuntoVector::ordinal(int e) {
    int pos = -1;
    if (pertenece(e)) {
        pos = 0;
        for (int i = 0; i < MAX_SIZE; i++) {
            if (V[i] == 1) {
                pos++;
            }
        }
    }
    return pos;
}

void conjuntoVector::suprime(int e) {
    if (pertenece(e)) {
        V[e] = 0;
        size--;
    }
}

int conjuntoVector::muestrea() {
    if (!vacio()) {
        std::srand(time(0));
        int rnd = 1 + (rand() % size);
        int pos = 0;
        for (int i = 0; i < MAX_SIZE; i++) {
            if (V[i] == 1) {
                pos++;
            }
            if (pos == rnd) {
                return V[i];
            }
        }
    }
}
