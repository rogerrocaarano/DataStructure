//
// Created by rogerroca on 20/10/2022.
//

#ifndef DATASTRUCTURE_POLYNOMIALVECTOR_H
#define DATASTRUCTURE_POLYNOMIALVECTOR_H

const int MAX_SIZE_POL_VECT = 100;

class polynomialVector {
private:
    int vCoef[MAX_SIZE_POL_VECT]{};
    int vExp[MAX_SIZE_POL_VECT]{};
    int length;

    int BuscarExponente(int exp);

    void rmTerm(int pos);

public:
    polynomialVector();

    bool EsCero();

    int Grado();

    int coeficiente(int exp);

    void AsignarCoeficiente(int coef, int exp);

    void poner_termino(int coef, int exp);

    int numero_terminos();

    int exponente(int term);

    void sumar(polynomialVector p1, polynomialVector p2);

    void restar(polynomialVector p1, polynomialVector p2);

    void multiplicar(polynomialVector p1, polynomialVector p2);

    void Opuesto(polynomialVector p1, polynomialVector p2);

    void print();

    void derivar(polynomialVector p1);


};


#endif //DATASTRUCTURE_POLYNOMIALVECTOR_H
