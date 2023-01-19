//
// Created by rogerroca on 15/1/2023.
//

#include "matrizDispersaSMemoria.h"
#include "iostream"

memDir matrizDispersaSMemoria::obtenerPosicion(int f, int c) {
    memDir dir = M_ptr;
    for (int i = 0; i < nt; i++) {
        if (mem.obtenerDato(dir, "->fila") == f && mem.obtenerDato(dir, "->col") == c) {
            return dir;
        }
        dir = mem.obtenerDato(dir, "->sig");
    }
    return NULL_VALUE;
}

void matrizDispersaSMemoria::eliminar(memDir pos) {
    if (pos >= nt || pos < 0) {
        std::cout << "Error: Posicion fuera de rango" << std::endl;
        return;
    }
    mem.delete_espacio(pos);

}

matrizDispersaSMemoria::matrizDispersaSMemoria() {
    df = 0;
    dc = 0;
    repe = 0;
    nt = 0;
    M_ptr = NULL_VALUE;
}

void matrizDispersaSMemoria::dimensionar(int m, int n) {
    df = m;
    dc = n;
}

int matrizDispersaSMemoria::dimension_fila() {
    return df;
}

int matrizDispersaSMemoria::dimension_columna() {
    return dc;
}

void matrizDispersaSMemoria::poner(int f, int c, matrizDispersaSMemoria::DATA_TYPE valor) {
    memDir pos = obtenerPosicion(f, c);
    if (pos >= 0) {
        // Asignamos el valor y si el valor es igual a "repe" hay que eliminarlo:
        mem.poner_dato(pos, "->dato", valor);
        if (valor == repe) {
            eliminar(pos);
        }
        return;
    }
    // No existe el valor en la matriz.
    // Crear un nuevo elemento:
    memDir dir = mem.new_espacio("data,fila,col,sig"); // Pedir espacio de memoria
    if (dir == NULL_VALUE) {
        std::cout << "Error: No existe suficiente espacio." << std::endl;
        return;
    }
    mem.poner_dato(dir, "->dato", valor);
    mem.poner_dato(dir, "->fila", f);
    mem.poner_dato(dir, "->col", c);
    mem.poner_dato(dir, "->sig", M_ptr);
    M_ptr = dir;
    nt++;
}

matrizDispersaSMemoria::DATA_TYPE matrizDispersaSMemoria::elemento(int f, int c) {
    if (f < 0 || f > df) {
        std::cout << "Error: Fila fuera de rango." << std::endl;
        return repe;
    }
    if (c < 0 || c > dc) {
        std::cout << "Error: Columna fuera de rango." << std::endl;
        return repe;
    }
    memDir pos = obtenerPosicion(f, c);
    return pos == -1 ? repe : mem.obtenerDato(pos, "->dato");
}

void matrizDispersaSMemoria::definir_valor_repetido(matrizDispersaSMemoria::DATA_TYPE valor) {
    // En tiempo de ejecución se eliminaría de la memoria
    // los valores coincidentes con el nuevo valor para "repe"
    int i = 0;
    memDir dir = M_ptr;
    while (i < nt) {
        if (mem.obtenerDato(dir, "->dato") == valor) {
            memDir aux = mem.obtenerDato(dir, "->sig");
            eliminar(dir);
            dir = aux;
            break;
        }
        i++;
    }
    // definir el nuevo valor para "repe"
    repe = valor;
}

void matrizDispersaSMemoria::mostrar() {
    for (int i = 1; i <= df; i++) {
        for (int j = 1; j <= dc; j++) {
            std::cout << "[" << elemento(i, j) << "]";
        }
        std::cout << std::endl;
    }
}
