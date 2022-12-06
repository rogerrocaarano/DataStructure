#include "rraCSMemoria.h"
#include "ListaRRA.h"

using namespace std;

int main() {
    auto *MiMemrra = new rraCSMemoria();
    auto *Lrra = new ListaRRA(MiMemrra);
    memDir z = MiMemrra->newSpace("ROGER,ROCA,ARANO");
    MiMemrra->setData(z, "ROGER", MiMemrra->getData(z, "ROGER") + 2);
    Lrra->insertItemFirst(100);
    Lrra->insertItemLast(200);
    Lrra->insertItem(Lrra->getLastDir(), 150);
    MiMemrra->showMemory();
    return 0;
}
