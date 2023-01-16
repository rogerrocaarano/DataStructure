//
// Created by rogerroca on 16/12/2022.
//

#include <iostream>
#include "../lib/pila/pilaPtr.h"

int main() {
    pilaPtr p;
    p.meter(1);
    p.meter(2);
    p.meter(3.1);
    double e;
    p.sacar(e);
    std::cout << e << std::endl;
    std::cout << p.toStr() << std::endl;

    return 0;
}