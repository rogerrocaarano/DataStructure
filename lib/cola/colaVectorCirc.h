//
// Created by rogerroca on 16/1/2023.
//

#ifndef INF220_COLAVECTORCIRC_H
#define INF220_COLAVECTORCIRC_H

#include "iostream"

const int COLA_SIZE = 100;

class colaVectorCirc {
protected:
    typedef int DATA_TYPE;
    DATA_TYPE Cola[COLA_SIZE];
    int firstCola, lastCola;

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

class dicolaVectorCirc : public colaVectorCirc {
private:
    int anterior(int dir);

public:
    void poner_frente(colaVectorCirc::DATA_TYPE e);

    void sacar_final(colaVectorCirc::DATA_TYPE &e);
};


#endif //INF220_COLAVECTORCIRC_H
