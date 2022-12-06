//
// Created by rogerroca on 18/10/2022.
//

#include "listaVector.h"
#include "iostream"

using namespace std;

listaVector::listaVector() {
    list = new DATA_TYPE[MAX_VECTOR_SIZE];
    this->length = 0;
}

dirV listaVector::fin() {
    if (!vacia()) {
        return length - 1;
    } else {
        return NULL_VALUE;
    }
}

dirV listaVector::primero() {
    if (!vacia()) {
        return 0;
    } else {
        return NULL_VALUE;
    }
}

dirV listaVector::siguiente(dirV dir) {
    if (vacia()) {
        return NULL_VALUE;
    } else {
        if (dir >= 0 && dir < length - 1) {
            return dir + 1;
        } else {
            return NULL_VALUE;
        }
    }
}

dirV listaVector::anterior(dirV dir) {
    if (vacia()) {
        return -1;
    } else {
        if (dir > 0 && dir <= length - 1) {
            return dir - 1;
        } else {
            return NULL_VALUE;
        }
    }
}

bool listaVector::vacia() {
    return length == 0;
}

int listaVector::recupera(dirV dir) {
    if (vacia()) {
    } else {
        if (dir >= 0 && dir <= length - 1) {
            return list[dir];
        } else {
        }
    }
}

int listaVector::longitud() {
    return length;
}

void listaVector::inserta(dirV dir, DATA_TYPE value) {
    if (length == MAX_VECTOR_SIZE) {
        cout << "lista::inserta->La lista está llena." << endl;
        return;
    } else {
        if (dir >= 0 && dir <= length - 1) {
            length++;
            for (int i = length - 1; i > dir; i--) {
                list[i] = list[i - 1];
            }
            list[dir] = value;
        } else {
            cout << "lista::inserta->Dirección inválida." << endl;
            return;
        }
    }
}

void listaVector::inserta_primero(DATA_TYPE value) {
    if (vacia()) {
        list[0] = value;
        length = 1;
    } else {
        inserta(0, value);
    }
}

void listaVector::inserta_ultimo(DATA_TYPE value) {
    if (length == MAX_VECTOR_SIZE) {
        cout << "lista::inserta_ultimo->La lista está llena." << endl;
    } else {
        length++;
        list[length - 1] = value;
    }
}

void listaVector::suprime(dirV dir) {
    if (length == MAX_VECTOR_SIZE) {
        cout << "lista::suprime->La lista está llena." << endl;
        return;
    } else {
        if (dir >= 0 && dir <= length - 1) {
            for (int i = dir; i <= length - 2; i++) {
                list[i] = list[i + 1];
            }
            length--;
        } else {
            cout << "lista::suprime->Dirección inválida." << endl;
            return;
        }
    }
}

void listaVector::modifica(dirV dir, DATA_TYPE value) {
    if (vacia()) {
        cout << "lista::modifica->La lista está vacía." << endl;
        return;
    } else {
        if (dir >= 0 && dir <= length - 1) {
            list[dir] = value;
        } else {
            cout << "lista::modifica->Dirección inválida." << endl;
            return;
        }
    }
}

void listaVector::print() {
    if (vacia()) {
        cout << "lista::print->La lista está vacía." << endl;
    } else {
        cout << "List: ";
        for (int i = 0; i <= length - 1; i++) {
            if (i == length - 1) {
                cout << list[i] << endl;
            } else {
                cout << list[i] << " , ";
            }
        }
    }
}
