//
// Created by rogerroca on 19/10/2022.
//

#include "listPtr.h"
#include "iostream"

using namespace std;

listPtr::listPtr() {
    ptrDir = nullptr;
    length = 0;
}

dirP listPtr::getLastDir() {
    if (!isEmpty()) {
        dirP x = ptrDir;
        dirP lastDir;
        while (x != nullptr) {
            lastDir = x;
            x = x->nextNode;
        }
        return lastDir;
    } else {
        cout << "Empty List." << endl;
        return nullptr;
    }
}

dirP listPtr::getFirstDir() {
    if (!isEmpty()) {
        return ptrDir;
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
        } else {
            return dir->nextNode;
        }
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
            dirP x = ptrDir;
            dirP lastDir = nullptr;
            while (x == nullptr) {
                if (x == dir) {
                    return lastDir;
                }
                lastDir = x;
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

int listPtr::getLength() {
    return length;
}

void listPtr::insertItem(dirP dir, DATA_TYPE value) {
    auto *x = new ListNode;
    if (x != nullptr) {
        x->dataStored = value;
        x->nextNode = nullptr;
        if (isEmpty()) {
            ptrDir = x;
            length = 1;
        } else {
            length++;
            if (dir == getFirstDir()) {
                x->nextNode = dir;
                ptrDir = x;
            } else {
                dirP previousDir = getPreviousDir(dir);
                previousDir->nextNode = x;
                x->nextNode = dir;
            }
        }
    }
}

void listPtr::insertItemFirst(DATA_TYPE value) {
    auto *x = new ListNode;
    if (x != nullptr) {
        x->dataStored = value;
        x->nextNode = ptrDir;
        ptrDir = x;
        length++;
    } else {
        cout << "Not enough memory space." << endl;
    }
}

void listPtr::insertItemLast(DATA_TYPE value) {
    auto *x = new ListNode;
    if (x != nullptr) {
        x->dataStored = value;
        x->nextNode = nullptr;
        length++;
        if (isEmpty()) {
            ptrDir = x;
        } else {
            getLastDir()->nextNode = x;
        }
    } else {
        cout << "Not enough memory space." << endl;
    }
}

void listPtr::delItem(dirP dir) {
    if (length == 0) {
        cout << "Lista Vacía." << endl;
        return;
    } else {
        if (dir == ptrDir) {
            dirP x = ptrDir;
            ptrDir = ptrDir->nextNode;
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
    string str = "[";
    dirP dirValue = ptrDir;
    while (dirValue != nullptr) {
        str += to_string(dirValue->dataStored);
        dirValue = dirValue->nextNode;
        if (dirValue != nullptr) {
            str += ",";
        }
        cout << str + "]" << endl;
    }
}
