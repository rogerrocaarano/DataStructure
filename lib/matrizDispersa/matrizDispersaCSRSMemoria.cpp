//
// Created by rogerroca on 16/1/2023.
//

#include "matrizDispersaCSRSMemoria.h"
#include "iostream"

bool matrizDispersaCSRSMemoria::existe_elemento(memDir nodo_f, memDir nodo_c) {
    return (nodo_f != NULL_VALUE && nodo_c != NULL_VALUE);
}

memDir matrizDispersaCSRSMemoria::obtener_nodo_f(int f) {
    if (ptrFil == NULL_VALUE) {
        return NULL_VALUE;
    }
    memDir nodo_f = ptrFil;
    while (mem.obtenerDato(nodo_f, "->f") != f) {
        if (mem.obtenerDato(nodo_f, "->f_sig") == NULL_VALUE) {
            return NULL_VALUE;
        }
        nodo_f = mem.obtenerDato(nodo_f, "->f_sig");
    }
    return nodo_f;
}

memDir matrizDispersaCSRSMemoria::obtener_nodo_c(memDir nodo_f, int c) {
    if (nodo_f == NULL_VALUE || mem.obtenerDato(nodo_f, "->PtrCol") == NULL_VALUE) {
        return NULL_VALUE;
    }
    memDir nodo_c = mem.obtenerDato(nodo_f, "->PtrCol");
    while (mem.obtenerDato(nodo_c, "->c") != c) {
        if (mem.obtenerDato(nodo_c, "->c_sig") == NULL_VALUE) {
            return NULL_VALUE;
        }
        nodo_c = mem.obtenerDato(nodo_c, "->c_sig");
    }
    return nodo_c;
}

bool matrizDispersaCSRSMemoria::verificarRango(int f, int c) {
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

void matrizDispersaCSRSMemoria::eliminar(int f, int c) {
    memDir nodo_f = obtener_nodo_f(f);
    memDir nodo_c = obtener_nodo_c(nodo_f, c);
    if (!existe_elemento(nodo_f, nodo_c)) {
        return;
    }
    // Eliminar el nodo del elemento
    // Si es el único elemento en la fila se eliminará toda la fila:
    if (nodo_c == mem.obtenerDato(nodo_f, "->PtrCol")
        && mem.obtenerDato(nodo_c, "->c_sig") == NULL_VALUE) {
        mem.delete_espacio(nodo_c);
        memDir nodo_f_sig = mem.obtenerDato(nodo_f, "->f_sig");
        mem.poner_dato(nodo_f_sig, "->f_ant", mem.obtenerDato(nodo_f, "->f_ant"));
        if (nodo_f == ptrFil) {
            ptrFil = nodo_f_sig;
        }
        mem.delete_espacio(nodo_f);
        nt--;
        return;
    }
    // Si es el primer elemento en la fila:
    if (nodo_c == mem.obtenerDato(nodo_f, "->PtrCol")) {
        mem.poner_dato(nodo_f, "->PtrCol", mem.obtenerDato(nodo_c, "->c_sig"));
    } else {
        memDir nodo_c_ant = mem.obtenerDato(nodo_f, "->PtrCol");
        while (mem.obtenerDato(nodo_c_ant, "->c_sig") != nodo_c) {
            nodo_c_ant = mem.obtenerDato(nodo_c_ant, "->c_sig");
        }
        mem.poner_dato(nodo_c_ant, "->c_sig", mem.obtenerDato(nodo_c, "->c_sig"));
    }
    nt--;
    mem.delete_espacio(nodo_c);
}

matrizDispersaCSRSMemoria::matrizDispersaCSRSMemoria() {
    ptrFil = NULL_VALUE;
    df = 0;
    dc = 0;
    nt = 0;
    repe = 0;
}

void matrizDispersaCSRSMemoria::dimensionar(int m, int n) {
    df = m;
    dc = n;
}

int matrizDispersaCSRSMemoria::dimension_fila() {
    return df;
}

int matrizDispersaCSRSMemoria::dimension_columna() {
    return dc;
}

void matrizDispersaCSRSMemoria::poner(int f, int c, matrizDispersaCSRSMemoria::DATA_TYPE valor) {
    if (!verificarRango(f, c))
        return;
    // Determinar si existe un valor en f,c:
    memDir nodo_f = obtener_nodo_f(f);
    memDir nodo_c = obtener_nodo_c(nodo_f, c);
    if (existe_elemento(nodo_f, nodo_c)) {
        // Si se introduce el valor "repe" en alguno de los elementos ya existentes, el elemento debe ser eliminado:
        // Obtener la posición del elemento a eliminar y llamar al método eliminar(pos)
        if (valor != repe) {
            mem.poner_dato(nodo_c, "->dato", valor);
        } else eliminar(f, c);
        return;
    }
    // Si no es un valor existente
    // Crear un nuevo nodo de columna
    nodo_c = mem.new_espacio("dato,c,c_sig");
    if (nodo_c == NULL_VALUE) return;
    mem.poner_dato(nodo_c, "->c", c);
    mem.poner_dato(nodo_c, "->dato", valor);
    mem.poner_dato(nodo_c, "->c_sig", NULL_VALUE);
    if (nodo_f != NULL_VALUE) { // Caso 1: Un valor nuevo para una fila ya existente.
        memDir aux = mem.obtenerDato(nodo_f, "->PtrCol");
        while (mem.obtenerDato(aux, "->c_sig") != NULL_VALUE) {
            aux = mem.obtenerDato(aux, "->c_sig");
        }
        mem.poner_dato(aux, "->c_sig", nodo_c);
    } else { // Caso 2: Un valor nuevo para una fila y columna nuevos.
        nodo_f = mem.new_espacio("f,f_sig,f_ant,PtrCol");
        mem.poner_dato(nodo_f, "->PtrCol", nodo_c);
        mem.poner_dato(nodo_f, "->f", f);
        mem.poner_dato(nodo_f, "->f_sig", NULL_VALUE);
        if (ptrFil == NULL_VALUE) {
            ptrFil = nodo_f;
            mem.poner_dato(nodo_f, "->f_ant", NULL_VALUE);
        } else {
            memDir aux = ptrFil;
            while (mem.obtenerDato(aux, "->f_sig") != NULL_VALUE) {
                aux = mem.obtenerDato(aux, "->f_sig");
            }
            mem.poner_dato(nodo_f, "->f_ant", aux);
            mem.poner_dato(aux, "->f_sig", nodo_f);
        }
    }
    nt++;
}

matrizDispersaCSRSMemoria::DATA_TYPE matrizDispersaCSRSMemoria::elemento(int f, int c) {
    if (!verificarRango(f, c))
        return repe;
    memDir nodo_f = obtener_nodo_f(f);
    memDir nodo_c = obtener_nodo_c(nodo_f, c);
    if (nodo_f == NULL_VALUE || nodo_c == NULL_VALUE) {
        return repe;
    }
    return mem.obtenerDato(nodo_c, "->dato");
}

void matrizDispersaCSRSMemoria::definir_valor_repetido(matrizDispersaCSRSMemoria::DATA_TYPE valor) {
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

void matrizDispersaCSRSMemoria::mostrar() {
    for (int i = 1; i <= df; i++) {
        for (int j = 1; j <= dc; j++) {
            std::cout << "[" << elemento(i, j) << "]";
        }
        std::cout << std::endl;
    }
}
