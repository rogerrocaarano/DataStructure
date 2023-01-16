//
// Created by rogerroca on 16/1/2023.
//

#ifndef INF220_MATRIZDISPERSACSRPTR_H
#define INF220_MATRIZDISPERSACSRPTR_H


class matrizDispersaCSRPtr {
    typedef int DATA_TYPE;
    struct nodoCol {
        int c; // Es el valor de la columna donde está el elemento
        DATA_TYPE dato;// Es el valor de elemento en la matriz
        nodoCol *c_sig;// Dirección del próximo elemento para otra columna
    };
    struct nodoFil {
        int f; // Indica la fila de la matriz
        nodoFil *f_sig; // indica la dirección del nodo que tiene la siguiente fila
        nodoFil *f_ant; // indica la dirección de nodo que tiene la anterior Fila
        nodoCol *PtrCol; // contiene los datos de la columna y elemento
    };
    typedef nodoCol *ptr_nodoCol;
    typedef nodoFil *ptr_nodoFil;
private:
    // Variables globales:
    ptr_nodoFil ptrFil;
    int df; // Dimensión filas
    int dc; // Dimensión columnas
    int nt; // Términos
    DATA_TYPE repe; // es el elemento que se repetirá en la matriz

    // Métodos privados:

    bool existe_elemento(ptr_nodoFil nodo_f, ptr_nodoCol nodo_c);

    ptr_nodoFil obtener_nodo_f(int f);

    ptr_nodoCol obtener_nodo_c(ptr_nodoFil nodo_f, int c);

    bool verificarRango(int f, int c);

    void eliminar(int f, int c);

public:

    matrizDispersaCSRPtr();

    void dimensionar(int m, int n);

    int dimension_fila();

    int dimension_columna();

    void poner(int f, int c, DATA_TYPE valor);

    DATA_TYPE elemento(int f, int c);

    void definir_valor_repetido(DATA_TYPE valor);

    void mostrar();
};


#endif //INF220_MATRIZDISPERSACSRPTR_H
