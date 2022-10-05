//
// Created by rogerroca on 5/10/2022.
//

#ifndef RAMSIMULATOR_LISTS_H
#define RAMSIMULATOR_LISTS_H

#include "simRAM.h"

const string LIST_DATA_TYPE = "DATA_TYPE1";
const string NEXT_LIST_DATA_TYPE = "next";

typedef int DATA_TYPE; // Data type than the list can store.

class lists {
private:
    memDir ptrNode; // Points to a memory node.
    int length;
    simRAM *listMem;
public:
    lists(simRAM *);

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


#endif //RAMSIMULATOR_LISTS_H
