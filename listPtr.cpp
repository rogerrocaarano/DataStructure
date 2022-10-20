//
// Created by rogerroca on 19/10/2022.
//

#include "listPtr.h"
#include "iostream"

using namespace std;

const bool VERBOSE = true;

listPtr::listPtr() {
    firstPtr = nullptr;
    length = 0;
}

dirP listPtr::getDir(int pos) {
    if (isEmpty()) {
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

dirP listPtr::getLastDir() {
    if (isEmpty()) {
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

dirP listPtr::getFirstDir() {
    if (!isEmpty()) {
        return firstPtr;
    } else {
        cout << "Empty List." << endl;
        return nullptr;
    }
}

dirP listPtr::getNextDir(dirP dir) {
    if (isEmpty()) {
        cout << "Empty List." << endl;
        return nullptr;
    } else {
        if (dir == getLastDir()) {
            cout << "Invalid direction" << endl;
            return nullptr;
        } else return dir->nextNode;
    }
}

dirP listPtr::getPreviousDir(dirP dir) {
    if (isEmpty()) {
        cout << "Empty List." << endl;
        return nullptr;
    } else {
        if (dir == getFirstDir()) {
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

bool listPtr::isEmpty() {
    return length == 0;
}

int listPtr::getValue(dirP dir) {
    if (isEmpty()) {
        cout << "List is empty" << endl;
    } else {
        return dir->dataStored;
    }
}

int listPtr::getValue(int pos) {
    dirP dir = getDir(pos);
    getValue(dir);
}

int listPtr::getLength() {
    return length;
}

void listPtr::insertItem(dirP dir, DATA_TYPE value) {
    auto *x = new ListNode;
    x->dataStored = value;
    x->nextNode = nullptr;
    if (isEmpty()) {
        firstPtr = x;
        length = 1;
    } else {
        if (dir == getFirstDir()) {
            x->nextNode = dir;
            firstPtr = x;
        } else {
            getPreviousDir(dir)->nextNode = x;
            x->nextNode = dir;
        }
        length++;
    }
}

void listPtr::insertItemFirst(DATA_TYPE value) {
    auto *x = new ListNode;
    x->dataStored = value;
    x->nextNode = nullptr;
    if (isEmpty()) {
        length = 1;
        firstPtr = x;
    } else {
        x->nextNode = firstPtr;
        firstPtr = x;
        length++;
    }
}

void listPtr::insertItemLast(DATA_TYPE value) {
    if (isEmpty()) {
        insertItemFirst(value);
    } else {
        auto *x = new ListNode;
        x->dataStored = value;
        x->nextNode = nullptr;
        getLastDir()->nextNode = x;
        length++;
    }
}

void listPtr::delItem(dirP dir) {
    if (length == 0) {
        cout << "Lista Vacía." << endl;
        return;
    } else {
        if (dir == firstPtr) {
            dirP x = firstPtr;
            firstPtr = firstPtr->nextNode;
            delete (x);
        } else {
            dirP previousDir = getPreviousDir(dir);
            previousDir->nextNode = dir->nextNode;
            delete (dir);
        }
    }
    length--;
}

void listPtr::setItem(dirP dir, DATA_TYPE value) {
    if (isEmpty()) {
        cout << "List is empty" << endl;
    } else {
        dir->dataStored = value;
    }
}

void listPtr::printList() {
    dirP dir = getFirstDir();
    while (dir->nextNode != nullptr) {
        cout << getValue(dir) << ",";
        dir = dir->nextNode;
    }
    if (dir->nextNode == nullptr) {
        cout << getValue(dir) << endl;
    }
}