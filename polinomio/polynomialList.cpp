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

memDir polynomialList::BuscarExponente(int exp) {
    memDir dir = pol->siguiente(pol->primero());
    if (dir != NULL_VALUE) {
        memDir expDir = NULL_VALUE;
        while (dir != NULL_VALUE && expDir == NULL_VALUE) {
            if (pol->recupera(dir) == exp) {
                expDir = dir;
            } else {
                dir = pol->siguiente(pol->siguiente(dir));
            }
        }
        return expDir;
    } else {
        Ex::noTerm(exp);
        return NULL_VALUE;
    }
}

memDir polynomialList::BuscarTerminoN(int i) {
    memDir dir = pol->primero();
    int nt = 0;
    memDir termDir = NULL_VALUE;
    while (dir != NULL_VALUE && termDir == NULL_VALUE) {
        nt++;
        if (nt == i) {
            termDir = dir;
        } else {
            dir = pol->siguiente(pol->siguiente(dir));
        }
    }
    return termDir;
}

polynomialList::polynomialList() {
    // Init LISTARRA.
    this->pol = new LISTARRA();
}

bool polynomialList::esCero() {
    return pol->longitud() == 0;
}

int polynomialList::Grado() {
    memDir dir = pol->siguiente(pol->primero());
    if (dir != NULL_VALUE) {
        int maxGrade = pol->recupera(dir);
        while (dir != NULL_VALUE) {
            if (pol->recupera(dir) > maxGrade) {
                maxGrade = pol->recupera(dir);
            }
            dir = pol->siguiente(dir);
        }
        return maxGrade;
    } else {
//        Ex::noTerm();
    }
}

int polynomialList::coeficiente(int exp) {
    memDir dir = BuscarExponente(exp);
    if (dir != NULL_VALUE) {
        return pol->recupera(pol->anterior(dir));
    } else {
        Ex::noGrade();
    }
}

void polynomialList::asignarCoeficiente(int coef, int exp) {
    memDir dir = BuscarExponente(exp);
    if (dir != NULL_VALUE) {
        memDir coefDir = pol->anterior(dir);
        pol->modifica(coefDir, coef);
        if (coef == 0) {
            pol->suprime(dir);
            pol->suprime(coefDir);
        }
    } else {
        Ex::noGrade();
    }
}

void polynomialList::poner_termino(int coef, int exp) {
    memDir expDir = BuscarExponente(exp);
    if (expDir != NULL_VALUE) {
        memDir coefDir = pol->anterior(expDir);
        pol->modifica(coefDir, pol->recupera(coefDir) + coef);
        if (pol->recupera(coefDir) == 0) {
            pol->suprime(expDir);
            pol->suprime(coefDir);
        }
    } else {
        if (coef != 0) {
            pol->inserta_ultimo(coef);
            pol->inserta_ultimo(exp);
        }
    }
}

int polynomialList::numero_terminos() {
    return pol->longitud() / 2;
}

int polynomialList::exponente(int term) {
    memDir dir = BuscarTerminoN(term);
    if (dir != NULL_VALUE) {
        return pol->recupera(pol->siguiente(dir));
    } else {
        Ex::termNotFound();
    }
}

void polynomialList::sumar(polynomialList p1, polynomialList p2) {
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

void polynomialList::restar(polynomialList p1, polynomialList p2) {
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

void polynomialList::multiplicar(polynomialList p1, polynomialList p2) {
    for (int i = 1; i <= p1.numero_terminos(); i++) {
        for (int j = 1; j <= p2.numero_terminos(); j++) {
            int exp = p1.exponente(i) + p2.exponente(j);
            int coef = p1.coeficiente(p1.exponente(i))
                       * p2.coeficiente(p2.exponente(j));
            poner_termino(coef, exp);
        }
    }
}

void polynomialList::opuesto(polynomialList p1, polynomialList p2) {
    sumar(p1, p2);
    if (esCero()) {
        cout << "Son polinomios opuestos." << endl;
    } else {
        cout << "No son polinomios opuestos." << endl;
    }
}

void polynomialList::print() {
    if (esCero()) {
        cout << "0" << endl;
    } else {
        for (int i = 1; i <= numero_terminos(); i++) {
            int exp = exponente(i);
            int coef = coeficiente(exp);
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

void polynomialList::derivar(polynomialList p1) {
    for (int i = 1; i <= p1.numero_terminos(); i++) {
        if (p1.exponente(i) != 0) {
            int exp = p1.exponente(i) - 1;
            int coef = p1.coeficiente(p1.exponente(i))
                       * p1.exponente(i);
            poner_termino(coef, exp);
        }
    }
}
