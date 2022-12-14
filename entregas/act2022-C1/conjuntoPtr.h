//
// Created by rogerroca on 14/12/2022.
//

#ifndef INF220_CONJUNTOPTR_H
#define INF220_CONJUNTOPTR_H


class conjuntoPtr {
    struct ConjuntoNodo {
        int dato;
        ConjuntoNodo *sig;
    };

    typedef ConjuntoNodo *dir;
    typedef int DATA_TYPE;
private:
    int cant;
    dir ptrConj;
public:
    conjuntoPtr();

    bool vacio();

    bool pertenece(DATA_TYPE e);

    void inserta(DATA_TYPE e);

    int cardinal();

    int ordinal(DATA_TYPE e);

    void suprime(DATA_TYPE e);

    DATA_TYPE muestrea();

    void mostrar();

    void ponerElemento(DATA_TYPE e);

    void interseccion(conjuntoPtr A, conjuntoPtr B);

    void compInterseccion(conjuntoPtr A, conjuntoPtr B);

    dir ultimoElemento();
};


#endif //INF220_CONJUNTOPTR_H
