#include "iostream"
#include "simRAM.h"
#include "listSimRAM.h"
#include "polynomialSimRAM.h"

void Exam1() {
    auto *MRRA = new simRAM;
    auto *LRRA = new listSimRAM(MRRA);
    auto *PRRA = new polynomialSimRAM(MRRA);
    memDir Y = MRRA->newSpace("EXAMEN,OP1");
    memDir H = Y;
    MRRA->setData(Y, "OP1", 100);
/***************************************************************
 * En el enunciado, se menciona 2 veces la variable Y,
 * la primera es de tipo 'dirección de memoria'
 * y la segunda de tipo 'entero'.
 * Si bien, el tipo 'dirección de memoria' es un entero,
 * declararé en su lugar una nueva variable 'y' de tipo entero,
 * para respetar el tipo de dato, el resultado final es el mismo.
 ***************************************************************/
    int y = MRRA->getData(Y, "EXAMEN") + MRRA->getData(Y, "OP1");
    cout << "LA SUMA ES " << y << endl;
    LRRA->insertItem(LRRA->getFirstDir(), y);
    LRRA->insertItem(LRRA->getFirstDir(), y - 18);
    MRRA->delSpace(H);
    PRRA->setTerm(2, 5);
    LRRA->insertItem(LRRA->getLastDir(), y + 18);

    LRRA->show();
    PRRA->show();
    MRRA->show();
}

int main() {
    Exam1();
    return 0;
}