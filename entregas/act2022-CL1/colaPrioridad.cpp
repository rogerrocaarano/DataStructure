// ---------------------------------------------------------------------------

#pragma hdrstop

#include "colaPrioridad.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

ColaPrioridad::ColaPrioridad() {
    // El constructor por defecto creará una estructura con 3 colas
    maxColas = 3;
    vc = new diColaPtr[maxColas];
    vf = new int[maxColas];
    for (int i = 0; i < maxColas; i++) {
        // vc[i] = new ColaL();
        vf[i] = 1;
    }
    cola_act = 0;
    cant = 0;
}

bool ColaPrioridad::vacia() {
    for (int i = 0; i < maxColas; i++) {
        if (!vc[i].vacia())
            return false;
    }
    return true;
}

int ColaPrioridad::primero() {
    if (!vacia()) {
        if (!vc[cola_act].vacia()) {
            // if (cant < vf[cola_act])
            return vc[cola_act].primero();
        } else {
            int cola = cola_act;
            while (vc[cola].vacia()) {
                cola = (cola + 1) % maxColas;
            }
            return vc[cola].primero();

        }
    }
}

void ColaPrioridad::poner(int e, int prior) {
    if (prior > 0 && prior <= maxColas) {
        vc[prior - 1].poner(e);
    }
}

void ColaPrioridad::sacar(int &e) {
    if (!vacia()) {
        if (!vc[cola_act].vacia()) {
            if (cant < vf[cola_act]) {
                cant++;
                vc[cola_act].sacar(e);
                if (cant == vf[cola_act]) {
                    cola_act = (cola_act + 1) % maxColas;
                    cant = 0;
                }
            }
        } else {
            while (vc[cola_act].vacia()) {
                cola_act = (cola_act + 1) % maxColas;
            }
            cant = 0;
            if (cant < vf[cola_act]) {
                cant++;
                vc[cola_act].sacar(e);
                if (cant == vf[cola_act]) {
                    cola_act = (cola_act + 1) % maxColas;
                    cant = 0;
                }
            }
        }
    }
}

void ColaPrioridad::asignar_frec_prioridad(int frec, int prior) {
    if (prior > 0 && prior <= maxColas) {
        vf[prior - 1] = frec;
    }
}

string ColaPrioridad::to_str() {
    string s = "";
    for (int i = 0; i < maxColas; i++)
        s += "COLA" + to_string((i + 1)) + ": " + vc[i].to_str() + "\n";
    return s;

}

ColaPrioridad::ColaPrioridad(int colas) {
    maxColas = colas;
    vc = new diColaPtr[maxColas];
    vf = new int[maxColas];
    for (int i = 0; i < maxColas; i++) {
        // vc[i] = new ColaL();
        vf[i] = 1;
    }
    cola_act = 0;
    cant = 0;
}
