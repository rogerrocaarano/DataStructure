//
// Created by rogerroca on 6/10/2022.
//

#include "polynomialList.h"
#include "iostream"

using namespace std;

namespace Ex {
    void noTerm(int exp) {
//        cout << "No Term: exp=" << exp << endl;
    }

    void noGrade() {
//        cout << "No Term." << endl;
    }

    void termNotFound() {
//        cout << "Term not found." << endl;
    }
}

memDir polynomialList::findExp(int exp) {
    memDir dir = pol->getNextDir(pol->getFirstDir());
    if (dir != NULL_VALUE) {
        memDir expDir = NULL_VALUE;
        while (dir != NULL_VALUE && expDir == NULL_VALUE) {
            if (pol->getValue(dir) == exp) {
                expDir = dir;
            } else {
                dir = pol->getNextDir(pol->getNextDir(dir));
            }
        }
        return expDir;
    } else {
        Ex::noTerm(exp);
        return NULL_VALUE;
    }
}

memDir polynomialList::findTermN(int i) {
    memDir dir = pol->getFirstDir();
    int nt = 0;
    memDir termDir = NULL_VALUE;
    while (dir != NULL_VALUE && termDir == NULL_VALUE) {
        nt++;
        if (nt == i) {
            termDir = dir;
        } else {
            dir = pol->getNextDir(pol->getNextDir(dir));
        }
    }
    return termDir;
}

polynomialList::polynomialList() {
    // Init listSimRAM.
    this->pol = new listSimRAM();
}

bool polynomialList::isZero() {
    return pol->getLength() == 0;
}

int polynomialList::getGrade() {
    memDir dir = pol->getNextDir(pol->getFirstDir());
    if (dir != NULL_VALUE) {
        int maxGrade = pol->getValue(dir);
        while (dir != NULL_VALUE) {
            if (pol->getValue(dir) > maxGrade) {
                maxGrade = pol->getValue(dir);
            }
            dir = pol->getNextDir(dir);
        }
        return maxGrade;
    } else {
//        Ex::noTerm();
    }
}

int polynomialList::getCoefficient(int exp) {
    memDir dir = findExp(exp);
    if (dir != NULL_VALUE) {
        return pol->getValue(pol->getPreviousDir(dir));
    } else {
        Ex::noGrade();
    }
}

void polynomialList::setCoefficient(int coef, int exp) {
    memDir dir = findExp(exp);
    if (dir != NULL_VALUE) {
        memDir coefDir = pol->getPreviousDir(dir);
        pol->setItem(coefDir, coef);
        if (coef == 0) {
            pol->delItem(dir);
            pol->delItem(coefDir);
        }
    } else {
        Ex::noGrade();
    }
}

void polynomialList::setTerm(int coef, int exp) {
    memDir expDir = findExp(exp);
    if (expDir != NULL_VALUE) {
        memDir coefDir = pol->getPreviousDir(expDir);
        pol->setItem(coefDir, pol->getValue(coefDir) + coef);
        if (pol->getValue(coefDir) == 0) {
            pol->delItem(expDir);
            pol->delItem(coefDir);
        }
    } else {
        if (coef != 0) {
            pol->insertItemLast(coef);
            pol->insertItemLast(exp);
        }
    }
}

int polynomialList::getNumberOfTerms() {
    return pol->getLength() / 2;
}

int polynomialList::getExponent(int term) {
    memDir dir = findTermN(term);
    if (dir != NULL_VALUE) {
        return pol->getValue(pol->getNextDir(dir));
    } else {
        Ex::termNotFound();
    }
}

void polynomialList::addition(polynomialList p1, polynomialList p2) {
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

void polynomialList::subtraction(polynomialList p1, polynomialList p2) {
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

void polynomialList::multiplication(polynomialList p1, polynomialList p2) {
    for (int i = 1; i <= p1.getNumberOfTerms(); i++) {
        for (int j = 1; j <= p2.getNumberOfTerms(); j++) {
            int exp = p1.getExponent(i) + p2.getExponent(j);
            int coef = p1.getCoefficient(p1.getExponent(i))
                       * p2.getCoefficient(p2.getExponent(j));
            setTerm(coef, exp);
        }
    }
}

void polynomialList::isOpposite(polynomialList p1, polynomialList p2) {
    addition(p1, p2);
    if (isZero()) {
        cout << "Son polinomios opuestos." << endl;
    } else {
        cout << "No son polinomios opuestos." << endl;
    }
}

void polynomialList::print() {
    if (isZero()) {
        cout << "0" << endl;
    } else {
        for (int i = 1; i <= getNumberOfTerms(); i++) {
            int exp = getExponent(i);
            int coef = getCoefficient(exp);
            if (coef >= 0 && i > 1) {
                if (exp == 0) {
                    cout << "+" << coef;
                } else {
                    cout << "+" << coef << "*x^" << exp;
                }
            } else {
                if (exp == 0) {
                    cout << coef;
                } else {
                    cout << coef << "*x^" << exp;
                }
            }
        }
        cout << endl;
    }
}

void polynomialList::derive(polynomialList p1) {
    for (int i = 1; i <= p1.getNumberOfTerms(); i++) {
        if (p1.getExponent(i) != 0) {
            int exp = p1.getExponent(i) - 1;
            int coef = p1.getCoefficient(p1.getExponent(i))
                       * p1.getExponent(i);
            setTerm(coef, exp);
        }
    }
}
