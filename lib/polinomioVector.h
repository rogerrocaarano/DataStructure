//
// Created by rogerroca on 20/10/2022.
//

#ifndef DATASTRUCTURE_POLINOMIOVECTOR_H
#define DATASTRUCTURE_POLINOMIOVECTOR_H

const int MAX_SIZE_POL_VECT = 100;

class polinomioVector {
private:
    int vCoef[MAX_SIZE_POL_VECT]{};
    int vExp[MAX_SIZE_POL_VECT]{};
    int length;

    int BuscarExponente(int exp);

    void rmTerm(int pos);

public:
    polinomioVector();

    bool EsCero();

    int Grado();

    int coeficiente(int exp);

    void AsignarCoeficiente(int coef, int exp);

    void poner_termino(int coef, int exp);

    int numero_terminos();

    int exponente(int term);

    void sumar(polinomioVector p1, polinomioVector p2);

    void restar(polinomioVector p1, polinomioVector p2);

    void multiplicar(polinomioVector p1, polinomioVector p2);

    void Opuesto(polinomioVector p1, polinomioVector p2);

    void print();

    void derivar(polinomioVector p1);


};


#endif //DATASTRUCTURE_POLINOMIOVECTOR_H
