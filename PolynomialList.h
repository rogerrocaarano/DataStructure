//
// Created by rogerroca on 6/10/2022.
//

#ifndef RAMSIMULATOR_POLYNOMIALLIST_H
#define RAMSIMULATOR_POLYNOMIALLIST_H

#include "listSimRAM.h"

using namespace std;

class PolynomialList {
private:
    listSimRAM *pol;

    memDir findExp(int);

    memDir findTermN(int);

public:
    PolynomialList();

    bool isZero();

    int getGrade();

    int getCoefficient(int exp);

    void setCoefficient(int coef, int exp);

    void setTerm(int coef, int exp);

    int getNumberOfTerms();

    int getExponent(int term);

    void addition(PolynomialList p1, PolynomialList p2);

    void subtraction(PolynomialList p1, PolynomialList p2);

    void multiplication(PolynomialList p1, PolynomialList p2);

    void isOpposite(PolynomialList p1, PolynomialList p2);

    void print();
};

#endif //RAMSIMULATOR_POLYNOMIALLIST_H
