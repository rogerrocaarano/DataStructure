//
// Created by rogerroca on 5/12/2022.
//

#ifndef INF220_CONJUNTOLISTAVECTOR_H
#define INF220_CONJUNTOLISTAVECTOR_H

#include "listaVector.h"

class conjuntoListaVector {
private:
    listaVector *conjunto;
public:
    conjuntoListaVector();

    bool vacio();

    bool pertenece(DATA_TYPE e);

    void inserta(DATA_TYPE e);

    int cardinal();

    int ordinal(DATA_TYPE e);

    void suprime(DATA_TYPE e);

    DATA_TYPE muestrea();
};


#endif //INF220_CONJUNTOLISTAVECTOR_H
