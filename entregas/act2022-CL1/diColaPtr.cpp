// ---------------------------------------------------------------------------

#pragma hdrstop

#include "diColaPtr.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

diColaPtr::diColaPtr() {
    ini = fin = nullptr;
}

bool diColaPtr::vacia() {
    return ini == nullptr;
}

void diColaPtr::poner(int e) {
    auto *aux = new NodoC();
    aux->elemento = e;
    aux->sig = nullptr;
    if (vacia()) {
        ini = fin = aux;
    } else {
        fin->sig = aux;
        fin = aux;
    }
}

void diColaPtr::sacar(int &e) {
    if (!vacia()) {
        e = ini->elemento;
        NodoC *x = ini;
        if (ini == fin)
            ini = fin = nullptr;
        else
            ini = ini->sig;
        delete (x);
    }
}

int diColaPtr::primero() {
    if (!vacia())
        return ini->elemento;
}

int diColaPtr::ultimo() {
    if (!vacia())
        return fin->elemento;
}

void diColaPtr::poner_frente(int e) {
    auto *aux = new NodoC();
    if (vacia())
        ini = fin = aux;
    else {
        aux->elemento = e;
        aux->sig = ini;
        ini = aux;
    }
}

void diColaPtr::sacar_final(int &e) {
    if (!vacia()) {
        e = fin->elemento;
        NodoC *x = fin;
        if (ini == fin)
            ini = fin = nullptr;
        else {
            NodoC *ant = ini;
            while (ant->sig != fin)
                ant = ant->sig;
            ant->sig = nullptr;
            fin = ant;
        }
        delete (x);
    }
}

std::string diColaPtr::to_str() {
    std::string s = "";
    int e;
    auto *aux = new diColaPtr();
    while (!vacia()) {
        sacar(e);
        aux->poner(e);
        s += std::to_string(e);
        if (!vacia())
            s += ",";
    }
    while (!aux->vacia()) {
        aux->sacar(e);
        poner(e);
    }
    return s;
}
