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

    int findExp(int exp);

    void rmTerm(int pos);

public:
    polynomialVector();

    bool isZero();

    int getGrade();

    int getCoefficient(int exp);

    void setCoefficient(int coef, int exp);

    void setTerm(int coef, int exp);

    int getNumberOfTerms();

    int getExponent(int term);

    void addition(polynomialVector p1, polynomialVector p2);

    void subtraction(polynomialVector p1, polynomialVector p2);

    void multiplication(polynomialVector p1, polynomialVector p2);

    void isOpposite(polynomialVector p1, polynomialVector p2);

    void print();

    void derive(polynomialVector p1);


};


#endif //DATASTRUCTURE_POLYNOMIALVECTOR_H
