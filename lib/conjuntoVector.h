//
// Created by rogerroca on 6/12/2022.
//

#ifndef INF220_CONJUNTOVECTOR_H
#define INF220_CONJUNTOVECTOR_H
/* Esta clase funciona de manera binaria, los elementos almacenados
 * únicamente pueden ser de tipo entero. */
const int MAX_SIZE = 100;

class conjuntoVector {
private:
    int V[MAX_SIZE];
    int size;
public:
    conjuntoVector();

    bool vacio();

    bool pertenece(int e);

    void inserta(int e);

    int cardinal();

    int ordinal(int e);

    void suprime(int e);

    int muestrea();

};


#endif //INF220_CONJUNTOVECTOR_H
