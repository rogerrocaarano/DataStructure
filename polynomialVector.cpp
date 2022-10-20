//
// Created by rogerroca on 20/10/2022.
//

#include "polynomialVector.h"
#include "iostream"

using namespace std;

polynomialVector::polynomialVector() {
    length = 0;
    for (int i = 0; i < MAX_SIZE_POL_VECT; i++) {
        vExp[i] = 0;
        vCoef[i] = 0;
    }
}

bool polynomialVector::isZero() {
    return length == 0;
}

int polynomialVector::getGrade() {
    if (this->length > 0) {
        int grade = vExp[0];
        for (int i = 0; i <= length - 1; i++) {
            if (vExp[i] > grade) grade = vExp[i];
        }
        return grade;
    } else cout << "Polynomial is empty" << endl;
}

int polynomialVector::getCoefficient(int exp) {
    int pos = findExp(exp);
    if (pos != -1) {
        return vCoef[pos];
    } else cout << "Exponent not found." << endl;
}

void polynomialVector::setCoefficient(int coef, int exp) {
    int pos = findExp(exp);
    if (pos != -1) {
        if (coef == 0) {
            rmTerm(pos);
        } else vCoef[pos] = coef;
    }
}

void polynomialVector::setTerm(int coef, int exp) {
    int pos = findExp(exp);
    if (pos != -1) {
        vCoef[pos] = vCoef[pos] + coef;
    } else {
        if (length < MAX_SIZE_POL_VECT) {
            vExp[length] = exp;
            vCoef[length] = coef;
            length++;
        } else cout << "Not enough space for new term." << endl;
    }
}

int polynomialVector::getNumberOfTerms() {
    return length;
}

int polynomialVector::getExponent(int term) {
    if (term > 0 && term < length) {
        return vExp[term];
    } else cout << "Invalid position." << endl;
}

void polynomialVector::addition(polynomialVector p1, polynomialVector p2) {
    for (int i = 1; i <= p1.getNumberOfTerms(); i++) {
        int exp = p1.getExponent(i);
        int coef = p1.getCoefficient(exp);
        setTerm(coef, exp);
    }
    for (int i = 1; i <= p2.getNumberOfTerms(); i++) {
        int exp = p2.getExponent(i);
        int coef = p2.getCoefficient(exp);
        setTerm(coef, exp);
    }
}

void polynomialVector::subtraction(polynomialVector p1, polynomialVector p2) {
    for (int i = 1; i <= p1.getNumberOfTerms(); i++) {
        int exp = p1.getExponent(i);
        int coef = p1.getCoefficient(exp);
        setTerm(coef, exp);
    }
    for (int i = 1; i <= p1.getNumberOfTerms(); i++) {
        int exp = p2.getExponent(i);
        int coef = p2.getCoefficient(exp) * (-1);
        setTerm(coef, exp);
    }
}

void polynomialVector::multiplication(polynomialVector p1, polynomialVector p2) {
    for (int i = 1; i <= p1.getNumberOfTerms(); i++) {
        for (int j = 1; j <= p2.getNumberOfTerms(); j++) {
            int exp = p1.getExponent(i) + p2.getExponent(j);
            int coef = p1.getCoefficient(p1.getExponent(i))
                       * p2.getCoefficient(p2.getExponent(j));
            setTerm(coef, exp);
        }
    }
}

void polynomialVector::isOpposite(polynomialVector p1, polynomialVector p2) {
    addition(p1, p2);
    if (isZero()) {
        cout << "Son polinomios opuestos." << endl;
    } else {
        cout << "No son polinomios opuestos." << endl;
    }
}

void polynomialVector::print() {
    if (isZero()) {
        cout << "0" << endl;
    } else {
        for (int i = 0; i < length; i++) {
            if (i == 0) {
                if (vExp[i] == 0) cout << vCoef[i];
                else cout << vCoef[i] << "*x^" << vExp[i];
            } else {
                if (vExp[i] == 0) cout << "+" << vCoef[i];
                else cout << "+" << vCoef[i] << "*x^" << vExp[i];
            }
        }
        cout << endl;
    }
}

void polynomialVector::derive(polynomialVector p1) {
    for (int i = 1; i <= p1.getNumberOfTerms(); i++) {
        if (p1.getExponent(i) != 0) {
            int exp = p1.getExponent(i) - 1;
            int coef = p1.getCoefficient(p1.getExponent(i))
                       * p1.getExponent(i);
            setTerm(coef, exp);
        }
    }
}

int polynomialVector::findExp(int exp) {
    int pos = -1;
    int i = 0;
    while (pos == -1 && i <= length - 1) {
        if (vExp[i] == exp) {
            pos = i;
        }
        i++;
    }
    return pos;
}

void polynomialVector::rmTerm(int pos) {
    if (pos < length) {
        for (int i = pos; i < length - 1; i++) {
            vExp[i] = vExp[i + 1];
            vCoef[i] = vCoef[i + 1];
        }
        vExp[length - 1] = 0;
        vCoef[length - 1] = 0;
        length--;
    } else cout << "Invalid direction" << endl;
}

