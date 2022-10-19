//
// Created by rogerroca on 18/10/2022.
//

#include "listVector.h"
#include "iostream"

using namespace std;

listVector::listVector() {
    list = new DATA_TYPE[MAX_VECTOR_SIZE];
    this->length = 0;
}

dir listVector::getLastDir() {
    if (!isEmpty()) {
        return length - 1;
    } else {
        cout << "Empty List." << endl;
        return NULL_VALUE;
    }
}

dir listVector::getFirstDir() {
    if (!isEmpty()) {
        return 0;
    } else {
        cout << "Empty List." << endl;
        return NULL_VALUE;
    }
}

dir listVector::getNextDir(dir dir) {
    if (isEmpty()) {
        cout << "Empty List." << endl;
        return NULL_VALUE;
    } else {
        if (dir >= 0 && dir < length - 1) {
            return dir + 1;
        } else {
            cout << "Invalid direction" << endl;
            return NULL_VALUE;
        }
    }
}

dir listVector::getPreviousDir(dir dir) {
    if (isEmpty()) {
        cout << "Empty List." << endl;
        return -1;
    } else {
        if (dir > 0 && dir <= length - 1) {
            return dir - 1;
        } else {
            cout << "Invalid direction" << endl;
            return NULL_VALUE;
        }
    }
}

bool listVector::isEmpty() {
    return length == 0;
}

int listVector::getValue(dir dir) {
    if (isEmpty()) {
        cout << "Empty List." << endl;
    } else {
        if (dir >= 0 && dir <= length - 1) {
            return list[dir];
        } else {
            cout << "Invalid direction." << endl;
        }
    }
}

int listVector::getLength() {
    return length;
}

void listVector::insertItem(dir dir, DATA_TYPE value) {
    if (length == MAX_VECTOR_SIZE) {
        cout << "List is full.";
        return;
    } else {
        if (dir >= 0 && dir <= length - 1) {
            length++;
            for (int i = length - 1; i > dir; i--) {
                list[i] = list[i - 1];
            }
            list[dir] = value;
        } else {
            cout << "Invalid direction." << endl;
            return;
        }
    }
}

void listVector::insertItemFirst(DATA_TYPE value) {
    insertItem(0, value);
}

void listVector::insertItemLast(DATA_TYPE value) {
    if (length == MAX_VECTOR_SIZE) {
        cout << "List is full.";
    } else {
        length++;
        list[length - 1] = value;
    }
}

void listVector::delItem(dir dir) {
    if (length == MAX_VECTOR_SIZE) {
        cout << "List is full.";
        return;
    } else {
        if (dir >= 0 && dir <= length - 1) {
            length--;
            for (int i = dir; i > length - 1; i++) {
                list[i] = list[i + 1];
            }
        } else {
            cout << "Invalid direction." << endl;
            return;
        }
    }
}

void listVector::setItem(dir dir, DATA_TYPE value) {
    if (isEmpty()) {
        cout << "List is empty" << endl;
        return;
    } else {
        if (dir >= 0 && dir <= length - 1) {
            list[dir] = value;
        } else {
            cout << "Invalid direction." << endl;
            return;
        }
    }
}

void listVector::printList() {
    if (isEmpty()) {
        cout << "List is empty" << endl;
    } else {
        cout << "List: ";
        for (int i = 0; i == length - 1; i++) {
            if (i == length - 1) {
                cout << list[i] << endl;
            } else {
                cout << list[i] << " , ";
            }
        }
    }
}