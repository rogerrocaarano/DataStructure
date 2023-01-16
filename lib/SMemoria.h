//
// Created by rogerroca on 4/10/2022.
//

#ifndef DATASTRUCTURE_MEMRRA_H
#define DATASTRUCTURE_SMEMORIA_H

#include "string"

using namespace std;

const int MAX_MEM_SPACE = 100;
const int NULL_VALUE = -1;

// Define a structure than represents a memory node
typedef int memDir;
struct NodoM {
    int Dato;
    string id;
    memDir link;
};


class SMemoria {
private:
    NodoM mem[MAX_MEM_SPACE];
    memDir libre; // Next available memory node.
public:
    SMemoria();

    memDir new_espacio(const string &cadena_id);

    void delete_espacio(memDir dir);

    void poner_dato(memDir dir, const string &cadena_id, int dataValue);

    int obtenerDato(memDir dir, const string &cadena_id);

    int Espacio_Disponible();

    int Espacio_ocupado();

    bool dir_libre(memDir dir);

    void mostrar();
};


#endif //DATASTRUCTURE_MEMRRA_H
