//
// Created by rogerroca on 19/10/2022.
//

#include "listaPtr.h"
#include "iostream"

using namespace std;

const bool VERBOSE = true;

listaPtr::listaPtr() {
    firstPtr = nullptr;
    length = 0;
}

dirP listaPtr::getDir(int pos) {
    if (vacia()) {
        cout << "List empty.";
        return nullptr;
    } else {
        if (pos <= length - 1) {
            dirP x = firstPtr;
            int i = 0;
            while (i < pos) {
                x = x->nextNode;
                i++;
            }
            return x;
        } else {
            cout << "Position out ot range";
            return nullptr;
        }
    }
}

dirP listaPtr::fin() {
    if (vacia()) {
        cout << "Empty List." << endl;
        return nullptr;
    } else {
        if (this->length == 1) {
            return firstPtr;
        } else {
            dirP lastDir = firstPtr;
            while (lastDir->nextNode != nullptr) {
                lastDir = lastDir->nextNode;
            }
            return lastDir;
        }
    }
}

dirP listaPtr::primero() {
    if (!vacia()) {
        return firstPtr;
    } else {
        cout << "Empty List." << endl;
        return nullptr;
    }
}

dirP listaPtr::siguiente(dirP dir) {
    if (vacia()) {
        cout << "Empty List." << endl;
        return nullptr;
    } else {
        if (dir == fin()) {
            cout << "Invalid direction" << endl;
            return nullptr;
        } else return dir->nextNode;
    }
}

dirP listaPtr::anterior(dirP dir) {
    if (vacia()) {
        cout << "Empty List." << endl;
        return nullptr;
    } else {
        if (dir == primero()) {
            cout << "Invalid direction" << endl;
            return nullptr;
        } else {
            dirP x = firstPtr;
            dirP prevDir = nullptr;
            while (x != nullptr) {
                if (x == dir) {
                    return prevDir;
                }
                prevDir = x;
                x = x->nextNode;
            }
            return nullptr;
        }
    }
}

bool listaPtr::vacia() {
    return length == 0;
}

int listaPtr::recupera(dirP dir) {
    if (vacia()) {
        cout << "List is empty" << endl;
    } else {
        return dir->dataStored;
    }
}

int listaPtr::recupera(int pos) {
    dirP dir = getDir(pos);
    recupera(dir);
}

int listaPtr::longitud() {
    return length;
}

void listaPtr::inserta(dirP dir, DATA_TYPE value) {
    auto *x = new ListNode;
    x->dataStored = value;
    x->nextNode = nullptr;
    if (vacia()) {
        firstPtr = x;
        length = 1;
    } else {
        if (dir == primero()) {
            x->nextNode = dir;
            firstPtr = x;
        } else {
            anterior(dir)->nextNode = x;
            x->nextNode = dir;
        }
        length++;
    }
}

void listaPtr::inserta_primero(DATA_TYPE value) {
    auto *x = new ListNode;
    x->dataStored = value;
    x->nextNode = nullptr;
    if (vacia()) {
        length = 1;
        firstPtr = x;
    } else {
        x->nextNode = firstPtr;
        firstPtr = x;
        length++;
    }
}

void listaPtr::inserta_ultimo(DATA_TYPE value) {
    if (vacia()) {
        inserta_primero(value);
    } else {
        auto *x = new ListNode;
        x->dataStored = value;
        x->nextNode = nullptr;
        fin()->nextNode = x;
        length++;
    }
}

void listaPtr::suprime(dirP dir) {
    if (length == 0) {
        cout << "Lista Vacía." << endl;
        return;
    } else {
        if (dir == firstPtr) {
            dirP x = firstPtr;
            firstPtr = firstPtr->nextNode;
            delete (x);
        } else {
            dirP previousDir = anterior(dir);
            previousDir->nextNode = dir->nextNode;
            delete (dir);
        }
    }
    length--;
}

void listaPtr::modifica(dirP dir, DATA_TYPE value) {
    if (vacia()) {
        cout << "List is empty" << endl;
    } else {
        dir->dataStored = value;
    }
}

void listaPtr::print() {
    dirP dir = primero();
    while (dir->nextNode != nullptr) {
        cout << recupera(dir) << ",";
        dir = dir->nextNode;
    }
    if (dir->nextNode == nullptr) {
        cout << recupera(dir) << endl;
    }
}