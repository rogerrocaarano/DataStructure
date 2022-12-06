//
// Created by rogerroca on 5/10/2022.
//

#include "ListaRRA.h"
#include "iostream"

using namespace std;

namespace Ex {
    void emptyList() {
        cout << "Lista Vacía" << endl;
    }

    void incorrectDir() {
        cout << "Dirección Incorrecta" << endl;
    }

    void lowMemSpace() {
        cout << "Espacio de memoria insuficiente." << endl;
    }
}

ListaRRA::ListaRRA() {
    this->listMem = new rraCSMemoria(); // Init simulated memory.
    length = 0;
    ptrDir = NULL_VALUE;
}

ListaRRA::ListaRRA(rraCSMemoria *mem) {
    this->listMem = mem; // Use user input memory.
    length = 0;
    ptrDir = NULL_VALUE;
}

memDir ListaRRA::getLastDir() {
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

memDir ListaRRA::getFirstDir() {
    if (isEmpty()) {
        Ex::emptyList();
    } else {
        return ptrDir;
    }
}

memDir ListaRRA::getNextDir(memDir dir) {
    if (isEmpty()) {
        Ex::emptyList();
    } else {
        if (dir == getLastDir()) {
            Ex::incorrectDir();
        } else {
            return (listMem->getData(dir, NEXT_LIST_ITEM_POINTER));
        }
    }
}

memDir ListaRRA::getPreviousDir(memDir dir) {
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

bool ListaRRA::isEmpty() {
    return !(length > 0);
}

int ListaRRA::getValue(memDir dir) {
    if (isEmpty()) {
        Ex::emptyList();
    } else {
        return listMem->getData(dir, LIST_ITEM);
    }
}

int ListaRRA::getLength() {
    return length;
}

void ListaRRA::insertItem(memDir dir, DATA_TYPE value) {
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

void ListaRRA::insertItemFirst(DATA_TYPE value) {
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

void ListaRRA::insertItemLast(DATA_TYPE value) {
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

void ListaRRA::delItem(memDir dir) {
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

void ListaRRA::setItem(memDir dir, DATA_TYPE value) {
    if (isEmpty()) {
        Ex::emptyList();
    } else {
        listMem->setData(dir, LIST_ITEM, value);
    }
}
