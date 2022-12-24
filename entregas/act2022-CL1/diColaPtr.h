// ---------------------------------------------------------------------------

#ifndef UDicolaPH
#define UDicolaPH
// ---------------------------------------------------------------------------
#include <iostream>

class DicolaP {
    struct NodoC {
        int elemento;
        NodoC *sig;
    };
private:
    NodoC *ini;
    NodoC *fin;

public:
    DicolaP();

    bool vacia();

    void poner(int e);

    void sacar(int &e);

    int primero();

    int ultimo();

    void poner_frente(int e);

    void sacar_final(int &e);

    std::string to_str();
};

#endif
