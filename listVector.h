//
// Created by rogerroca on 18/10/2022.
//

#ifndef RAMSIMULATOR_LISTVECTOR_H
#define RAMSIMULATOR_LISTVECTOR_H


const int MAX_VECTOR_SIZE = 100;
const int NULL_VALUE = -1;

typedef int dir;
typedef int DATA_TYPE; // Data type than the listVector can store.

class listVector {
private:
    dir ptrDir;
    int length;
    DATA_TYPE *list;
public:
    listVector();

    dir getLastDir();

    dir getFirstDir();

    dir getNextDir(dir dir);

    dir getPreviousDir(dir dir);

    bool isEmpty();

    int getValue(dir dir);

    int getLength();

    void insertItem(dir dir, DATA_TYPE value);

    void insertItemFirst(DATA_TYPE value);

    void insertItemLast(DATA_TYPE value);

    void delItem(dir dir);

    void setItem(dir dir, DATA_TYPE value);

    void printList();
};


#endif //RAMSIMULATOR_LISTVECTOR_H
