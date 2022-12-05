//
// Created by rogerroca on 26/10/2022.
//

#ifndef DATASTRUCTURE_POLYNOMIALPTR_H
#define DATASTRUCTURE_POLYNOMIALPTR_H

#include "string"

using namespace std;

struct polynomialNode {
    int coef;
    int exp;
    polynomialNode *nextNode;
};

typedef polynomialNode *dirP;

class polynomialPtr {
private:
    dirP firstPtr;
    int length;

    dirP BuscarExponente(int exp);

    dirP BuscarTerminoN(int i);

public:
    polynomialPtr();

    bool EsCero();

    int Grado();

    int coeficiente(int exp);

    void AsignarCoeficiente(int coef, int exp);

    void poner_termino(int coef, int exp);

    int numero_terminos();

    int exponente(int term);

    void print();

    void sumar(polynomialPtr p1, polynomialPtr p2);

    void restar(polynomialPtr p1, polynomialPtr p2);

    void multiplicar(polynomialPtr p1, polynomialPtr p2);

    void Opuesto(polynomialPtr p1, polynomialPtr p2);

    void rmTerm(dirP dir);
};


#endif //DATASTRUCTURE_POLYNOMIALPTR_H
