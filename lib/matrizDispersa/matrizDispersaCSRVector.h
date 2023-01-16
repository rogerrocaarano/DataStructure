//
// Created by rogerroca on 15/12/2022.
//

#ifndef INF220_MATRIZDISPERSACSRVECTOR_H
#define INF220_MATRIZDISPERSACSRVECTOR_H

const int MAX_VECTOR_SIZE = 100;

class matrizDispersaCSRVector {
    typedef int DATA_TYPE;
private:
    int Vf[MAX_VECTOR_SIZE]; // Filas
    int Vc[MAX_VECTOR_SIZE]; // Columnas
    DATA_TYPE Vd[MAX_VECTOR_SIZE];  // elementos
    int df; // Dimensión filas
    int dc; // Dimensión columnas
    int nt; // Términos
    DATA_TYPE repe; // es el elemento que se repetirá en la matriz

    int existe_elemento(int f, int c);

    int donde_insertar(int f, int c);

    bool verificarRango(int f, int c);

    void eliminar(int f, int c);

public:
    matrizDispersaCSRVector();

    void dimensionar(int m, int n);

    int dimension_fila();

    int dimension_columna();

    void poner(int f, int c, DATA_TYPE valor);

    DATA_TYPE elemento(int f, int c);

    void definir_valor_repetido(DATA_TYPE valor);

    void mostrar();
};


#endif //INF220_MATRIZDISPERSACSRVECTOR_H
