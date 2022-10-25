//
// Created by rogerroca on 5/10/2022.
//

#include "listSimRAM.h"
#include "iostream"

using namespace std;

namespace Ex {
    void emptyList() {
//        cout << "Empty List" << endl;
    }

    void incorrectDir() {
//        cout << "Incorrect Direction" << endl;
    }

    void lowMemSpace() {
//        cout << "Low memory space" << endl;
    }
}

listSimRAM::listSimRAM() {
    this->listMem = new simRAM(); // Init simulated memory.
    length = 0;
    ptrDir = NULL_VALUE;
}

listSimRAM::listSimRAM(simRAM *mem) {
    this->listMem = mem; // Use user input memory.
    length = 0;
    ptrDir = NULL_VALUE;
}

memDir listSimRAM::getLastDir() {
    memDir lastDir;
    if (isEmpty()) {
        Ex::emptyList();
    } else {
        memDir x = ptrDir;
        while (x != NULL_VALUE) {
            lastDir = x;
            x = listMem->getData(x, NEXT_LIST_ITEM_POINTER);
        }
        return lastDir;
    }
}

memDir listSimRAM::getFirstDir() {
    if (isEmpty()) {
        Ex::emptyList();
    } else {
        return ptrDir;
    }
}

memDir listSimRAM::getNextDir(memDir dir) {
    if (isEmpty()) {
        Ex::emptyList();
        return NULL_VALUE;
    } else {
        if (dir == getLastDir()) {
            /**
            * 17/10/2022 19:55
             * Added a return value for the exception.
            */
            Ex::incorrectDir();
            return NULL_VALUE;
        } else {
            return (listMem->getData(dir, NEXT_LIST_ITEM_POINTER));
        }
    }
}

memDir listSimRAM::getPreviousDir(memDir dir) {
    if (isEmpty()) {
        Ex::emptyList();
    } else {
        if (dir == getFirstDir()) {
            Ex::incorrectDir();
        } else {
            memDir x = ptrDir;
            memDir previousDir = NULL_VALUE;
            while (x != NULL_VALUE) {
                if (x == dir) {
                    return previousDir;
                }
                previousDir = x;
                x = listMem->getData(x, NEXT_LIST_ITEM_POINTER);
            }
            return previousDir;
        }
    }
}

bool listSimRAM::isEmpty() {
    return !(length > 0);
}

int listSimRAM::getValue(memDir dir) {
    if (isEmpty()) {
        Ex::emptyList();
    } else {
        return listMem->getData(dir, LIST_ITEM);
    }
}

int listSimRAM::getLength() {
    return length;
}

void listSimRAM::insertItem(memDir dir, DATA_TYPE value) {
    /**
    * 17/10/2022 17:00
    * Added exception for empty list
    **/
    if (this->isEmpty()) {
        insertItemFirst(value);
    } else {
        memDir x = listMem->newSpace(LIST_NODE); // request new memory space.
        if (x != NULL_VALUE) {
            listMem->setData(x, LIST_ITEM, value);
            listMem->setData(x, NEXT_LIST_ITEM_POINTER, dir);
            if (isEmpty()) {
                ptrDir = x;
                length = 1;
            } else {
                length++;
                if (dir == getFirstDir()) {
                    listMem->setData(x, NEXT_LIST_ITEM_POINTER, dir);
                    ptrDir = x;
                } else {
                    memDir prevDir = getPreviousDir(dir);
                    listMem->setData(prevDir, NEXT_LIST_ITEM_POINTER, x);
                    listMem->setData(x, NEXT_LIST_ITEM_POINTER, dir);
                }
            }
        } else {
            Ex::lowMemSpace();
        }
    }
}

void listSimRAM::insertItemFirst(DATA_TYPE value) {
    memDir x = listMem->newSpace(LIST_NODE);
    if (x != NULL_VALUE) {
        listMem->setData(x, LIST_ITEM, value);
        listMem->setData(x, NEXT_LIST_ITEM_POINTER, ptrDir);
        length++;
        ptrDir = x;
    } else {
        Ex::lowMemSpace();
    }
}

void listSimRAM::insertItemLast(DATA_TYPE value) {
    if (this->isEmpty()) {
        insertItemFirst(value);
    } else {
        memDir x = listMem->newSpace(LIST_NODE);
        if (x != NULL_VALUE) {
            listMem->setData(x, LIST_ITEM, value);
            listMem->setData(x, NEXT_LIST_ITEM_POINTER, NULL_VALUE);
            if (getLength() != NULL_VALUE) {
                listMem->setData(getLastDir(), NEXT_LIST_ITEM_POINTER, x);
            } else {
                ptrDir = x;
            }
            length++;
        } else {
            Ex::lowMemSpace();
        }
    }
}

void listSimRAM::delItem(memDir dir) {
    if (isEmpty()) {
        Ex::emptyList();
    } else {
        if (dir == ptrDir) {
            memDir x = ptrDir;
            ptrDir = listMem->getData(ptrDir, NEXT_LIST_ITEM_POINTER);
            listMem->delSpace(x);
        } else {
            listMem->setData(getPreviousDir(dir), NEXT_LIST_ITEM_POINTER, getNextDir(dir));
            listMem->delSpace(dir);
        }
        length--;
    }
}

void listSimRAM::setItem(memDir dir, DATA_TYPE value) {
    if (isEmpty()) {
        Ex::emptyList();
    } else {
        listMem->setData(dir, LIST_ITEM, value);
    }
}

void listSimRAM::show() {
    cout << "L: ";
    memDir dir = ptrDir;
    int i = 1;
    while (i <= length) {
        cout << listMem->getData(dir, LIST_ITEM);
        if (i < length) {
            cout << " , ";
        }
        dir = listMem->getData(dir, NEXT_LIST_ITEM_POINTER);
        i++;
    }
    cout << endl;
}
