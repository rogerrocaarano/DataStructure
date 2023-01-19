//
// Created by rogerroca on 16/1/2023.
//

#ifndef INF220_MATRIZDISPERSACSRSMEMORIA_H
#define INF220_MATRIZDISPERSACSRSMEMORIA_H

#include "../SMemoria.h"

class matrizDispersaCSRSMemoria {
    typedef int DATA_TYPE;

private:
    // Variables globales:
    memDir ptrFil;
    int df; // Dimensión filas
    int dc; // Dimensión columnas
    int nt; // Términos
    DATA_TYPE repe; // es el elemento que se repetirá en la matriz
    SMemoria mem; // Memoria simulada
    // Métodos privados:

    bool existe_elemento(memDir nodo_f, memDir nodo_c);

    memDir obtener_nodo_f(int f);

    memDir obtener_nodo_c(memDir nodo_f, int c);

    bool verificarRango(int f, int c);

    void eliminar(int f, int c);

public:

    matrizDispersaCSRSMemoria();

    void dimensionar(int m, int n);

    int dimension_fila();

    int dimension_columna();

    void poner(int f, int c, DATA_TYPE valor);

    DATA_TYPE elemento(int f, int c);

    void definir_valor_repetido(DATA_TYPE valor);

    void mostrar();
};


#endif //INF220_MATRIZDISPERSACSRSMEMORIA_H
