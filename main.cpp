#include "iostream"
#include "lib/conjuntoListaVector.h"

int main() {
    conjuntoListaVector C;
    std::cout << "TEST1::vacio()";
    if (C.vacio()) {
        std::cout << " PASS" << std::endl;
    } else {
        std::cout << " NO PASS" << std::endl;
    }
    C.inserta(10);
    C.inserta(20);
    std::cout << "TEST2::vacio()";
    if (!C.vacio()) {
        std::cout << " PASS" << std::endl;
    } else {
        std::cout << " NO PASS" << std::endl;
    }
    std::cout << "TEST3::pertenece()";
    if (C.pertenece(20)) {
        std::cout << " PASS" << std::endl;
    } else {
        std::cout << "NO PASS" << std::endl;
    }
    std::cout << "TEST4::cardinal()";
    if (C.cardinal() == 2) {
        std::cout << " PASS" << std::endl;
    } else {
        std::cout << "NO PASS" << std::endl;
    }
    std::cout << "TEST5::ordinal()";
    if (C.ordinal(10) == 2 && C.ordinal(20) == 1) {
        std::cout << " PASS" << std::endl;
    } else {
        std::cout << "NO PASS" << std::endl;
    }
    C.suprime(10);
    std::cout << "TEST6::suprime()";
    if (!C.pertenece(10) && C.cardinal() == 1) {
        std::cout << " PASS" << std::endl;
    } else {
        std::cout << "NO PASS" << std::endl;
    }
    C.inserta(1);
    C.inserta(100);
    std::cout << C.muestrea() << std::endl;
    return 0;
}