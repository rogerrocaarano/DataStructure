//
// Created by rogerroca on 20/10/2022.
//

#ifndef DATASTRUCTURE_POLYNOMIALVECTORDOUBLE_H
#define DATASTRUCTURE_POLYNOMIALVECTORDOUBLE_H


const int MAX_SIZE_POL_VECT_DOUBLE = 100;

class polynomialVectorDouble {
private:
    double vCoef[MAX_SIZE_POL_VECT_DOUBLE]{};
    int vExp[MAX_SIZE_POL_VECT_DOUBLE]{};
    int length;

    int BuscarExponente(int exp);

    void rmTerm(int pos);

public:
    polynomialVectorDouble();

    bool EsCero();

    int Grado();

    double coeficiente(int exp);

    void AsignarCoeficiente(double coef, int exp);

    void poner_termino(double coef, int exp);

    int numero_terminos();

    int exponente(int term);

    void sumar(polynomialVectorDouble p1, polynomialVectorDouble p2);

    void restar(polynomialVectorDouble p1, polynomialVectorDouble p2);

    void multiplicar(polynomialVectorDouble p1, polynomialVectorDouble p2);

    void opuesto(polynomialVectorDouble p1, polynomialVectorDouble p2);

    void print();

    void derivar(polynomialVectorDouble p1);

    double integrar(double a, double b, double dx);

    double eval(double x);


};


#endif //DATASTRUCTURE_POLYNOMIALVECTORDOUBLE_H
