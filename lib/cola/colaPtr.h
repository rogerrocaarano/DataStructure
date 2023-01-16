//
// Created by rogerroca on 16/1/2023.
//

#ifndef INF220_COLAPTR_H
#define INF220_COLAPTR_H

#include "iostream"

class colaPtr {
    typedef int DATA_TYPE;

    struct NodoC {
        DATA_TYPE elemento;
        NodoC *sig;
    };
private:
    NodoC *firstCola; // Puntero al inicio de la cola
    NodoC *lastCola; // Puntero al final de la cola
public:
    colaPtr();

    bool vacia();

    void poner(colaPtr::DATA_TYPE e);

    void sacar(colaPtr::DATA_TYPE &e);

    colaPtr::DATA_TYPE primero();

    std::string to_str();

    void mostrar();


};


#endif //INF220_COLAPTR_H
