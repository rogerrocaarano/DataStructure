//
// Created by rogerroca on 6/10/2022.
//

#ifndef DATASTRUCTURE_POLYNOMIALLIST_H
#define DATASTRUCTURE_POLYNOMIALLIST_H

#include "../LISTARRA.h"

using namespace std;

class polynomialList {
private:
    LISTARRA *pol;

    memDir BuscarExponente(int exp);

    memDir BuscarTerminoN(int i);

public:
    polynomialList();

    bool esCero();

    int Grado();

    int coeficiente(int exp);

    void asignarCoeficiente(int coef, int exp);

    void poner_termino(int coef, int exp);

    int numero_terminos();

    int exponente(int term);

    void sumar(polynomialList p1, polynomialList p2);

    void restar(polynomialList p1, polynomialList p2);

    void multiplicar(polynomialList p1, polynomialList p2);

    void opuesto(polynomialList p1, polynomialList p2);

    void print();

    void derivar(polynomialList p1);
};

#endif //DATASTRUCTURE_POLYNOMIALLIST_H
