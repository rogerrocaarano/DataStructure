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

    int findExp(int exp);

    void rmTerm(int pos);

public:
    polynomialVectorDouble();

    bool isZero();

    int getGrade();

    double getCoefficient(int exp);

    void setCoefficient(double coef, int exp);

    void setTerm(double coef, int exp);

    int getNumberOfTerms();

    int getExponent(int term);

    void addition(polynomialVectorDouble p1, polynomialVectorDouble p2);

    void subtraction(polynomialVectorDouble p1, polynomialVectorDouble p2);

    void multiplication(polynomialVectorDouble p1, polynomialVectorDouble p2);

    void isOpposite(polynomialVectorDouble p1, polynomialVectorDouble p2);

    void print();

    void derive(polynomialVectorDouble p1);

    double integral(double a, double b, double dx);

    double eval(double x);


};


#endif //DATASTRUCTURE_POLYNOMIALVECTORDOUBLE_H
