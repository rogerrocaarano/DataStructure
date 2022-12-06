//
// Created by rogerroca on 6/10/2022.
//

#ifndef DATASTRUCTURE_POLINOMIOLISTASMEMORIA_H
#define DATASTRUCTURE_POLINOMIOLISTASMEMORIA_H

#include "listaSMemoria.h"

using namespace std;

class polinomioListaSMemoria {
private:
    listaSMemoria *pol;

    memDir BuscarExponente(int exp);

    memDir BuscarTerminoN(int i);

public:
    polinomioListaSMemoria();

    bool esCero();

    int Grado();

    int coeficiente(int exp);

    void asignarCoeficiente(int coef, int exp);

    void poner_termino(int coef, int exp);

    int numero_terminos();

    int exponente(int term);

    void sumar(polinomioListaSMemoria p1, polinomioListaSMemoria p2);

    void restar(polinomioListaSMemoria p1, polinomioListaSMemoria p2);

    void multiplicar(polinomioListaSMemoria p1, polinomioListaSMemoria p2);

    void opuesto(polinomioListaSMemoria p1, polinomioListaSMemoria p2);

    void print();

    void derivar(polinomioListaSMemoria p1);
};

#endif //DATASTRUCTURE_POLINOMIOLISTASMEMORIA_H
