//
// Created by rogerroca on 15/1/2023.
//

#ifndef INF220_PILASMEMORIA_H
#define INF220_PILASMEMORIA_H

#include "SMemoria.h"

class pilaSMemoria {
    typedef int DATA_TYPE;
    const string PILA_ITEM = "elem";
    const string NEXT_PILA_ITEM_POINTER = "sig";
    const string PILA_NODE = PILA_ITEM + ',' + NEXT_PILA_ITEM_POINTER;
private:
    memDir tope;
    SMemoria m;
public:
    pilaSMemoria();

    bool vacia();

    void meter(DATA_TYPE e);

    void sacar(DATA_TYPE &e);

    DATA_TYPE cima();

    std::string toStr();
};


#endif //INF220_PILASMEMORIA_H
