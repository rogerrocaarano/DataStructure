//
// Created by rogerroca on 19/10/2022.
//

#ifndef RAMSIMULATOR_LISTPTR_H
#define RAMSIMULATOR_LISTPTR_H

struct ListNode {
    int dataStored;
    ListNode *nextNode;
};
typedef ListNode *dirP;
typedef int DATA_TYPE; // Data type than the listVector can store.


class listPtr {
private:
    dirP ptrDir;
    int length;
public:

    listPtr();

    dirP getLastDir();

    dirP getFirstDir();

    dirP getNextDir(dirP dir);

    dirP getPreviousDir(dirP dir);

    bool isEmpty();

    int getValue(dirP dir);

    int getLength();

    void insertItem(dirP dir, DATA_TYPE value);

    void insertItemFirst(DATA_TYPE value);

    void insertItemLast(DATA_TYPE value);

    void delItem(dirP dir);

    void setItem(dirP dir, DATA_TYPE value);

    void printList();
};


#endif //RAMSIMULATOR_LISTPTR_H
