//
// Created by rogerroca on 20/10/2022.
//

#include "polynomialSimRAM.h"
#include "iostream"

using namespace std;

memDir polynomialSimRAM::findExp(int exp) {
    memDir dir = ptrPol;
    if (dir != NULL_VALUE) {
        memDir expDir = NULL_VALUE;
        while (dir != NULL_VALUE && expDir == NULL_VALUE) {
            if (m->getData(dir, EXP) == exp) {
                expDir = dir;
            } else dir = m->getData(dir, NEXT_NODE);
        }
        return expDir;
    } else return NULL_VALUE;
}

memDir polynomialSimRAM::findTermN(int i) {
    memDir dir = ptrPol;
    int nt = 0;
    memDir termDir = NULL_VALUE;
    while (dir != NULL_VALUE && termDir == NULL_VALUE) {
        nt++;
        if (nt == i) {
            termDir = dir;
        } else dir = m->getData(dir, NEXT_NODE);
    }
    return termDir;
}

polynomialSimRAM::polynomialSimRAM() {
    this->m = new simRAM();
    length = 0;
    ptrPol = NULL_VALUE;
}

polynomialSimRAM::polynomialSimRAM(simRAM *mem) {
    this->m = mem;
    length = 0;
    ptrPol = NULL_VALUE;
}

bool polynomialSimRAM::isZero() {
    return length == 0;
}

int polynomialSimRAM::getGrade() {
    memDir dir = ptrPol;
    if (dir != NULL_VALUE) {
        int maxGrade = m->getData(dir, EXP);
        while (dir != NULL_VALUE) {
            if (m->getData(dir, EXP) > maxGrade) {
                maxGrade = m->getData(dir, EXP);
            }
            dir = m->getData(dir, NEXT_NODE);
        }
        return maxGrade;
    }
}

int polynomialSimRAM::getCoefficient(int exp) {
    memDir dir = findExp(exp);
    if (dir != NULL_VALUE) {
        return m->getData(dir, COEF);
    } else cout << "Not found." << endl;
}

void polynomialSimRAM::setCoefficient(int coef, int exp) {
    memDir dir = findExp(exp);
    if (dir != NULL_VALUE) {
        m->setData(dir, COEF, coef);
        if (coef == 0) {
            m->delSpace(dir);
        }
    } else cout << "Not found." << endl;
}

void polynomialSimRAM::setTerm(int coef, int exp) {
    memDir expDir = findExp(exp);
    if (expDir != NULL_VALUE) {
        coef = coef + m->getData(expDir, COEF);
        m->setData(expDir, COEF, coef);
        if (coef == 0) {
            m->delSpace(expDir);
            length--;
        }
    } else {
        if (coef != 0) {
            memDir newTerm = m->newSpace(POL_NODE);
            m->setData(newTerm, EXP, exp);
            m->setData(newTerm, COEF, coef);
            m->setData(newTerm, NEXT_NODE, ptrPol);
            ptrPol = newTerm;
            length++;
        }
    }
}

int polynomialSimRAM::getNumberOfTerms() {
    return length;
}

int polynomialSimRAM::getExponent(int term) {
    memDir dir = findTermN(term);
    if (dir != NULL_VALUE) {
        return m->getData(dir, EXP);
    } else cout << "Term not found" << endl;
}

void polynomialSimRAM::print() {
    cout << "P: ";
    memDir dir = ptrPol;
    int i = 1;
    while (i <= length) {
        if (i > 1 && m->getData(dir, COEF) > 0) cout << "+";
        cout << m->getData(dir, COEF);
        if (m->getData(dir, EXP) > 0) {
            cout << "x^" << m->getData(dir, EXP);
        }
        dir = m->getData(dir, NEXT_NODE);
        i++;
    }
    cout << endl;
}

void polynomialSimRAM::addition(polynomialSimRAM p1, polynomialSimRAM p2) {
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

void polynomialSimRAM::subtraction(polynomialSimRAM p1, polynomialSimRAM p2) {
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

void polynomialSimRAM::multiplication(polynomialSimRAM p1, polynomialSimRAM p2) {
    for (int i = 1; i <= p1.getNumberOfTerms(); i++) {
        for (int j = 1; j <= p2.getNumberOfTerms(); j++) {
            int exp = p1.getExponent(i) + p2.getExponent(j);
            int coef = p1.getCoefficient(p1.getExponent(i))
                       * p2.getCoefficient(p2.getExponent(j));
            setTerm(coef, exp);
        }
    }
}

void polynomialSimRAM::isOpposite(polynomialSimRAM p1, polynomialSimRAM p2) {
    addition(p1, p2);
    if (isZero()) {
        cout << "Son polinomios opuestos." << endl;
    } else {
        cout << "No son polinomios opuestos." << endl;
    }
}
