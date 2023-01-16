//
// Created by rogerroca on 15/1/2023.
//

#ifndef INF220_PILAVECTOR_H
#define INF220_PILAVECTOR_H

#include "iostream"

const int MAX_VECTOR_SIZE = 100;

class pilaVector {
    typedef int DATA_TYPE;
private:
    int elementos[MAX_VECTOR_SIZE];
    int tope;

public:
    pilaVector();

    bool vacia();

    void meter(DATA_TYPE e);

    void sacar(DATA_TYPE &e);

    DATA_TYPE cima();

    std::string toStr();
};


#endif //INF220_PILAVECTOR_H
