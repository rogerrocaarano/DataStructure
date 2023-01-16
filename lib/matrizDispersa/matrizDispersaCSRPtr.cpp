//
// Created by rogerroca on 16/1/2023.
//

#include "matrizDispersaCSRPtr.h"
#include "iostream"

bool matrizDispersaCSRPtr::existe_elemento(matrizDispersaCSRPtr::ptr_nodoFil nodo_f,
                                           matrizDispersaCSRPtr::ptr_nodoCol nodo_c) {
    return (nodo_f != nullptr && nodo_c != nullptr);
}

matrizDispersaCSRPtr::ptr_nodoFil matrizDispersaCSRPtr::obtener_nodo_f(int f) {
    if (ptrFil == nullptr) {
        return nullptr;
    }
    ptr_nodoFil nodo_f = ptrFil;
    while (nodo_f->f != f) {
        if (nodo_f->f_sig == nullptr) {
            return nullptr;
        }
        nodo_f = nodo_f->f_sig;
    }

    return nodo_f;
}

matrizDispersaCSRPtr::ptr_nodoCol
matrizDispersaCSRPtr::obtener_nodo_c(matrizDispersaCSRPtr::ptr_nodoFil nodo_f, int c) {
    if (nodo_f == nullptr || nodo_f->PtrCol == nullptr) {
        return nullptr;
    }
    ptr_nodoCol nodo_c = nodo_f->PtrCol;
    while (nodo_c->c != c) {
        if (nodo_c->c_sig == nullptr) {
            return nullptr;
        }
        nodo_c = nodo_c->c_sig;
    }
    return nodo_c;
}

bool matrizDispersaCSRPtr::verificarRango(int f, int c) {
    // Verificar si los datos están dentro del rango de la matriz:
    if (f <= 0 || f > df) {
        std::cout << "Error: Fila fuera de rango." << std::endl;
        return false;
    }
    if (c <= 0 || c > dc) {
        std::cout << "Error: Columna fuera de rango." << std::endl;
        return false;
    }
    return true;
}

void matrizDispersaCSRPtr::eliminar(int f, int c) {
    ptr_nodoFil nodo_f = obtener_nodo_f(f);
    ptr_nodoCol nodo_c = obtener_nodo_c(nodo_f, c);
    if (!existe_elemento(nodo_f, nodo_c)) {
        return;
    }
    // Eliminar el nodo del elemento
    // Si es el único elemento en la fila se eliminará toda la fila:
    if (nodo_c == nodo_f->PtrCol && nodo_c->c_sig == nullptr) {
        delete nodo_c;
        ptr_nodoFil nodo_f_sig = nodo_f->f_sig;
        nodo_f_sig->f_ant = nodo_f->f_ant;
        if (nodo_f == ptrFil) {
            ptrFil = nodo_f_sig;
        }
        delete nodo_f;
        nt--;
        return;
    }
    // Si es el primer elemento en la fila:
    if (nodo_c == nodo_f->PtrCol) {
        nodo_f->PtrCol = nodo_c->c_sig;
    } else {
        ptr_nodoCol nodo_c_ant = nodo_f->PtrCol;
        while (nodo_c_ant->c_sig != nodo_c) {
            nodo_c_ant = nodo_c_ant->c_sig;
        }
        nodo_c_ant->c_sig = nodo_c->c_sig;
    }
    nt--;
    delete nodo_c;
}

matrizDispersaCSRPtr::matrizDispersaCSRPtr() {
    ptrFil = nullptr;
    df = 0;
    dc = 0;
    nt = 0;
    repe = 0;
}

void matrizDispersaCSRPtr::dimensionar(int m, int n) {
    df = m;
    dc = n;
}

int matrizDispersaCSRPtr::dimension_fila() {
    return df;
}

int matrizDispersaCSRPtr::dimension_columna() {
    return dc;
}

void matrizDispersaCSRPtr::poner(int f, int c, matrizDispersaCSRPtr::DATA_TYPE valor) {
    if (!verificarRango(f, c))
        return;
    // Determinar si existe un valor en f,c:
    ptr_nodoFil nodo_f = obtener_nodo_f(f);
    ptr_nodoCol nodo_c = obtener_nodo_c(nodo_f, c);
    if (existe_elemento(nodo_f, nodo_c)) {
        // Si se introduce el valor "repe" en alguno de los elementos ya existentes, el elemento debe ser eliminado:
        // Obtener la posición del elemento a eliminar y llamar al método eliminar(pos)
        if (valor != repe) {
            nodo_c->dato = valor;
        } else eliminar(f, c);
        return;
    }
    // Si no es un valor existente
    // Crear un nuevo nodo de columna
    nodo_c = new nodoCol;
    nodo_c->c = c;
    nodo_c->dato = valor;
    nodo_c->c_sig = nullptr;

    if (nodo_f != nullptr) { // Caso 1: Un valor nuevo para una fila ya existente.
        ptr_nodoCol aux = nodo_f->PtrCol;
        while (aux->c_sig != nullptr) {
            aux = aux->c_sig;
        }
        aux->c_sig = nodo_c;
    } else { // Caso 2: Un valor nuevo para una fila y columna nuevos.
        nodo_f = new nodoFil;
        nodo_f->PtrCol = nodo_c;
        nodo_f->f = f;
        nodo_f->f_sig = nullptr;
        if (ptrFil == nullptr) {
            ptrFil = nodo_f;
            nodo_f->f_ant = nullptr;
        } else {
            ptr_nodoFil aux = ptrFil;
            while (aux->f_sig != nullptr) {
                aux = aux->f_sig;
            }
            nodo_f->f_ant = aux;
            aux->f_sig = nodo_f;
        }
    }
    nt++;
}

matrizDispersaCSRPtr::DATA_TYPE matrizDispersaCSRPtr::elemento(int f, int c) {
    if (!verificarRango(f, c))
        return repe;
    ptr_nodoFil nodo_f = obtener_nodo_f(f);
    ptr_nodoCol nodo_c = obtener_nodo_c(nodo_f, c);
    if (nodo_f == nullptr || nodo_c == nullptr) {
        return repe;
    }
    return nodo_c->dato;
}

void matrizDispersaCSRPtr::definir_valor_repetido(matrizDispersaCSRPtr::DATA_TYPE valor) {
    // Eliminar los elementos de la matriz que coincidan con el nuevo valor para "repe"
    // y luego cambiar el valor en la estructura.
    for (int i = 1; i <= df; i++) {
        for (int j = 1; j <= dc; j++) {
            if (elemento(i, j) == valor)
                eliminar(i, j);
        }
    }
    repe = valor;
}

void matrizDispersaCSRPtr::mostrar() {
    for (int i = 1; i <= df; i++) {
        for (int j = 1; j <= dc; j++) {
            std::cout << "[" << elemento(i, j) << "]";
        }
        std::cout << std::endl;
    }
}
