//
// Created by rogerroca on 6/10/2022.
//

#ifndef DATASTRUCTURE_POLYNOMIALLIST_H
#define DATASTRUCTURE_POLYNOMIALLIST_H

#include "../list/listSimRAM.h"

using namespace std;

class polynomialList {
private:
    listSimRAM *pol;

    memDir findExp(int);

    memDir findTermN(int);

public:
    polynomialList();

    bool isZero();

    int getGrade();

    int getCoefficient(int exp);

    void setCoefficient(int coef, int exp);

    void setTerm(int coef, int exp);

    int getNumberOfTerms();

    int getExponent(int term);

    void addition(polynomialList p1, polynomialList p2);

    void subtraction(polynomialList p1, polynomialList p2);

    void multiplication(polynomialList p1, polynomialList p2);

    void isOpposite(polynomialList p1, polynomialList p2);

    void print();

    void derive(polynomialList p1);
};

#endif //DATASTRUCTURE_POLYNOMIALLIST_H
