//
// Created by rogerroca on 16/1/2023.
//

#include "../../lib/cola/colaPtr.h"

int main() {
    dicolaPtr c;
    c.poner(1);
    c.poner(2);
    c.poner(3);
    c.poner(4);
    c.mostrar();
    int e;
    c.sacar(e);
    c.mostrar();
    c.poner_frente(10);
    c.mostrar();
    c.sacar_final(e);
    c.mostrar();
    return 0;
}