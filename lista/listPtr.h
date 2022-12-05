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

    dirP fin();

    dirP primero();

    dirP siguiente(dirP dir);

    dirP anterior(dirP dir);

    bool vacia();

    int recupera(dirP dir);

    int recupera(int pos);

    int longitud();

    void inserta(dirP dir, DATA_TYPE value);

    void inserta_primero(DATA_TYPE value);

    void inserta_ultimo(DATA_TYPE value);

    void suprime(dirP dir);

    void modifica(dirP dir, DATA_TYPE value);

    void print();
};


#endif //DATASTRUCTURE_LISTPTR_H
