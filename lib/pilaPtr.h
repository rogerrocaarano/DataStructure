//
// Created by rogerroca on 16/12/2022.
//

#ifndef INF220_PILAPTR_H
#define INF220_PILAPTR_H


class pilaPtr {
    typedef int DATA_TYPE;
    struct NodoPila {
        DATA_TYPE elemento;
        NodoPila *sig;
    };
    typedef NodoPila *dir;
private:
    dir tope;
public:
    pilaPtr();

    bool vacia();

    void meter(DATA_TYPE e);

    void sacar(DATA_TYPE &e);

    DATA_TYPE cima();

    std::string toStr();
};


#endif //INF220_PILAPTR_H
