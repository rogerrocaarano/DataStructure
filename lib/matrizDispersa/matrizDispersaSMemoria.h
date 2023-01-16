//
// Created by rogerroca on 15/1/2023.
//

#ifndef INF220_MATRIZDISPERSASMEMORIA_H
#define INF220_MATRIZDISPERSASMEMORIA_H

#include "../SMemoria.h"

class matrizDispersaSMemoria {
    typedef int DATA_TYPE;
    const string MD_DATA = "dato";
    const string MD_FILA = "fila";
    const string MD_COL = "col";
    const string NEXT_MD_ITEM_POINTER = "sig";
    const string MD_NODE = MD_DATA + ',' +
                           MD_FILA + ',' +
                           MD_COL + ',' +
                           NEXT_MD_ITEM_POINTER;
private:
    SMemoria mem;
    int df; // Dimensión filas
    int dc; // Dimensión columnas
    int nt; // Términos
    DATA_TYPE repe; // es el elemento que se repetirá en la matriz
    memDir M_ptr; // puntero de la matriz

    memDir obtenerPosicion(int f, int c);

    void eliminar(memDir pos);

public:
    matrizDispersaSMemoria();

    void dimensionar(int m, int n);

    int dimension_fila();

    int dimension_columna();

    void poner(int f, int c, DATA_TYPE valor);

    DATA_TYPE elemento(int f, int c);

    void definir_valor_repetido(DATA_TYPE valor);

    void mostrar();
};


#endif //INF220_MATRIZDISPERSASMEMORIA_H
