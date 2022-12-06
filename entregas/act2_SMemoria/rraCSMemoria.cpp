//
// Created by rogerroca on 4/10/2022.
//

#include "rraCSMemoria.h"
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
rraCSMemoria::rraCSMemoria() {
    for (int i = 0; i < MAX_MEM_SPACE; i++) {
        mem[i].link = i + 1; // Create the initial values for memory links.
        mem[i].dataStored = 0; // Initialize data values.
    }
    mem[MAX_MEM_SPACE - 1].link = NULL_VALUE; // Set last link to -1. (end of memory).
    nextFreeNode = 0;
}

memDir rraCSMemoria::newSpace(const string &idStr) {
    // Getting ids from a comma separated string
    // and saving it to an array.
    int idCount = IDs::countIds(idStr);
    string *ids = IDs::idStrToArray(idStr);
    // request the first available node to memory:
    memDir requestNode = nextFreeNode;
    memDir firstUsedNode = nextFreeNode;
    // set node id and jump to the next linked node:
    for (int i = 0; i < idCount - 1; i++) {
        mem[requestNode].id = ids[i];
        requestNode = mem[requestNode].link; // linked node.
    }
    nextFreeNode = mem[requestNode].link; // new nextFreeNode.
    mem[requestNode].link = NULL_VALUE;
    mem[requestNode].id = ids[idCount - 1];
    return firstUsedNode;
}

void rraCSMemoria::delSpace(memDir dir) {
    // link the new available memory until first NULL_VALUE.
    memDir x = dir;
    while (mem[x].link != NULL_VALUE) {
        x = mem[x].link;
    }
    // Link with nextFreeNode and
    // set new direction of available memory.
    mem[x].link = nextFreeNode;
    nextFreeNode = dir;
}

void rraCSMemoria::setData(memDir dir, const string &idStr, int dataValue) {
    memDir z = dir;
    while (z != NULL_VALUE) {
        if (mem[z].id == idStr) {          // If found id:
            mem[z].dataStored = dataValue; // Save new Value.
        }
        z = mem[z].link;
    }
}

int rraCSMemoria::getData(memDir dir, const string &idStr) {
    memDir z = dir;
    while (z != NULL_VALUE) {
        if (mem[z].id == idStr) {
            return mem[z].dataStored;
        }
        z = mem[z].link;
    }
}

int rraCSMemoria::getAvailableSpace() {
    memDir x = nextFreeNode;
    int availableSpace = 0;
    while (x != -1) {
        availableSpace = availableSpace + 1;
        x = mem[x].link;
    }
    return availableSpace;
}

int rraCSMemoria::getUsedSpace() {
    int usedSpace = (MAX_MEM_SPACE) - getAvailableSpace();
    return usedSpace;
}

bool rraCSMemoria::isSpaceAvailable(memDir dir) {
    memDir x = nextFreeNode;
    bool isAvailable = false; // flag.
    while (x != NULL_VALUE && !isAvailable) {
        if (x == dir) {
            isAvailable = true;
        }
        x = mem[x].link;
    }
    return isAvailable;
}

void rraCSMemoria::showMemory() {
    cout << "DIR\tID\t\tDATA\tLINK" << endl;
    cout << "----------------------------------------" << endl;
    for (int i = 0; i < MAX_MEM_SPACE; i++) {
        cout << i << "\t" << mem[i].id << "\t\t" << mem[i].dataStored << "\t" << mem[i].link << endl;
    }
    cout << "----------------------------------------" << endl;
    cout << "Siguiente nodo Libre: " << nextFreeNode << endl;
    cout << "Espacio ocupado: " << getUsedSpace() << endl;
    cout << "Espacio disponible: " << getAvailableSpace() << endl;
}
