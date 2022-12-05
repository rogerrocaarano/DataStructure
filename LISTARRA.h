//
// Created by rogerroca on 5/10/2022.
//

#ifndef DATASTRUCTURE_LISTARRA_H
#define DATASTRUCTURE_LISTARRA_H

#include "MEMORIARRA.h"

const string LIST_ITEM = "elem";
const string NEXT_LIST_ITEM_POINTER = "sig";
const string LIST_NODE = LIST_ITEM + ',' + NEXT_LIST_ITEM_POINTER;

typedef int DATA_TYPE; // Data type than the LISTARRA can store.

class LISTARRA {
private:
    memDir ptrDir; // Points to a memory node.
    int length;
    MEMORIARRA *listMem;
public:
    LISTARRA();

    LISTARRA(MEMORIARRA *mem);

    memDir fin();

    memDir primero();

    memDir siguiente(memDir dir);

    memDir anterior(memDir dir);

    bool vacia();

    int recupera(memDir dir);

    int longitud();

    void inserta(memDir dir, DATA_TYPE value);

    void inserta_primero(DATA_TYPE value);

    void inserta_ultimo(DATA_TYPE value);

    void suprime(memDir dir);

    void modifica(memDir dir, DATA_TYPE value);

    void mostrar();
};


#endif //DATASTRUCTURE_LISTARRA_H
