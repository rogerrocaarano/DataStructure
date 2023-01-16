//
// Created by rogerroca on 16/1/2023.
//

#include "../../lib/cola/colaPtr.h"

int main() {
    colaPtr c;
    c.poner(1);
    c.poner(2);
    c.poner(3);
    c.poner(4);
    c.mostrar();
    int e;
    c.sacar(e);
    std::cout << e << std::endl;
    std::cout << c.primero();
    return 0;
}