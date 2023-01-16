//
// Created by rogerroca on 16/1/2023.
//

#include "matrizDispersaPtr.h"
#include "iostream"

matrizDispersaPtr::node_ptr matrizDispersaPtr::obtenerPosicion(int f, int c) {
    node_ptr e_ptr = M_ptr;
    for (int i = 0; i < nt; i++) {
        if (e_ptr->f == f && e_ptr->c == c) {
            return e_ptr;
        }
        e_ptr = e_ptr->sig;
    }
    return nullptr;
}

void matrizDispersaPtr::eliminar(matrizDispersaPtr::node_ptr pos) {
    if (pos == nullptr) {
        std::cout << "Error: Posicion fuera de rango" << std::endl;
        return;
    }
    if (pos == M_ptr) {
        M_ptr = pos->sig;
        delete pos;
        return;
    }
    matrizDispersaPtr::node_ptr _pos = M_ptr;
    while (_pos->sig != pos)
        _pos = _pos->sig;
    _pos->sig = pos->sig;
    delete pos;
}

matrizDispersaPtr::matrizDispersaPtr() {
    df = 0;
    dc = 0;
    repe = 0;
    nt = 0;
    M_ptr = nullptr;
}

void matrizDispersaPtr::dimensionar(int m, int n) {
    df = m;
    dc = n;
}

int matrizDispersaPtr::dimension_fila() {
    return df;
}

int matrizDispersaPtr::dimension_columna() {
    return dc;
}

void matrizDispersaPtr::poner(int f, int c, matrizDispersaPtr::DATA_TYPE valor) {
    matrizDispersaPtr::node_ptr pos = obtenerPosicion(f, c);
    if (pos != nullptr) {
        // Asignamos el valor y si el valor es igual a "repe" hay que eliminarlo:
        pos->dato = valor;
        if (valor == repe) {
            eliminar(pos);
        }
        return;
    }
    // No existe el valor en la matriz.
    // Crear un nuevo elemento:
    auto newNode = new MD_NODE;
    newNode->dato = valor;
    newNode->f = f;
    newNode->c = c;
    newNode->sig = M_ptr;
    M_ptr = newNode;
    nt++;
}

matrizDispersaPtr::DATA_TYPE matrizDispersaPtr::elemento(int f, int c) {
    if (f < 0 || f > df) {
        std::cout << "Error: Fila fuera de rango." << std::endl;
        return repe;
    }
    if (c < 0 || c > dc) {
        std::cout << "Error: Columna fuera de rango." << std::endl;
        return repe;
    }
    matrizDispersaPtr::node_ptr pos = obtenerPosicion(f, c);
    return pos == nullptr ? repe : pos->dato;
}

void matrizDispersaPtr::definir_valor_repetido(matrizDispersaPtr::DATA_TYPE valor) {
    // En tiempo de ejecución se eliminarán
    // los valores coincidentes con el nuevo valor para "repe"
    int i = 0;
    matrizDispersaPtr::node_ptr node = M_ptr;
    while (i < nt) {
        if (node->dato == valor) {
            matrizDispersaPtr::node_ptr aux = node->sig;
            eliminar(node);
            node = aux;
            break;
        }
        i++;
    }
    // definir el nuevo valor para "repe"
    repe = valor;
}

void matrizDispersaPtr::mostrar() {
    for (int i = 1; i <= df; i++) {
        for (int j = 1; j <= dc; j++) {
            std::cout << "[" << elemento(i, j) << "]";
        }
        std::cout << std::endl;
    }
}
