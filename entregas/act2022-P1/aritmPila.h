//
// Created by rogerroca on 18/12/2022.
//

#ifndef INF220_ARITMPILA_H
#define INF220_ARITMPILA_H


#include "pilaPtr.h"
#include "iostream"

class aritmPila {
private:
    pilaPtr Result;
//    pilaPtr Operandos;
    // La expresión vendrá de una entrada de tipo texto, en formato infijo.
    std::string exp;

    void evalExp();

    void evalExp(char c);

    bool esOperador(char c);

    void limpiarExp();

    int tipoExp();

    std::string inFijaToPostFija(std::string infija);

    int prioridadInfija(char c);

    int prioridadPila(char c);

    bool parentesisOk(std::string infija);

public:
    aritmPila();

    aritmPila(std::string consoleIn);
};


#endif //INF220_ARITMPILA_H
