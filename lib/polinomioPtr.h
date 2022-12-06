//
// Created by rogerroca on 26/10/2022.
//

#ifndef DATASTRUCTURE_POLINOMIOPTR_H
#define DATASTRUCTURE_POLINOMIOPTR_H

#include "string"

using namespace std;

struct polynomialNode {
    int coef;
    int exp;
    polynomialNode *nextNode;
};

typedef polynomialNode *dirP;

class polinomioPtr {
private:
    dirP firstPtr;
    int length;

    dirP BuscarExponente(int exp);

    dirP BuscarTerminoN(int i);

public:
    polinomioPtr();

    bool EsCero();

    int Grado();

    int coeficiente(int exp);

    void AsignarCoeficiente(int coef, int exp);

    void poner_termino(int coef, int exp);

    int numero_terminos();

    int exponente(int term);

    void print();

    void sumar(polinomioPtr p1, polinomioPtr p2);

    void restar(polinomioPtr p1, polinomioPtr p2);

    void multiplicar(polinomioPtr p1, polinomioPtr p2);

    void Opuesto(polinomioPtr p1, polinomioPtr p2);

    void rmTerm(dirP dir);
};


#endif //DATASTRUCTURE_POLINOMIOPTR_H
