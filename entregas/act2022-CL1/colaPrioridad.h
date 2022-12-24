// ---------------------------------------------------------------------------

#ifndef UColaPrioridadH
#define UColaPrioridadH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
//#include "Funciones.h"
//#include "UColaL.h"
#include "diColaPtr.h"
//#include "UColaV3.h"

using namespace std;

//const int MAX_CL = 3;

class ColaPrioridad {
private:
    DicolaP *vc;
    int *vf;
    int cola_act;
    int cant;
    int maxColas;

public:
    ColaPrioridad();

    ColaPrioridad(int colas);

    bool vacia();

    int primero();

    void poner(int e, int prior);

    void sacar(int &e);

    void asignar_frec_prioridad(int frec, int prior);

    string to_str();
};

#endif
