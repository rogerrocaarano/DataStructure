//
// Created by rogerroca on 20/10/2022.
//

#include "POLINOMIORRA.h"
#include "iostream"

using namespace std;

memDir POLINOMIORRA::BuscarExponente(int exp) {
    memDir dir = ptrPol;
    if (dir != NULL_VALUE) {
        memDir expDir = NULL_VALUE;
        while (dir != NULL_VALUE && expDir == NULL_VALUE) {
            if (m->obtenerDato(dir, EXP) == exp) {
                expDir = dir;
            } else dir = m->obtenerDato(dir, NEXT_NODE);
        }
        return expDir;
    } else return NULL_VALUE;
}

memDir POLINOMIORRA::BuscarTerminoN(int i) {
    memDir dir = ptrPol;
    int nt = 0;
    memDir termDir = NULL_VALUE;
    while (dir != NULL_VALUE && termDir == NULL_VALUE) {
        nt++;
        if (nt == i) {
            termDir = dir;
        } else dir = m->obtenerDato(dir, NEXT_NODE);
    }
    return termDir;
}

POLINOMIORRA::POLINOMIORRA() {
    this->m = new MEMRRA();
    length = 0;
    ptrPol = NULL_VALUE;
}

POLINOMIORRA::POLINOMIORRA(MEMRRA *mem) {
    this->m = mem;
    length = 0;
    ptrPol = NULL_VALUE;
}

bool POLINOMIORRA::EsCero() {
    return length == 0;
}

int POLINOMIORRA::Grado() {
    memDir dir = ptrPol;
    if (dir != NULL_VALUE) {
        int maxGrade = m->obtenerDato(dir, EXP);
        while (dir != NULL_VALUE) {
            if (m->obtenerDato(dir, EXP) > maxGrade) {
                maxGrade = m->obtenerDato(dir, EXP);
            }
            dir = m->obtenerDato(dir, NEXT_NODE);
        }
        return maxGrade;
    }
}

int POLINOMIORRA::coeficiente(int exp) {
    memDir dir = BuscarExponente(exp);
    if (dir != NULL_VALUE) {
        return m->obtenerDato(dir, COEF);
    } else cout << "Not found." << endl;
}

void POLINOMIORRA::AsignarCoeficiente(int coef, int exp) {
    memDir dir = BuscarExponente(exp);
    if (dir != NULL_VALUE) {
        m->poner_dato(dir, COEF, coef);
        if (coef == 0) {
            m->delete_espacio(dir);
        }
    } else cout << "Not found." << endl;
}

void POLINOMIORRA::poner_termino(int coef, int exp) {
    memDir expDir = BuscarExponente(exp);
    if (expDir != NULL_VALUE) {
        coef = coef + m->obtenerDato(expDir, COEF);
        m->poner_dato(expDir, COEF, coef);
        if (coef == 0) {
            m->delete_espacio(expDir);
            length--;
        }
    } else {
        if (coef != 0) {
            memDir newTerm = m->new_espacio(POL_NODE);
            m->poner_dato(newTerm, EXP, exp);
            m->poner_dato(newTerm, COEF, coef);
            m->poner_dato(newTerm, NEXT_NODE, ptrPol);
            ptrPol = newTerm;
            length++;
        }
    }
}

int POLINOMIORRA::numero_terminos() {
    return length;
}

int POLINOMIORRA::exponente(int term) {
    memDir dir = BuscarTerminoN(term);
    if (dir != NULL_VALUE) {
        return m->obtenerDato(dir, EXP);
    } else cout << "Term not found" << endl;
}

void POLINOMIORRA::mostrar() {
    cout << "P: ";
    memDir dir = ptrPol;
    int i = 1;
    while (i <= length) {
        if (i > 1 && m->obtenerDato(dir, COEF) > 0) cout << "+";
        cout << m->obtenerDato(dir, COEF);
        if (m->obtenerDato(dir, EXP) > 0) {
            cout << "x^" << m->obtenerDato(dir, EXP);
        }
        dir = m->obtenerDato(dir, NEXT_NODE);
        i++;
    }
    cout << endl;
}

void POLINOMIORRA::sumar(POLINOMIORRA p1, POLINOMIORRA p2) {
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

void POLINOMIORRA::restar(POLINOMIORRA p1, POLINOMIORRA p2) {
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

void POLINOMIORRA::multiplicar(POLINOMIORRA p1, POLINOMIORRA p2) {
    for (int i = 1; i <= p1.numero_terminos(); i++) {
        for (int j = 1; j <= p2.numero_terminos(); j++) {
            int exp = p1.exponente(i) + p2.exponente(j);
            int coef = p1.coeficiente(p1.exponente(i))
                       * p2.coeficiente(p2.exponente(j));
            poner_termino(coef, exp);
        }
    }
}

void POLINOMIORRA::Opuesto(POLINOMIORRA p1, POLINOMIORRA p2) {
    sumar(p1, p2);
    if (EsCero()) {
        cout << "Son polinomios opuestos." << endl;
    } else {
        cout << "No son polinomios opuestos." << endl;
    }
}
