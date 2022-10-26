//
// Created by rogerroca on 19/10/2022.
//

#ifndef DATASTRUCTURE_LISTPTR_H
#define DATASTRUCTURE_LISTPTR_H

struct ListNode {
    int dataStored;
    ListNode *nextNode;
};
typedef ListNode *dirP;
typedef int DATA_TYPE; // Data type than the listVector can store.


class listPtr {
private:
    dirP firstPtr;
    int length;
public:

    listPtr();

    dirP getDir(int pos);

    dirP getLastDir();

    dirP getFirstDir();

    dirP getNextDir(dirP dir);

    dirP getPreviousDir(dirP dir);

    bool isEmpty();

    int getValue(dirP dir);

    int getValue(int pos);

    int getLength();

    void insertItem(dirP dir, DATA_TYPE value);

    void insertItemFirst(DATA_TYPE value);

    void insertItemLast(DATA_TYPE value);

    void delItem(dirP dir);

    void setItem(dirP dir, DATA_TYPE value);

    void print();
};


#endif //DATASTRUCTURE_LISTPTR_H
