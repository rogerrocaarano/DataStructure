//
// Created by rogerroca on 6/10/2022.
//

#include "Polynomial.h"
#include "iostream"

using namespace std;

namespace Ex {
    void noTerms() {
        cout << "Polinomio no tiene términos" << endl;
    }

    void noGrade() {
        cout << "Polinomio no tiene ese término" << endl;
    }

    void termNotFound() {
        cout << "No existe ese número de término" << endl;
    }
}

memDir Polynomial::findExp(int exp) {
    memDir dir = pol->getNextDir(pol->getFirstDir());
    if (dir != NULL_VALUE) {
        memDir expDir = NULL_VALUE;
        while (dir != NULL_VALUE && expDir == NULL_VALUE) {
            if (pol->getValue(dir) == exp) {
                expDir = dir;
            }
            dir = pol->getNextDir(pol->getNextDir(dir));
        }
        return expDir;
    } else {
        Ex::noTerms();
        return NULL_VALUE;
    }
}

memDir Polynomial::findTermN(int i) {
    memDir dir = pol->getFirstDir();
    int nt = 0;
    if (dir != NULL_VALUE) {
        memDir termDir = NULL_VALUE;
        while (dir != NULL_VALUE && termDir == NULL_VALUE) {
            nt++;
            if (nt == i) {
                termDir = dir;
            }
            dir = pol->getNextDir(pol->getNextDir(dir));
        }
        return termDir;
    } else {
        Ex::noTerms();
    }
}

Polynomial::Polynomial() {
    // Init list.
    this->pol = new list();
}

bool Polynomial::isZero() {
    return pol->getLength() == 0;
}

int Polynomial::getGrade() {
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
        Ex::noTerms();
    }
}

int Polynomial::getCoefficient(int exp) {
    memDir dir = findExp(exp);
    if (dir != NULL_VALUE) {
        return pol->getValue(pol->getPreviousDir(dir));
    } else {
        Ex::noGrade();
    }
}

void Polynomial::setCoefficient(int coef, int exp) {
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

void Polynomial::setTerm(int coef, int exp) {
    /**
    * 7/10/2022 12:07
    * Added a condition for no terms in the polynomial.
    */
    if (!isZero()) {
        memDir expDir = findExp(exp);
        if (expDir != NULL_VALUE) {
            memDir coefDir = pol->getPreviousDir(expDir);
            pol->setItem(coefDir, pol->getValue(coefDir) + coef);
            if (pol->getValue(coefDir) == 0) {
                pol->delItem(expDir);
                pol->delItem(coefDir);
            } else {
                if (coef != 0) {
                    pol->insertItemLast(exp);
                    pol->insertItem(pol->getLastDir(), coef);
                }
            }
        }
    } else {
        if (coef != 0) {
            pol->insertItemFirst(exp); // No initial value, needs to initialise the list.
            pol->insertItem(pol->getLastDir(), coef);
        }
    }
//    memDir expDir = findExp(exp);
//    if (expDir != NULL_VALUE) {
//        memDir coefDir = pol->getPreviousDir(expDir);
//        pol->setItem(coefDir, pol->getValue(coefDir) + coef);
//        if (pol->getValue(coefDir) == 0) {
//            pol->delItem(expDir);
//            pol->delItem(coefDir);
//        } else {
//            if (coef != 0) {
//                pol->insertItemLast(exp);
//                pol->insertItem(pol->getLastDir(), coef);
//            }
//        }
//    }
}

int Polynomial::getNumberOfTerms() {
    return pol->getLength() / 2;
}

int Polynomial::getExponent(int term) {
    memDir dir = findTermN(term);
    if (dir != NULL_VALUE) {
        return pol->getValue(pol->getNextDir(dir));
    } else {
        Ex::termNotFound();
    }
}

void Polynomial::addition(Polynomial p1, Polynomial p2) {
    for (int i = 1; p1.getNumberOfTerms(); i++) {
        int exp = p1.findExp(i);
        int coef = p1.getCoefficient(exp);
        setTerm(coef, exp);
    }
    for (int i = 1; p2.getNumberOfTerms(); i++) {
        int exp = p2.findExp(i);
        int coef = p2.getCoefficient(exp);
        setTerm(coef, exp);
    }
}

void Polynomial::subtraction(Polynomial p1, Polynomial p2) {
    for (int i = 1; p1.getNumberOfTerms(); i++) {
        int exp = p1.findExp(i);
        int coef = p1.getCoefficient(exp);
        setTerm(coef, exp);
    }
    for (int i = 1; p2.getNumberOfTerms(); i++) {
        int exp = p2.findExp(i);
        int coef = p2.getCoefficient(exp) * (-1);
        setTerm(coef, exp);
    }
}

void Polynomial::multiplication(Polynomial p1, Polynomial p2) {
//todo Find how to do this.
}
