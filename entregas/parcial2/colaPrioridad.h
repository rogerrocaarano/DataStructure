#ifndef UColaPrioridadH
#define UColaPrioridadH

#include <iostream>
#include <string>
#include "colaSMemoria.h"


using namespace std;


class ColaPrioridadRRA {
private:
    colaSMemoria *vc;
    int *vf;
    int cola_act;
    int cant;
    int maxColas;

public:
    ColaPrioridadRRA();

    ColaPrioridadRRA(int colas);

    ColaPrioridadRRA(SMemoria *memoria);

    bool vacia();

    int primero();

    void poner(int e, int prior);

    void sacar(int &e);

    void asignar_frec_prioridad(int frec, int prior);

    string to_str();
};

#endif
