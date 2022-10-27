//
// Created by rogerroca on 5/10/2022.
//

#ifndef DATASTRUCTURE_LISTSIMRAM_H
#define DATASTRUCTURE_LISTSIMRAM_H

#include "../simRAM.h"

const string LIST_ITEM = "L:value";
const string NEXT_LIST_ITEM_POINTER = "L:next";
const string LIST_NODE = LIST_ITEM + ',' + NEXT_LIST_ITEM_POINTER;

typedef int DATA_TYPE; // Data type than the listSimRAM can store.

class listSimRAM {
private:
    memDir ptrDir; // Points to a memory node.
    int length;
    simRAM *listMem;
public:
    listSimRAM();

    listSimRAM(simRAM *mem);

    memDir getLastDir();

    memDir getFirstDir();

    memDir getNextDir(memDir dir);

    memDir getPreviousDir(memDir dir);

    bool isEmpty();

    int getValue(memDir dir);

    int getLength();

    void insertItem(memDir dir, DATA_TYPE value);

    void insertItemFirst(DATA_TYPE value);

    void insertItemLast(DATA_TYPE value);

    void delItem(memDir dir);

    void setItem(memDir dir, DATA_TYPE value);

    void print();
};


#endif //DATASTRUCTURE_LISTSIMRAM_H
