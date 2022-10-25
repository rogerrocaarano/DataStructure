//
// Created by rogerroca on 20/10/2022.
//

#ifndef DATASTRUCTURE_POLYNOMIALSIMRAM_H
#define DATASTRUCTURE_POLYNOMIALSIMRAM_H

#include "simRAM.h"

const string COEF = "P:coef";
const string EXP = "P:exp";
const string NEXT_NODE = "P:next";

const string POL_NODE = COEF + ',' + EXP + ',' + NEXT_NODE;

class polynomialSimRAM {
private:
    simRAM *m;
    memDir ptrPol;
    int length;

    memDir findExp(int);

    memDir findTermN(int);

public:
    polynomialSimRAM();

    polynomialSimRAM(simRAM *mem);

    bool isZero();

    int getGrade();

    int getCoefficient(int exp);

    void setCoefficient(int coef, int exp);

    void setTerm(int coef, int exp);

    int getNumberOfTerms();

    int getExponent(int term);

    void show();
};


#endif //DATASTRUCTURE_POLYNOMIALSIMRAM_H
