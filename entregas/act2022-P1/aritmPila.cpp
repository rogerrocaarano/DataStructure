//
// Created by rogerroca on 18/12/2022.
//

#include "aritmPila.h"
#include "cmath"

aritmPila::aritmPila() {
    std::cout << "Introducir expresión: ";
    std::cin >> exp;
    evalExp();
}

aritmPila::aritmPila(std::string consoleIn) {
    exp = consoleIn;
    evalExp();
}

void aritmPila::evalExp() {
    limpiarExp();
    if (tipoExp() == 0) {
        std::cout << "EXPRESION INFIJA: " << exp << std::endl;
        exp = inFijaToPostFija(exp);
    }
    std::cout << "EXPRESION POSTFIJA: " << exp << std::endl;
    std::string buffer = "";
    while (exp.length() > 0) {
        char c = exp.at(0);
        exp.erase(0, 1);
        if (!esOperador(c)) {
            if (c == ' ') {
                Result.meter(std::stod(buffer));
                buffer = "";
            } else {
                buffer = buffer + c;
            }
        } else {
            if (!buffer.empty()) {
                Result.meter(std::stod(buffer));
                buffer = "";
            }
            evalExp(c);
        }
    }
    std::cout << "Resultado: " << Result.cima() << std::endl;
}

bool aritmPila::esOperador(char c) {
    std::string operadores = "+-*/()^";
    return operadores.find(c) != -1;
}

void aritmPila::evalExp(char c) {
    double op1, op2;
    bool error = false;
    if (!Result.vacia()) {
        Result.sacar(op2);
    } else {
        error = true;
    }
    if (!Result.vacia()) {
        Result.sacar(op1);
    } else {
        error = true;
    }
    if (!error) {
        switch (c) {
            case '+':
                Result.meter(op1 + op2);
                break;
            case '-':
                Result.meter(op1 - op2);
                break;
            case '*':
                Result.meter(op1 * op2);
                break;
            case '/':
                Result.meter(op1 / op2);
                break;
            case '^':
                Result.meter(pow(op1, op2));
                break;
            default:
                std::cout << "Operador Inválido" << std::endl;
        }
    }
}

void aritmPila::limpiarExp() {
    // Limpiar espacios de más
    // Al principio y al final del string exp:
    if (exp.at(0) == ' ') {
        exp.erase(0, 1);
    }
    if (exp.at(exp.length() - 1) == ' ') {
        exp.erase(exp.length() - 1, 1);
    }
    int tipo = tipoExp();
    if (tipo > 0) {
        // Eliminar espacios dobles:
        int pos = 0;
        while (pos < exp.length() - 1) {
            if (exp[pos] == ' ' && exp[pos + 1] == ' ') {
                exp.erase(pos + 1, 1);
            } else {
                pos++;
            }
        }
    } else {
        // Eliminar todos los espacios:
        int pos = 0;
        while (pos < exp.length() - 1) {
            if (exp[pos] == ' ') {
                exp.erase(pos, 1);
            } else {
                pos++;
            }
        }
    }
}

int aritmPila::tipoExp() {
    // Si hay algún paréntesis en la expresión es de tipo infija:
    for (int i = 0; i < exp.length(); i++) {
        if (exp.at(i) == '(' || exp.at(i) == ')') {
            return 0; // Infija.
        }
    }
    if (esOperador(exp.at(0))) {
        return 1; // Prefija.
    }
    if (esOperador(exp.at(exp.length() - 1))) {
        return 2; // Postfija.
    }
    return 0; // Infija.
}

std::string aritmPila::inFijaToPostFija(std::string infija) {
    std::string postFija = "";
    if (!parentesisOk(infija)) {
        std::cout << "Error: verificar parentesis de la expresion" << std::endl;
        return postFija;
    }
    pilaPtr operadores;
    for (int i = 0; i < infija.length(); i++) {
        // obtener un caracter de la expresión:
        char c = infija[i];
        // Si es un operador, guardar en la pila:
        if (esOperador(c)) {
            // Si el operador es el parentesis de cierre ")"
            // sacar los operadores de la pila hasta encontrar el parentesis de apertura "(".
            if (c == ')') {
                double aux = c;
                while (aux != '(') {
                    operadores.sacar(aux);
                    if (aux != '(') {
                        postFija = postFija + char(aux);
                    }
                }
            }
            // evaluar la prioridad del operador, si es menor a la del anterior,
            // el anterior operador debe salir de la pila primero.
            if (c != '(' && prioridadInfija(c) < prioridadInfija(operadores.cima())) {
                double aux;
                operadores.sacar(aux);
                postFija = postFija + char(aux);
            }
            // No meter a la pila los paréntesis de cierre.
            if (c != ')') {
                operadores.meter(c);
            }
        } else {
            postFija = postFija + c;
            // Si el siguiente caracter es un operador, diferente de ")" añadir un espacio en blanco:
            if (infija[i + 1] != ')' && esOperador(infija[i + 1])) {
                postFija = postFija + ' ';
            }
        }
    }
    // Vaciar la pila de operadores:
    while (!operadores.vacia()) {
        double aux;
        operadores.sacar(aux);
        postFija = postFija + char(aux);
    }

}

int aritmPila::prioridadInfija(char c) {
    switch (c) {
        case '^':
            return 4;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
//        case '(':
//            return 5;
        default:
            return -1;
    }
}

int aritmPila::prioridadPila(char c) {
    switch (c) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        case '(':
            return 0;
        default:
            return -1;
    }
}

bool aritmPila::parentesisOk(std::string infija) {
    pilaPtr parentesis;
    for (int i = 0; i < infija.length(); i++) {
        if (infija[i] == '(') {
            parentesis.meter(infija[i]);
        }
        if (infija[i] == ')') {
            double aux;
            parentesis.sacar(aux);
        }
    }
    return parentesis.vacia();
}

