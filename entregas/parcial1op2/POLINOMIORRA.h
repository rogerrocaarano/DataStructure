//
// Created by rogerroca on 20/10/2022.
//

#ifndef DATASTRUCTURE_POLINOMIORRA_H
#define DATASTRUCTURE_POLINOMIORRA_H

#include "../../lib/SMemoria.h"

const string COEF = "coef";
const string EXP = "exp";
const string NEXT_NODE = "sig";

const string POL_NODE = COEF + ',' + EXP + ',' + NEXT_NODE;

class POLINOMIORRA {
private:
    MEMRRA *m;
    memDir ptrPol;
    int length;

    memDir BuscarExponente(int exp);

    memDir BuscarTerminoN(int i);

public:
    POLINOMIORRA();

    POLINOMIORRA(MEMRRA *mem);

    bool EsCero();

    int Grado();

    int coeficiente(int exp);

    void AsignarCoeficiente(int coef, int exp);

    void poner_termino(int coef, int exp);

    int numero_terminos();

    int exponente(int term);

    void sumar(POLINOMIORRA p1, POLINOMIORRA p2);

    void restar(POLINOMIORRA p1, POLINOMIORRA p2);

    void multiplicar(POLINOMIORRA p1, POLINOMIORRA p2);

    void Opuesto(POLINOMIORRA p1, POLINOMIORRA p2);

    void mostrar();
};


#endif //DATASTRUCTURE_POLINOMIORRA_H
