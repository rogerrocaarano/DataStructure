//
// Created by rogerroca on 15/1/2023.
//

#ifndef INF220_PILASMEMORIA_H
#define INF220_PILASMEMORIA_H

#include "../SMemoria.h"

class pilaSMemoria {
    typedef int DATA_TYPE;

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
