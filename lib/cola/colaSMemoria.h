//
// Created by rogerroca on 16/1/2023.
//

#ifndef INF220_COLASMEMORIA_H
#define INF220_COLASMEMORIA_H

#include "../SMemoria.h"

class colaSMemoria {
    typedef int DATA_TYPE;
private:
    memDir firstCola; // Puntero al inicio de la cola
    memDir lastCola; // Puntero al final de la cola
    SMemoria mem; // Memoria simulada
public:
    colaSMemoria();

    bool vacia();

    void poner(colaSMemoria::DATA_TYPE e);

    void sacar(colaSMemoria::DATA_TYPE &e);

    colaSMemoria::DATA_TYPE primero();

    std::string to_str();

    void mostrar();

};


#endif //INF220_COLASMEMORIA_H
