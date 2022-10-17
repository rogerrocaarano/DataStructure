#include <iostream>
#include "simRAM.h"
#include "listSimRAM.h"

using namespace std;

void testSimRam() {
    simRAM m;
    m.newSpace("1st req");
    m.newSpace("2nd req");
    m.newSpace("3rd req");
    m.showMemory();
    cout << "Test:: isSpaceAvailable: " << m.isSpaceAvailable(m.getAvailableSpace()) << endl; // Should return 1
    m.delSpace(2);
    m.newSpace("4th req"); // Should be in DIR 2.
    m.showMemory();
    m.setData(0, "1st req", 100);
    m.showMemory();
}

void testListSimRam() {
    listSimRAM l;
    l.insertItem(l.getFirstDir(), 1);
    l.insertItemLast(2);
    l.insertItemFirst(3);
    l.printList();
}

int main() {
//    testSimRam();
    testListSimRam();
    return 0;
}