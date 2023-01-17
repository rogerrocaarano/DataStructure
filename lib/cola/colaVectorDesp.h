//
// Created by rogerroca on 16/1/2023.
//

#ifndef INF220_COLAVECTORDESP_H
#define INF220_COLAVECTORDESP_H

#include "iostream"

const int COLA_SIZE = 100;

class colaVectorDesp {
protected:
    typedef int DATA_TYPE;
    DATA_TYPE Cola[COLA_SIZE];
    int firstCola, lastCola;

public:
    colaVectorDesp();

    bool vacia();

    void poner(colaVectorDesp::DATA_TYPE e);

    void sacar(colaVectorDesp::DATA_TYPE &e);

    colaVectorDesp::DATA_TYPE primero();

    std::string to_str();

    void mostrar();
};

class dicolaVectorDesp : public colaVectorDesp {
public:
    void poner_frente(colaVectorDesp::DATA_TYPE e);

    void sacar_final(colaVectorDesp::DATA_TYPE &e);
};

#endif //INF220_COLAVECTORDESP_H
