//
// Created by rogerroca on 5/10/2022.
//

#ifndef RAMSIMULATOR_LIST_H
#define RAMSIMULATOR_LIST_H

#include "simRAM.h"

const string LIST_ITEM = "item";
const string NEXT_LIST_ITEM_POINTER = "next";
const string LIST_NODE = LIST_ITEM + ',' + NEXT_LIST_ITEM_POINTER;

typedef int DATA_TYPE; // Data type than the list can store.

class list {
private:
    memDir ptrDir; // Points to a memory node.
    int length;
    simRAM *listMem;
public:
    list();

    list(simRAM *);

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


#endif //RAMSIMULATOR_LIST_H
