//
// Created by rogerroca on 15/1/2023.
//

#ifndef INF220_PILALISTA_H
#define INF220_PILALISTA_H

#include "listaPtr.h"
#include "iostream"

class pilaLista {
private:
    listaPtr L;
public:
    pilaLista();

    bool vacia();

    void meter(DATA_TYPE e);

    void sacar(DATA_TYPE &e);

    DATA_TYPE cima();

    std::string toStr();
};


#endif //INF220_PILALISTA_H
