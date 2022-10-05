#include <iostream>
#include "simRAM.h"

using namespace std;

int main() {
    simRAM memory;
    cout << "RAM SIMULATOR" << endl;
    cout << "1. Request New Space" << endl;
    memory.newSpace("id1,id2,id3");
    memory.showMemory();
    cout << "2. Remove Space" << endl;
    memory.delSpace(0);
    memory.showMemory();
    cout << "3. Set data on memory space" << endl;
    memory.newSpace("id1,id2,id3");
    memory.newSpace("id2.1,id2.2");
    memory.setData(0, "id2", 100);
    memory.showMemory();
//    cout << "4. Get data from memory space" << endl;
//    cout << "5. Show memory" << endl;
    return 0;
}
