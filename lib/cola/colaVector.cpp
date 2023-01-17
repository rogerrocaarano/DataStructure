//
// Created by rogerroca on 16/1/2023.
//

#include "colaVector.h"

colaVector::colaVector() {
    firstCola = lastCola = 0;
}

bool colaVector::vacia() {
    return firstCola == lastCola;
}

void colaVector::poner(colaVector::DATA_TYPE e) {
    if (lastCola < COLA_SIZE) {
        Cola[lastCola] = e;
        lastCola++;
    }
}

void colaVector::sacar(colaVector::DATA_TYPE &e) {
    if (vacia()) {
        return;
    }
    e = Cola[firstCola];
    firstCola++;
}

colaVector::DATA_TYPE colaVector::primero() {
    if (!vacia())
        return Cola[firstCola];
}

std::string colaVector::to_str() {
    std::string s = "<<";
    int e;
    auto *aux = new colaVector();
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

void colaVector::mostrar() {
    std::cout << to_str() << std::endl;
}

void dicolaVector::poner_frente(colaVector::DATA_TYPE e) {
    if (vacia()) {
        Cola[firstCola] = e;
        lastCola++;
    } else {
        if (lastCola < COLA_SIZE) {
            for (int i = lastCola; i >= firstCola; i--) {
                Cola[i] = Cola[i - 1];
            }
            Cola[firstCola] = e;
            lastCola++;
        }
    }

}

void dicolaVector::sacar_final(colaVector::DATA_TYPE &e) {
    if (vacia()) {
        return;
    }
    e = Cola[lastCola];
    lastCola--;
}
