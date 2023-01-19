//
// Created by rogerroca on 5/10/2022.
//

#include "listaSMemoria.h"
#include "iostream"

using namespace std;

namespace Ex {
    void emptyList() {
//        cout << "Empty List" << endl;
    }

    void incorrectDir() {
//        cout << "Incorrect Direction" << endl;
    }

    void lowMemSpace() {
//        cout << "Low memory space" << endl;
    }
}

listaSMemoria::listaSMemoria() {
    this->listMem = new SMemoria(); // Init simulated memory.
    length = 0;
    ptrDir = NULL_VALUE;
}

listaSMemoria::listaSMemoria(SMemoria *mem) {
    this->listMem = mem; // Use user input memory.
    length = 0;
    ptrDir = NULL_VALUE;
}

memDir listaSMemoria::fin() {
    memDir lastDir;
    if (vacia()) {
        Ex::emptyList();
    } else {
        memDir x = ptrDir;
        while (x != NULL_VALUE) {
            lastDir = x;
            x = listMem->obtenerDato(x, "->sig");
        }
        return lastDir;
    }
}

memDir listaSMemoria::primero() {
    if (vacia()) {
        Ex::emptyList();
    } else {
        return ptrDir;
    }
}

memDir listaSMemoria::siguiente(memDir dir) {
    if (vacia()) {
        Ex::emptyList();
        return NULL_VALUE;
    } else {
        if (dir == fin()) {
            /**
            * 17/10/2022 19:55
             * Added a return value for the exception.
            */
            Ex::incorrectDir();
            return NULL_VALUE;
        } else {
            return (listMem->obtenerDato(dir, "->sig"));
        }
    }
}

memDir listaSMemoria::anterior(memDir dir) {
    if (vacia()) {
        Ex::emptyList();
    } else {
        if (dir == primero()) {
            Ex::incorrectDir();
        } else {
            memDir x = ptrDir;
            memDir previousDir = NULL_VALUE;
            while (x != NULL_VALUE) {
                if (x == dir) {
                    return previousDir;
                }
                previousDir = x;
                x = listMem->obtenerDato(x, "->sig");
            }
            return previousDir;
        }
    }
}

bool listaSMemoria::vacia() {
    return !(length > 0);
}

int listaSMemoria::recupera(memDir dir) {
    if (vacia()) {
        Ex::emptyList();
    } else {
        return listMem->obtenerDato(dir, "->elem");
    }
}

int listaSMemoria::longitud() {
    return length;
}

void listaSMemoria::inserta(memDir dir, DATA_TYPE value) {
    /**
    * 17/10/2022 17:00
    * Added exception for empty lista
    **/
    if (this->vacia()) {
        inserta_primero(value);
    } else {
        memDir x = listMem->new_espacio("elem,sig"); // request new memory space.
        if (x != NULL_VALUE) {
            listMem->poner_dato(x, "->elem", value);
            listMem->poner_dato(x, "->sig", dir);
            if (vacia()) {
                ptrDir = x;
                length = 1;
            } else {
                length++;
                if (dir == primero()) {
                    listMem->poner_dato(x, "->sig", dir);
                    ptrDir = x;
                } else {
                    memDir prevDir = anterior(dir);
                    listMem->poner_dato(prevDir, "->sig", x);
                    listMem->poner_dato(x, "->sig", dir);
                }
            }
        } else {
            Ex::lowMemSpace();
        }
    }
}

void listaSMemoria::inserta_primero(DATA_TYPE value) {
    memDir x = listMem->new_espacio("elem,sig");
    if (x != NULL_VALUE) {
        listMem->poner_dato(x, "->elem", value);
        listMem->poner_dato(x, "->sig", ptrDir);
        length++;
        ptrDir = x;
    } else {
        Ex::lowMemSpace();
    }
}

void listaSMemoria::inserta_ultimo(DATA_TYPE value) {
    if (this->vacia()) {
        inserta_primero(value);
    } else {
        memDir x = listMem->new_espacio("elem,sig");
        if (x != NULL_VALUE) {
            listMem->poner_dato(x, "->elem", value);
            listMem->poner_dato(x, "->sig", NULL_VALUE);
            if (longitud() != NULL_VALUE) {
                listMem->poner_dato(fin(), "->sig", x);
            } else {
                ptrDir = x;
            }
            length++;
        } else {
            Ex::lowMemSpace();
        }
    }
}

void listaSMemoria::suprime(memDir dir) {
    if (vacia()) {
        Ex::emptyList();
    } else {
        if (dir == ptrDir) {
            memDir x = ptrDir;
            ptrDir = listMem->obtenerDato(ptrDir, "->sig");
            listMem->delete_espacio(x);
        } else {
            listMem->poner_dato(anterior(dir), "->sig", siguiente(dir));
            listMem->delete_espacio(dir);
        }
        length--;
    }
}

void listaSMemoria::modifica(memDir dir, DATA_TYPE value) {
    if (vacia()) {
        Ex::emptyList();
    } else {
        listMem->poner_dato(dir, "->elem", value);
    }
}

void listaSMemoria::mostrar() {
    cout << "L: ";
    memDir dir = ptrDir;
    int i = 1;
    while (i <= length) {
        cout << listMem->obtenerDato(dir, "->elem");
        if (i < length) {
            cout << " , ";
        }
        dir = listMem->obtenerDato(dir, "->sig");
        i++;
    }
    cout << endl;
}
