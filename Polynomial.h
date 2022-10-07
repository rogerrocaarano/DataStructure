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

    int getCoefficient(int);

    void setCoefficient(int, int);

    void setTerm(int, int);

    int getNumberOfTerms();

    int getExponent(int);

    void addition(Polynomial, Polynomial);

    void subtraction(Polynomial, Polynomial);

    void multiplication(Polynomial, Polynomial);
};

#endif //RAMSIMULATOR_POLYNOMIAL_H
