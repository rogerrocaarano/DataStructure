//
// Created by rogerroca on 16/1/2023.
//

#ifndef INF220_COLAVECTORDESP_H
#define INF220_COLAVECTORDESP_H

#include "iostream"

const int COLA_SIZE = 100;

class colaVectorDesp {
    typedef int DATA_TYPE;
private:
    DATA_TYPE Cola[COLA_SIZE];
    DATA_TYPE firstCola, lastCola;

public:
    colaVectorDesp();

    bool vacia();

    void poner(colaVectorDesp::DATA_TYPE e);

    void sacar(colaVectorDesp::DATA_TYPE &e);

    colaVectorDesp::DATA_TYPE primero();

    std::string to_str();

    void mostrar();
};


#endif //INF220_COLAVECTORDESP_H
