#include "iostream"
//#include "simRAM.h"
//#include "listSimRAM.h"
//#include "PolynomialList.h"
//#include "listVector.h"
//#include "listPtr.h"
#include "polynomialVector.h"

using namespace std;

//void testSimRam() {
//    simRAM m;
//    m.newSpace("1st req");
//    m.newSpace("2nd req");
//    m.newSpace("3rd req");
//    m.showMemory();
//    cout << "Test:: isSpaceAvailable: " << m.isSpaceAvailable(m.getAvailableSpace()) << endl; // Should return 1
//    m.delSpace(2);
//    m.newSpace("4th req"); // Should be in DIR 2.
//    m.showMemory();
//    m.setData(0, "1st req", 100);
//    m.showMemory();
//}
//
//void testListSimRam() {
//    listSimRAM l;
//    l.insertItem(l.getFirstDir(), 100);
//    l.insertItemLast(200);
//    l.insertItemLast(300);
//    l.delItem(2);
//    l.insertItemLast(500);
//    l.printList();
//}
//
//void testPolynomialList() {
//    PolynomialList p1;
//    PolynomialList p2;
//    p1.setTerm(6, 2);
//    p1.setTerm(10, 3);
//    p2.derive(p1);
//    p2.print();
//
//}

void testPolynomialVector() {
    polynomialVector p1;
    polynomialVector p2;
    polynomialVector p3;

    p1.setTerm(6, 2);
    p1.setTerm(10, 3);
    p1.print();
    p2.setTerm(-6, 2);
    p2.setTerm(-10, 3);
    p2.print();
    p3.derive(p1);
    p3.print();
}

//void testListVector() {
//    listVector l;
//    l.insertItemFirst(100);
//    l.insertItemLast(200);
//    l.insertItem(1, 150);
//    l.delItem(1);
//    l.insertItem(l.getFirstDir(), 300);
//    l.setItem(0, l.getValue(l.getPreviousDir(2)));
//
//    l.printList();
//}

//void testListPtr() {
//    listPtr l;
//    l.insertItemFirst(100);
//    l.insertItemLast(200);
//    l.insertItemLast(300);
//    l.insertItemFirst(10);
//    l.insertItem(l.getPreviousDir(l.getLastDir()), 1);
//    l.printList();
//    cout << l.getValue(2) << endl;
//
//}

int main() {
//    testSimRam();
//    testListSimRam();
//    testPolynomialList();
//    testListVector();
//    testListPtr();
    testPolynomialVector();
    return 0;

}