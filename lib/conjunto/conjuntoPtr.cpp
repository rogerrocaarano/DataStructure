//
// Created by rogerroca on 14/12/2022.
//

#include "conjuntoPtr.h"
#include "iostream"

conjuntoPtr::conjuntoPtr() {
    cant = 0;
    ptrConj = nullptr;
}

bool conjuntoPtr::vacio() {
    return cant == 0;
}

bool conjuntoPtr::pertenece(conjuntoPtr::DATA_TYPE e) {
    dir ptrE = ptrConj;
    while (ptrE != nullptr) {
        if (ptrE->dato == e) return true;
        else ptrE = ptrE->sig;
    }
    return false;
}

void conjuntoPtr::inserta(conjuntoPtr::DATA_TYPE e) {
    if (pertenece(e)) return;
    dir ptrE = new ConjuntoNodo;
    ptrE->dato = e;
    ptrE->sig = ptrConj;
    ptrConj = ptrE;
    cant++;
}

int conjuntoPtr::cardinal() {
    return cant;
}

int conjuntoPtr::ordinal(conjuntoPtr::DATA_TYPE e) {
    if (!pertenece(e)) return -1; // excepción si "e" no pertenece al conjunto.
    int ord = 0;
    dir ptrE = ptrConj;
    while (ptrE != nullptr) {
        ord++;
        if (ptrE->dato == e) return ord;
        else ptrE = ptrE->sig;
    }
}

void conjuntoPtr::suprime(conjuntoPtr::DATA_TYPE e) {
    if (!pertenece(e)) return;
    dir ptrPrev = nullptr;
    dir ptrE = ptrConj;
    while (ptrE != nullptr) {
        if (ptrE->dato == e) break;
        ptrPrev = ptrE;
        ptrE = ptrE->sig;
    }
    if (ptrE == ptrConj) ptrConj = ptrE->sig; // Si "e" es el primer elemento
    else ptrPrev->sig = ptrE->sig; // Si "e" es cualquier otro elemento
    // eliminar el puntero y restar a "cant"
    delete ptrE;
    cant--;
}

conjuntoPtr::DATA_TYPE conjuntoPtr::muestrea() {
    if (!vacio()) {
        std::srand(time(0));
        int rnd = 1 + (rand() % cant);
        int x = 1;
        dir ptrMuestra = ptrConj;
        while (x != rnd) {
            ptrMuestra = ptrMuestra->sig;
            x++;
        }
        return ptrMuestra->dato;
    } else {
        std::cout << "El conjunto esta vacio." << std::endl;
    }
}

void conjuntoPtr::mostrar() {
    if (vacio()) {
        std::cout << "El conjunto esta vacio." << std::endl;
        return;
    }
    dir ptrE = ptrConj;
    std::cout << "{";
    while (ptrE != nullptr) {
        if (ptrE == ptrConj) {
            std::cout << ptrE->dato;
        } else {
            std::cout << "," << ptrE->dato;
        }
        ptrE = ptrE->sig;
    }
    std::cout << "}" << std::endl;
}

void conjuntoPtr::ponerElemento(conjuntoPtr::DATA_TYPE e) {
    if (pertenece(e)) return;
    dir ptrE = new ConjuntoNodo;
    ptrE->dato = e;
    if (vacio()) ptrConj = ptrE;
    else ultimoElemento()->sig = ptrE;
    ptrE->sig = nullptr; // el último elemento siempre apuntará a nulo.
    cant++;
}

void conjuntoPtr::interseccion(conjuntoPtr A, conjuntoPtr B) {
    if (!vacio()) {
        std::cout << "Error: el procedimiento debe ejecutarse en un conjunto vacio." << std::endl;
        return;
    }
    dir ptrA = A.ptrConj;
    while (ptrA != nullptr) {
        // si el dato de ptrA pertenece al conjunto B, incluir en el conjunto "interseccion"
        if (B.pertenece(ptrA->dato)) {
            ponerElemento(ptrA->dato);
        }
        // pasar al siguiente elemento de A
        ptrA = ptrA->sig;
    }
}

void conjuntoPtr::compInterseccion(conjuntoPtr A, conjuntoPtr B) {
    if (!vacio()) {
        std::cout << "Error: el procedimiento debe ejecutarse en un conjunto vacio." << std::endl;
        return;
    }
    dir ptrA = A.ptrConj;
    while (ptrA != nullptr) {
        // si el dato de ptrA no pertenece al conjunto B, incluir en el conjunto
        if (!B.pertenece(ptrA->dato)) {
            ponerElemento(ptrA->dato);
        }
        // pasar al siguiente elemento de A
        ptrA = ptrA->sig;
    }
    dir ptrB = B.ptrConj;
    while (ptrB != nullptr) {
        // si el dato de ptrA no pertenece al conjunto A, incluir en el conjunto
        if (!A.pertenece(ptrB->dato)) {
            ponerElemento(ptrB->dato);
        }
        // pasar al siguiente elemento de A
        ptrB = ptrB->sig;
    }
}

conjuntoPtr::dir conjuntoPtr::ultimoElemento() {
    dir ptrUltimo = ptrConj;
    while (ptrUltimo->sig != nullptr) {
        ptrUltimo = ptrUltimo->sig;
    }
    return ptrUltimo;
}
