//
// Created by rogerroca on 26/10/2022.
//

#ifndef DATASTRUCTURE_POLYNOMIALPTR_H
#define DATASTRUCTURE_POLYNOMIALPTR_H

#include "string"

using namespace std;

struct polynomialNode {
    int coef;
    int exp;
    polynomialNode *nextNode;
};

typedef polynomialNode *dirP;

class polynomialPtr {
private:
    dirP firstPtr;
    int length;

    dirP findExp(int);

    dirP findTermN(int);

public:
    polynomialPtr();

    bool isZero();

    int getGrade();

    int getCoefficient(int exp);

    void setCoefficient(int coef, int exp);

    void setTerm(int coef, int exp);

    int getNumberOfTerms();

    int getExponent(int term);

    void print();

    void addition(polynomialPtr p1, polynomialPtr p2);

    void subtraction(polynomialPtr p1, polynomialPtr p2);

    void multiplication(polynomialPtr p1, polynomialPtr p2);

    void isOpposite(polynomialPtr p1, polynomialPtr p2);

    void rmTerm(dirP dir);
};


#endif //DATASTRUCTURE_POLYNOMIALPTR_H
