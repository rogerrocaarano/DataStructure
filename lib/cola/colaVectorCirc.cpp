//
// Created by rogerroca on 16/1/2023.
//

#include "colaVectorCirc.h"

colaVectorCirc::colaVectorCirc() {
    firstCola = lastCola = 0;
}

bool colaVectorCirc::vacia() {
    return firstCola == lastCola;
}

void colaVectorCirc::poner(colaVectorCirc::DATA_TYPE e) {
    if (siguiente(lastCola) != firstCola) {
        Cola[lastCola] = e;
        lastCola = siguiente(lastCola);
    }
}

void colaVectorCirc::sacar(colaVectorCirc::DATA_TYPE &e) {
    if (vacia()) {
        return;
    }
    e = Cola[firstCola];
    firstCola = siguiente(firstCola);
}

colaVectorCirc::DATA_TYPE colaVectorCirc::primero() {
    if (!vacia())
        return Cola[firstCola];
}

std::string colaVectorCirc::to_str() {
    std::string s = "<<";
    int e;
    auto *aux = new colaVectorCirc();
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

void colaVectorCirc::mostrar() {
    std::cout << to_str() << std::endl;
}

int colaVectorCirc::siguiente(int dir) {
    if (dir == COLA_SIZE - 1)
        return 0;
    else
        return dir + 1;
}

void dicolaVectorCirc::poner_frente(colaVectorCirc::DATA_TYPE e) {
    if (siguiente(lastCola) != firstCola) {
        firstCola = anterior(firstCola);
        Cola[firstCola] = e;
    }
}

void dicolaVectorCirc::sacar_final(colaVectorCirc::DATA_TYPE &e) {
    if (!vacia()) {
        e = Cola[lastCola - 1];
        lastCola = anterior(lastCola);
    }
}

int dicolaVectorCirc::anterior(int dir) {
    if (dir == 0)
        return COLA_SIZE - 1;
    else
        return dir - 1;
}
