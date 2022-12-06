//
// Created by rogerroca on 4/10/2022.
//

#include "SMemoria.h"
#include "iostream"

using namespace std;
namespace IDs {
    // From a comma separated string,
    // count the ids and build an array with them.
    int countIds(string id) {
        int idCount = 0;
        unsigned int idLength = id.length();
        for (int i = 0; i < idLength; i++) {
            if (id[i] == ',') {
                idCount++;
            }
        }
        if (id[idLength - 1] != ',') {
            idCount++;
        }
        return idCount;
    }

    string *idStrToArray(const string &idStr) {
        int IDsCount = countIds(idStr);
        auto *ids = new string[IDsCount];
        int i = 0;
        string auxIds = idStr;
        while (auxIds.length() > 0) {
            unsigned int pos = auxIds.find_first_of(',');
            pos = pos == -1 ? auxIds.length() : pos;
            string id = auxIds.substr(0, pos);
            if (i + 1 < IDsCount) {
                auxIds = auxIds.substr(pos + 1, auxIds.length() - pos - 1);
            } else {
                auxIds = "";
            }
            ids[i] = id;
            i++;
        }
        return ids;
    }
} // namespace IDs
MEMRRA::MEMRRA() {
    for (int i = 0; i < MAX_MEM_SPACE; i++) {
        mem[i].link = i + 1; // Create the initial values for memory links.
        mem[i].Dato = 0; // Initialize data values.
    }
    mem[MAX_MEM_SPACE - 1].link = NULL_VALUE; // Set last link to -1. (end of memory).
    libre = 0;
}

memDir MEMRRA::new_espacio(const string &cadena_id) {
    // Getting ids from a comma separated string
    // and saving it to an array.
    int idCount = IDs::countIds(cadena_id);
    string *ids = IDs::idStrToArray(cadena_id);
    // request the first available node to memory:
    memDir requestNode = libre;
    memDir firstUsedNode = libre;
    // set node id and jump to the next linked node:
    for (int i = 0; i < idCount - 1; i++) {
        mem[requestNode].id = ids[i];
        requestNode = mem[requestNode].link; // linked node.
    }
    libre = mem[requestNode].link; // new libre.
    mem[requestNode].link = NULL_VALUE;
    mem[requestNode].id = ids[idCount - 1];
    return firstUsedNode;
}

void MEMRRA::delete_espacio(memDir dir) {
    // link the new available memory until first NULL_VALUE.
    memDir x = dir;
    while (mem[x].link != NULL_VALUE) {
        x = mem[x].link;
    }
    // Link with libre and
    // set new direction of available memory.
    mem[x].link = libre;
    libre = dir;
}

void MEMRRA::poner_dato(memDir dir, const string &cadena_id, int dataValue) {
    memDir z = dir;
    while (z != NULL_VALUE) {
        if (mem[z].id == cadena_id) {          // If found id:
            mem[z].Dato = dataValue; // Save new Value.
        }
        z = mem[z].link;
    }
}

int MEMRRA::obtenerDato(memDir dir, const string &cadena_id) {
    memDir z = dir;
    while (z != NULL_VALUE) {
        if (mem[z].id == cadena_id) {
            return mem[z].Dato;
        }
        z = mem[z].link;
    }
}

int MEMRRA::Espacio_Disponible() {
    memDir x = libre;
    int availableSpace = 0;
    while (x != -1) {
        availableSpace = availableSpace + 1;
        x = mem[x].link;
    }
    return availableSpace;
}

int MEMRRA::Espacio_ocupado() {
    int usedSpace = (MAX_MEM_SPACE) - Espacio_Disponible();
    return usedSpace;
}

bool MEMRRA::dir_libre(memDir dir) {
    memDir x = libre;
    bool isAvailable = false; // flag.
    while (x != NULL_VALUE && !isAvailable) {
        if (x == dir) {
            isAvailable = true;
        }
        x = mem[x].link;
    }
    return isAvailable;
}

void MEMRRA::mostrar() {
    cout << "DIR\tID\t\tDATA\tLINK" << endl;
    cout << "----------------------------------------" << endl;
    for (int i = 0; i < MAX_MEM_SPACE; i++) {
        cout << i << "\t" << mem[i].id << "\t\t" << mem[i].Dato << "\t" << mem[i].link << endl;
    }
    cout << "----------------------------------------" << endl;
    cout << "Siguiente nodo Libre: " << libre << endl;
    cout << "Espacio ocupado: " << Espacio_ocupado() << endl;
    cout << "Espacio disponible: " << Espacio_Disponible() << endl;
}
