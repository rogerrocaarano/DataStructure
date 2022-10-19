//
// Created by rogerroca on 18/10/2022.
//

#ifndef RAMSIMULATOR_LISTVECTOR_H
#define RAMSIMULATOR_LISTVECTOR_H


const int MAX_VECTOR_SIZE = 100;
const int NULL_VALUE = -1;

typedef int dirV;
typedef int DATA_TYPE; // Data type than the listVector can store.

class listVector {
private:
    dirV ptrDir;
    int length;
    DATA_TYPE *list;
public:
    listVector();

    dirV getLastDir();

    dirV getFirstDir();

    dirV getNextDir(dirV dir);

    dirV getPreviousDir(dirV dir);

    bool isEmpty();

    int getValue(dirV dir);

    int getLength();

    void insertItem(dirV dir, DATA_TYPE value);

    void insertItemFirst(DATA_TYPE value);

    void insertItemLast(DATA_TYPE value);

    void delItem(dirV dir);

    void setItem(dirV dir, DATA_TYPE value);

    void printList();
};


#endif //RAMSIMULATOR_LISTVECTOR_H
