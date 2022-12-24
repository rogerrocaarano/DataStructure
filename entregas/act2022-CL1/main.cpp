//
// Created by rogerroca on 23/12/2022.
//
#include "iostream"
#include "colaPrioridad.h"

std::string consoleUserInput;
int menuSelection;
int nroColas = 0;

bool esNumero(char c) {
    std::string num = "1234567890";
    return num.find(c) != -1;
}

bool validUserInput(std::string &str) {
    if (str.empty())
        return false;
    for (char c: str) {
        if (!esNumero(c))
            return false;
    }
    return true;
}

namespace interfaz {
    void inicio() {
        std::cout << "COLA DE PRIORIDAD" << std::endl;
        std::cout << "1. Poner elemento." << std::endl;
        std::cout << "2. Sacar elemento." << std::endl;
        std::cout << "0. Salir." << std::endl;

        consoleUserInput = "";
        while (!validUserInput(consoleUserInput)) {
            std::cout << "Seleccione una opcion: ";
            std::getline(cin, consoleUserInput);
            std::cout << std::endl;
        }
        menuSelection = std::stod(consoleUserInput);
    }

    void ponerElemento_Cola() {
        int cola = 0;
        while (cola < 1 || cola > nroColas) {
            consoleUserInput = "";
            std::cout << "Seleccionar una cola de 1 a " << nroColas << std::endl;
            while (!validUserInput(consoleUserInput)) {
                std::cout << "Cola: ";
                std::getline(cin, consoleUserInput);
                std::cout << std::endl;
            }
            cola = std::stod(consoleUserInput);
        }
    }

    void ponerElemento_Elemento() {
        consoleUserInput = "";
        while (!validUserInput(consoleUserInput)) {
            std::cout << "Elemento a ingresar: ";
            std::getline(cin, consoleUserInput);
            std::cout << std::endl;
        }
    }

    void sacarElemento(int e) {
        std::cout << "Elemento sacado: " << e << std::endl;
    }

}

int main() {
    // Inicializar las colas:
    std::cout << "CREAR COLAS" << std::endl;
    // Solicitar cantidad de colas.
    while (nroColas < 2) {
        consoleUserInput = "";
        std::cout << "Se requieren al menos 2 colas." << std::endl;
        while (!validUserInput(consoleUserInput)) {
            std::cout << "Nro. de colas: ";
            std::getline(cin, consoleUserInput);
            std::cout << std::endl;
            if (validUserInput(consoleUserInput)) {
                nroColas = std::stod(consoleUserInput);
            }
        }
    }
    // Llamar al constructor de cola de prioridad.
    auto CP = ColaPrioridad(nroColas);
    // Solicitar las frecuencias para las colas.
    for (int i = 1; i <= nroColas; i++) {
        int f = 0;
        while (f < 1) {
            consoleUserInput = "";
            while (!validUserInput(consoleUserInput)) {
                std::cout << "Frecuencia para la cola " << i << ": ";
                std::getline(cin, consoleUserInput);
                std::cout << std::endl;
                if (validUserInput(consoleUserInput)) {
                    f = std::stod(consoleUserInput);
                }
            }
        }
        CP.asignar_frec_prioridad(f, i);
    }

    bool exitCall = false;
    while (!exitCall) {
        std::cout << CP.to_str();
        interfaz::inicio();
        switch (menuSelection) {
            case 0:
                exitCall = true;
                break;
            case 1:
                std::cout << "PONER ELEMENTO" << std::endl;
                int cola;
                int e;
                interfaz::ponerElemento_Cola();
                cola = std::stod(consoleUserInput);
                interfaz::ponerElemento_Elemento();
                e = std::stod(consoleUserInput);
                CP.poner(e, cola);
                break;
            case 2:
                int elemSacado;
                if (CP.vacia()) {
                    std::cout << "La cola esta vacia." << std::endl;
                } else {
                    CP.sacar(elemSacado);
                    interfaz::sacarElemento(elemSacado);
                }
                break;
            default:
                std::cout << "Seleccion incorrecta." << std::endl;
                break;
        }
    }
    return 0;
}