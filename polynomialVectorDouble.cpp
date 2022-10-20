//
// Created by rogerroca on 20/10/2022.
//

#include "polynomialVectorDouble.h"
#include "iostream"
#include "cmath"

using namespace std;

polynomialVectorDouble::polynomialVectorDouble() {
    length = 0;
    for (int i = 0; i < MAX_SIZE_POL_VECT_DOUBLE; i++) {
        vExp[i] = 0;
        vCoef[i] = 0;
    }
}

bool polynomialVectorDouble::isZero() {
    return length == 0;
}

int polynomialVectorDouble::getGrade() {
    if (this->length > 0) {
        int grade = vExp[0];
        for (int i = 0; i <= length - 1; i++) {
            if (vExp[i] > grade) grade = vExp[i];
        }
        return grade;
    } else cout << "Polynomial is empty" << endl;
}

double polynomialVectorDouble::getCoefficient(int exp) {
    int pos = findExp(exp);
    if (pos != -1) {
        return vCoef[pos];
    } else cout << "Exponent not found." << endl;
}

void polynomialVectorDouble::setCoefficient(double coef, int exp) {
    int pos = findExp(exp);
    if (pos != -1) {
        if (coef == 0) {
            rmTerm(pos);
        } else vCoef[pos] = coef;
    }
}

void polynomialVectorDouble::setTerm(double coef, int exp) {
    int pos = findExp(exp);
    if (pos != -1) {
        vCoef[pos] = vCoef[pos] + coef;
        if (vCoef[pos] == 0) rmTerm(pos);
    } else {
        if (length < MAX_SIZE_POL_VECT_DOUBLE) {
            vExp[length] = exp;
            vCoef[length] = coef;
            length++;
        } else cout << "Not enough space for new term." << endl;
    }
}

int polynomialVectorDouble::getNumberOfTerms() {
    return length;
}

int polynomialVectorDouble::getExponent(int term) {
    if (term > 0 && term <= length) {
        return vExp[term - 1];
    } else cout << "Invalid position." << endl;
}

void polynomialVectorDouble::addition(polynomialVectorDouble p1, polynomialVectorDouble p2) {
    for (int i = 1; i <= p1.getNumberOfTerms(); i++) {
        int exp = p1.getExponent(i);
        double coef = p1.getCoefficient(exp);
        setTerm(coef, exp);
    }
    for (int i = 1; i <= p2.getNumberOfTerms(); i++) {
        int exp = p2.getExponent(i);
        double coef = p2.getCoefficient(exp);
        setTerm(coef, exp);
    }
}

void polynomialVectorDouble::subtraction(polynomialVectorDouble p1, polynomialVectorDouble p2) {
    for (int i = 1; i <= p1.getNumberOfTerms(); i++) {
        int exp = p1.getExponent(i);
        double coef = p1.getCoefficient(exp);
        setTerm(coef, exp);
    }
    for (int i = 1; i <= p1.getNumberOfTerms(); i++) {
        int exp = p2.getExponent(i);
        double coef = p2.getCoefficient(exp) * (-1);
        setTerm(coef, exp);
    }
}

void polynomialVectorDouble::multiplication(polynomialVectorDouble p1, polynomialVectorDouble p2) {
    for (int i = 1; i <= p1.getNumberOfTerms(); i++) {
        for (int j = 1; j <= p2.getNumberOfTerms(); j++) {
            int exp = p1.getExponent(i) + p2.getExponent(j);
            double coef = p1.getCoefficient(p1.getExponent(i))
                          * p2.getCoefficient(p2.getExponent(j));
            setTerm(coef, exp);
        }
    }
}

void polynomialVectorDouble::isOpposite(polynomialVectorDouble p1, polynomialVectorDouble p2) {
    addition(p1, p2);
    if (isZero()) {
        cout << "Son polinomios opuestos." << endl;
    } else {
        cout << "No son polinomios opuestos." << endl;
    }
}

void polynomialVectorDouble::print() {
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

void polynomialVectorDouble::derive(polynomialVectorDouble p1) {
    for (int i = 1; i <= p1.getNumberOfTerms(); i++) {
        if (p1.getExponent(i) != 0) {
            int exp = p1.getExponent(i) - 1;
            int coef = p1.getCoefficient(p1.getExponent(i))
                       * p1.getExponent(i);
            setTerm(coef, exp);
        }
    }
}

int polynomialVectorDouble::findExp(int exp) {
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

void polynomialVectorDouble::rmTerm(int pos) {
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

double polynomialVectorDouble::integral(double a, double b, double dx) {
    if (b > a) {
        double area = 0;
        double y;
        while ((a + dx) < b) {
            y = eval((a + dx) / 2);
            y = abs(y);
            area = area + y * dx;
            a = a + dx;
        }
        y = eval((b - a) / 2);
        y = abs(y);
        area = area + y * ((b - a) / 2);
        return area;
    } else cout << "Invalid range.";
}

double polynomialVectorDouble::eval(double x) {
    double y = 0;
    for (int i = 1; i <= length; i++) {
        int exp = getExponent(i);
        double coef = getCoefficient(exp);
        double term = coef * pow(x, exp);
        y = y + term;
    }
    return y;
}
