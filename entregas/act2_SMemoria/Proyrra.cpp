#include "rraCSMemoria.h"

using namespace std;

int main() {
    rraCSMemoria MiMemrra;
    memDir x = MiMemrra.newSpace("uno");
    MiMemrra.setData(x, "uno", 100);
    memDir y = MiMemrra.newSpace("dos");
    MiMemrra.delSpace(x);
    memDir z = MiMemrra.newSpace("ROGER,ROCA,ARANO");
    MiMemrra.setData(z, "ROGER", MiMemrra.getData(z, "ROGER") + 5);
    MiMemrra.showMemory();
    return 0;
}
