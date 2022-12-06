//
// Created by rogerroca on 20/10/2022.
//

#ifndef DATASTRUCTURE_POLINOMIOVECTORDOUBLE_H
#define DATASTRUCTURE_POLINOMIOVECTORDOUBLE_H


const int MAX_SIZE_POL_VECT_DOUBLE = 100;

class polinomioVectorDouble {
private:
    double vCoef[MAX_SIZE_POL_VECT_DOUBLE]{};
    int vExp[MAX_SIZE_POL_VECT_DOUBLE]{};
    int length;

    int BuscarExponente(int exp);

    void rmTerm(int pos);

public:
    polinomioVectorDouble();

    bool EsCero();

    int Grado();

    double coeficiente(int exp);

    void AsignarCoeficiente(double coef, int exp);

    void poner_termino(double coef, int exp);

    int numero_terminos();

    int exponente(int term);

    void sumar(polinomioVectorDouble p1, polinomioVectorDouble p2);

    void restar(polinomioVectorDouble p1, polinomioVectorDouble p2);

    void multiplicar(polinomioVectorDouble p1, polinomioVectorDouble p2);

    void opuesto(polinomioVectorDouble p1, polinomioVectorDouble p2);

    void print();

    void derivar(polinomioVectorDouble p1);

    double integrar(double a, double b, double dx);

    double eval(double x);


};


#endif //DATASTRUCTURE_POLINOMIOVECTORDOUBLE_H
