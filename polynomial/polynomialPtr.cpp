//
// Created by rogerroca on 26/10/2022.
//

#include "polynomialPtr.h"
#include "iostream"

using namespace std;

dirP polynomialPtr::findExp(int exp) {
    dirP dir = firstPtr;
    if (dir != nullptr) {
        dirP expDir = nullptr;
        while (dir != nullptr && expDir == nullptr) {
            if (dir->exp == exp) {
                expDir = dir;
            } else dir = dir->nextNode;
        }
        return expDir;
    } else return nullptr;
}

dirP polynomialPtr::findTermN(int i) {
    dirP dir = firstPtr;
    int nt = 0;
    dirP termDir = nullptr;
    while (dir != nullptr && termDir == nullptr) {
        nt++;
        if (nt == i) {
            termDir = dir;
        } else dir = dir->nextNode;
    }
    return termDir;
}

polynomialPtr::polynomialPtr() {
    length = 0;
    firstPtr = nullptr;
}

bool polynomialPtr::isZero() {
    return length == 0;
}

int polynomialPtr::getGrade() {
    dirP dir = firstPtr;
    if (dir != nullptr) {
        int maxGrade = dir->exp;
        while (dir != nullptr) {
            if (dir->exp > maxGrade) {
                maxGrade = dir->exp;
            }
            dir = dir->nextNode;
        }
        return maxGrade;
    }
}

int polynomialPtr::getCoefficient(int exp) {
    dirP dir = findExp(exp);
    if (dir != nullptr) {
        return dir->coef;
    } else cout << "Not found." << endl;
}

void polynomialPtr::setCoefficient(int coef, int exp) {
    dirP dir = findExp(exp);
    if (dir != nullptr) {
        dir->coef = coef;
        if (coef == 0) {
            m->delSpace(dir);
        }
    } else cout << "Not found." << endl;
}

void polynomialPtr::setTerm(int coef, int exp) {
    dirP expDir = findExp(exp);
    if (expDir != nullptr) {
        coef = coef + expDir->coef;
        expDir->coef = coef;
        if (coef == 0) {
            if (length == 1) {
                firstPtr = nullptr;
                length = 0;
            } else if (firstPtr == expDir) {
                firstPtr = expDir->nextNode;
            } else {
                dirP previousDir = firstPtr;
                while (previousDir->nextNode != expDir)
                    previousDir = previousDir->nextNode;
                if (expDir->nextNode != nullptr)
                    previousDir->nextNode = expDir->nextNode;
                else previousDir->nextNode = nullptr;
            }
            length--;
        }
    } else {
        if (coef != 0) {
            dirP newTerm = new polynomialNode;
            newTerm->nextNode = firstPtr;
            newTerm->exp = exp;
            newTerm->coef = coef;
            firstPtr = newTerm;
            length++;
        }
    }
}

int polynomialPtr::getNumberOfTerms() {
    return length;
}

int polynomialPtr::getExponent(int term) {
    dirP dir = findTermN(term);
    if (dir != nullptr) {
        return dir->exp;
    } else cout << "Term not found" << endl;
}

void polynomialPtr::print() {
    cout << "P: ";
    dirP dir = firstPtr;
    int i = 1;
    while (i <= length) {
        if (i > 1 && dir->coef > 0) cout << "+";
        cout << dir->coef;
        if (dir->exp > 0) {
            cout << "x^" << dir->exp;
        }
        dir = dir->nextNode;
        i++;
    }
    cout << endl;
}

void polynomialPtr::addition(polynomialPtr p1, polynomialPtr p2) {
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

void polynomialPtr::subtraction(polynomialPtr p1, polynomialPtr p2) {
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

void polynomialPtr::multiplication(polynomialPtr p1, polynomialPtr p2) {
    for (int i = 1; i <= p1.getNumberOfTerms(); i++) {
        for (int j = 1; j <= p2.getNumberOfTerms(); j++) {
            int exp = p1.getExponent(i) + p2.getExponent(j);
            int coef = p1.getCoefficient(p1.getExponent(i))
                       * p2.getCoefficient(p2.getExponent(j));
            setTerm(coef, exp);
        }
    }
}

void polynomialPtr::isOpposite(polynomialPtr p1, polynomialPtr p2) {
    addition(p1, p2);
    if (isZero()) {
        cout << "Son polinomios opuestos." << endl;
    } else {
        cout << "No son polinomios opuestos." << endl;
    }
}
