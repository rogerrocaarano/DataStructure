//
// Created by rogerroca on 16/1/2023.
//

#ifndef INF220_MATRIZDISPERSAPTR_H
#define INF220_MATRIZDISPERSAPTR_H


class matrizDispersaPtr {
    typedef int DATA_TYPE;
    struct MD_NODE {
        DATA_TYPE dato;
        int f;
        int c;
        MD_NODE *sig;
    };
    typedef MD_NODE *node_ptr;
private:
    int df; // Dimensión filas
    int dc; // Dimensión columnas
    int nt; // Términos
    DATA_TYPE repe; // es el elemento que se repetirá en la matriz
    node_ptr M_ptr; // puntero de la matriz

    node_ptr obtenerPosicion(int f, int c);

    void eliminar(node_ptr pos);

public:
    matrizDispersaPtr();

    void dimensionar(int m, int n);

    int dimension_fila();

    int dimension_columna();

    void poner(int f, int c, DATA_TYPE valor);

    DATA_TYPE elemento(int f, int c);

    void definir_valor_repetido(DATA_TYPE valor);

    void mostrar();
};


#endif //INF220_MATRIZDISPERSAPTR_H
