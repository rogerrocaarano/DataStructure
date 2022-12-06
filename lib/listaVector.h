//
// Created by rogerroca on 18/10/2022.
//

#ifndef DATASTRUCTURE_LISTAVECTOR_H
#define DATASTRUCTURE_LISTAVECTOR_H


const int MAX_VECTOR_SIZE = 100;
const int NULL_VALUE = -1;

typedef int dirV;
typedef int DATA_TYPE; // Data type than the listaVector can store.

class listaVector {
private:
    dirV ptrDir;
    int length;
    DATA_TYPE *list;
public:
    listaVector();

    dirV fin();

    dirV primero();

    dirV siguiente(dirV dir);

    dirV anterior(dirV dir);

    bool vacia();

    int recupera(dirV dir);

    int longitud();

    void inserta(dirV dir, DATA_TYPE value);

    void inserta_primero(DATA_TYPE value);

    void inserta_ultimo(DATA_TYPE value);

    void suprime(dirV dir);

    void modifica(dirV dir, DATA_TYPE value);

    void print();
};


#endif //DATASTRUCTURE_LISTAVECTOR_H
