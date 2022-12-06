#include "iostream"
#include "MEMRRA.h"
#include "LISTARRA.h"
#include "POLINOMIORRA.h"

int main() {
    // Llamar a los constructores de LRRA, PRRA y LRRA
    auto *MRRA = new MEMRRA;
    auto *PRRA = new POLINOMIORRA(MRRA);
    auto *LRRA = new listaSMemoria(MRRA);
    // Solicita espacio, EXAMEN y OP1 se inicializan con 0.
    int Y = MRRA->new_espacio("EXAMEN,OP1");
    // Copia ID Y en H.
    int H = Y; // H = 0;
    // Carga 100 a OP1.
    MRRA->poner_dato(Y, "OP1", 100);
    // EXAMEN: 0, OP1: 100.
    // Y = 0 + 100; Y = 100.
    Y = MRRA->obtenerDato(Y, "EXAMEN") + MRRA->obtenerDato(Y, "OP1");
    std::cout << "LA SUMA ES " << Y << endl;
    LRRA->inserta(LRRA->primero(), Y); // Lista: 100.
    LRRA->inserta(LRRA->primero(), Y - 18); // Lista: 82, 100.
    MRRA->delete_espacio(H); // Elimina y libera 0 y 1 de la memoria.
    // Polinomio: 2x^5.
    // Se solicitan las direcciones 0, 1 y 6 (son las que están libres)
    // coef:2 dir:0; exp:5 dir:1; sig:-1 (no hay mas términos) dir: 6.
    PRRA->poner_termino(2, 5);
    LRRA->inserta(LRRA->fin(), Y + 18); // Lista: 82, 118, 100
    // Mostrar los valores.
    PRRA->mostrar();
    LRRA->mostrar();
    MRRA->mostrar();

    return 0;
}