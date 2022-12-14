//
// Created by rogerroca on 14/12/2022.
//
#include "conjuntoPtr.h"

int main() {
// crear conjunto A,B,C
    conjuntoPtr A, B, C;
// llamar al metodo poner elemento en A (2)
// llamar al metodo poner elemento en A (7)
    A.ponerElemento(2);
    A.ponerElemento(7);
// llamar al metodo poner elemento en B (3)
// llamar al metodo poner elemento en B (7)
    B.ponerElemento(3);
    B.ponerElemento(7);
// desarrollar el algoritmo que coloque el complemento de la interseccion de A con B en C
    C.compInterseccion(A, B);
// llamar a mostrar conjunto A // para el ejemplo mostraria {2,7}
// llamar a mostrar conjunto B // para el ejemplo mostraria {3,7}
// llamar a mostrar conjunto C // para el ejemplo mostraria {2,3}
    A.mostrar();
    B.mostrar();
    C.mostrar();
    return 0;
}