//
// Created by rogerroca on 26/10/2022.
//

#include "polinomioPtr.h"
#include "iostream"

using namespace std;

dirP polinomioPtr::BuscarExponente(int exp) {
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

dirP polinomioPtr::BuscarTerminoN(int i) {
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

polinomioPtr::polinomioPtr() {
    length = 0;
    firstPtr = nullptr;
}

bool polinomioPtr::EsCero() {
    return length == 0;
}

int polinomioPtr::Grado() {
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

int polinomioPtr::coeficiente(int exp) {
    dirP dir = BuscarExponente(exp);
    if (dir != nullptr) {
        return dir->coef;
    } else cout << "Not found." << endl;
}

void polinomioPtr::AsignarCoeficiente(int coef, int exp) {
    dirP dir = BuscarExponente(exp);
    if (dir != nullptr) {
        dir->coef = coef;
        if (coef == 0) {
            rmTerm(dir);
        }
    } else cout << "Not found." << endl;
}

void polinomioPtr::poner_termino(int coef, int exp) {
    dirP expDir = BuscarExponente(exp);
    if (expDir != nullptr) {
        coef = coef + expDir->coef;
        expDir->coef = coef;
        if (coef == 0) {
            rmTerm(expDir);
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

int polinomioPtr::numero_terminos() {
    return length;
}

int polinomioPtr::exponente(int term) {
    dirP dir = BuscarTerminoN(term);
    if (dir != nullptr) {
        return dir->exp;
    } else cout << "Term not found" << endl;
}

void polinomioPtr::print() {
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

void polinomioPtr::sumar(polinomioPtr p1, polinomioPtr p2) {
    for (int i = 1; i <= p1.numero_terminos(); i++) {
        int exp = p1.exponente(i);
        int coef = p1.coeficiente(exp);
        poner_termino(coef, exp);
    }
    for (int i = 1; i <= p2.numero_terminos(); i++) {
        int exp = p2.exponente(i);
        int coef = p2.coeficiente(exp);
        poner_termino(coef, exp);
    }
}

void polinomioPtr::restar(polinomioPtr p1, polinomioPtr p2) {
    for (int i = 1; i <= p1.numero_terminos(); i++) {
        int exp = p1.exponente(i);
        int coef = p1.coeficiente(exp);
        poner_termino(coef, exp);
    }
    for (int i = 1; i <= p1.numero_terminos(); i++) {
        int exp = p2.exponente(i);
        int coef = p2.coeficiente(exp) * (-1);
        poner_termino(coef, exp);
    }
}

void polinomioPtr::multiplicar(polinomioPtr p1, polinomioPtr p2) {
    for (int i = 1; i <= p1.numero_terminos(); i++) {
        for (int j = 1; j <= p2.numero_terminos(); j++) {
            int exp = p1.exponente(i) + p2.exponente(j);
            int coef = p1.coeficiente(p1.exponente(i))
                       * p2.coeficiente(p2.exponente(j));
            poner_termino(coef, exp);
        }
    }
}

void polinomioPtr::Opuesto(polinomioPtr p1, polinomioPtr p2) {
    sumar(p1, p2);
    if (EsCero()) {
        cout << "Son polinomios opuestos." << endl;
    } else {
        cout << "No son polinomios opuestos." << endl;
    }
}

void polinomioPtr::rmTerm(dirP dir) {
    if (length > 0) {
        if (dir == firstPtr) {
            if (length == 1) firstPtr = nullptr;
            else firstPtr = dir;
        } else {
            dirP previousDir = firstPtr;
            while (previousDir->nextNode != dir) {
                previousDir = previousDir->nextNode;
            }
            previousDir->nextNode = dir->nextNode;
        }
        length--;
    } else cout << "Invalid dir." << endl;

}
