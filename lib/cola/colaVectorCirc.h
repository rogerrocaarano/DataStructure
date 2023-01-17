//
// Created by rogerroca on 16/1/2023.
//

#ifndef INF220_COLAVECTORCIRC_H
#define INF220_COLAVECTORCIRC_H

#include "iostream"

const int COLA_SIZE = 100;

class colaVectorCirc {
    typedef int DATA_TYPE;
private:
    DATA_TYPE Cola[COLA_SIZE];
    DATA_TYPE firstCola, lastCola;

public:
    colaVectorCirc();

    bool vacia();

    void poner(colaVectorCirc::DATA_TYPE e);

    void sacar(colaVectorCirc::DATA_TYPE &e);

    colaVectorCirc::DATA_TYPE primero();

    std::string to_str();

    void mostrar();

    int siguiente(int dir);
};


#endif //INF220_COLAVECTORCIRC_H
