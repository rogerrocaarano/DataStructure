//
// Created by rogerroca on 16/1/2023.
//

#ifndef INF220_COLAVECTOR_H
#define INF220_COLAVECTOR_H

#include "iostream"

const int COLA_SIZE = 100;

class colaVector {
    typedef int DATA_TYPE;
private:
    DATA_TYPE Cola[COLA_SIZE];
    DATA_TYPE firstCola, lastCola;

public:
    colaVector();

    bool vacia();

    void poner(colaVector::DATA_TYPE e);

    void sacar(colaVector::DATA_TYPE &e);

    colaVector::DATA_TYPE primero();

    std::string to_str();

    void mostrar();
};


#endif //INF220_COLAVECTOR_H
