//
// Created by rogerroca on 16/12/2022.
//
#include "matrizDispersaCSRVector.h"

// Elabore un proyecto que cargue una matriz dispersa que tenga la diagonal principal con puros unos "1",
// la matriz debe estar implementada con el formato de compresion por fila., una vez cargada la matriz
// debe mostrarse en pantalla en modo consola.
int main() {
    int dimMatriz = 5;
    matrizDispersaCSRVector m;
    m.dimensionar(dimMatriz,dimMatriz);
    for (int i=1;i<=dimMatriz;i++) {
        m.poner(i,i,1);
    }
    m.mostrar();
    return 0;
}