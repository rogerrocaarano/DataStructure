//
// Created by rogerroca on 5/10/2022.
//

#ifndef RAMSIMULATOR_LISTARRA_H
#define RAMSIMULATOR_LISTARRA_H

#include "rraCSMemoria.h"

const string LIST_ITEM = "elem";
const string NEXT_LIST_ITEM_POINTER = "sig";
const string LIST_NODE = LIST_ITEM + ',' + NEXT_LIST_ITEM_POINTER;

typedef int DATA_TYPE; // Data type than the ListaRRA can store.

class ListaRRA {
private:
    memDir ptrDir; // Points to a memory node.
    int length;
    rraCSMemoria *listMem;
public:
    ListaRRA();

    ListaRRA(rraCSMemoria *);

    memDir getLastDir();

    memDir getFirstDir();

    memDir getNextDir(memDir);

    memDir getPreviousDir(memDir);

    bool isEmpty();

    int getValue(memDir);

    int getLength();

    void insertItem(memDir, DATA_TYPE);

    void insertItemFirst(DATA_TYPE);

    void insertItemLast(DATA_TYPE);

    void delItem(memDir);

    void setItem(memDir, DATA_TYPE);
};


#endif //RAMSIMULATOR_LISTARRA_H
