//
// Created by rogerroca on 6/10/2022.
//

#ifndef RAMSIMULATOR_POLYNOMIAL_H
#define RAMSIMULATOR_POLYNOMIAL_H

#include "list.h"

using namespace std;

class Polynomial {
private:
    list *pol;

    memDir findExp(int);

    memDir findTermN(int);

public:
    Polynomial();

    bool isZero();

    int getGrade();

    int getCoefficient(int exp);

    void setCoefficient(int coef, int exp);

    void setTerm(int coef, int exp);

    int getNumberOfTerms();

    int getExponent(int term);

    void addition(Polynomial p1, Polynomial p2);

    void subtraction(Polynomial p1, Polynomial p2);

    void multiplication(Polynomial p1, Polynomial p2);
};

#endif //RAMSIMULATOR_POLYNOMIAL_H
