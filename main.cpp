#include <iostream>
#include "simRAM.h"
#include "list.h"

using namespace std;

int main() {
    simRAM *memory = new simRAM();
    memory->newSpace("id1,id2");
    memory->showMemory();
    list *l = new list(memory);
    l->insertItemFirst(100);
    l->insertItemLast(200);
    l->insertItem(4, 10);
    l->insertItemLast(20);
    memory->showMemory();
    return 0;
}
