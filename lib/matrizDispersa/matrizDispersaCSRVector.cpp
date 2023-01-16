//
// Created by rogerroca on 15/12/2022.
//

#include <iostream>
#include "matrizDispersaCSRVector.h"

int matrizDispersaCSRVector::existe_elemento(int f, int c) {
    // Determinar la cantidad de elementos diferentes de "repe" en la fila:
    // Los valores de fila y columna vienen dados de forma natural al usuario (empiezan en 1),
    // considerar esto para mapear correctamente a un array en Cpp considerando que estos empiezan en 0.
    int dif = Vf[f] - Vf[f - 1];
    int pos = Vf[f - 1] - 1;
    for (int i = 0; i < dif; i++) {
        if (Vc[pos + i] == c) {
            return pos + i;
        }
    }
    // Si no se encuentra el valor de la columna en la fila:
    return -1;
}

int matrizDispersaCSRVector::donde_insertar(int f, int c) {
    int dif = Vf[f] - Vf[f - 1];
    int pos = Vf[f - 1] - 1;
    while (c > Vc[pos] && dif > 0) {
        pos++;
        dif--;
    }
    return pos;
}

matrizDispersaCSRVector::matrizDispersaCSRVector() {
    df = 0;
    dc = 0;
    repe = 0;
    nt = 0;
    // Inicializar un valor más que el número de filas,
    // el número de elementos diferentes de "repe" en una fila estará determinado por Vf[f+1]-Vf[f]
    // inicializamos en 1 por conveniencia.
    Vf[0] = 1;
    Vf[1] = 1;
}

void matrizDispersaCSRVector::dimensionar(int m, int n) {
    // todo: este método debería soportar redimensionamiento en ejecución?
    df = m;
    dc = n;
    // Limpiar los valores de los vectores:
    for (int i = 0; i < m * n; i++) {
        Vd[i] = 0;
        Vc[i] = 0;
    }
    // Asignar el valor de 1 a Df de 0 a df:
    for (int i = 0; i <= df; i++) {
        Vf[i] = 1;
    }
}

int matrizDispersaCSRVector::dimension_fila() {
    return df;
}

int matrizDispersaCSRVector::dimension_columna() {
    return dc;
}

void matrizDispersaCSRVector::poner(int f, int c, matrizDispersaCSRVector::DATA_TYPE valor) {
    if (!verificarRango(f, c))
        return;
    // Determinar si existe un valor en f,c:
    int pos = existe_elemento(f, c);
    if (pos >= 0) {
        // Si se introduce el valor "repe" en alguno de los elementos ya existentes, el elemento debe ser eliminado:
        // Obtener la posición del elemento a eliminar y llamar al método eliminar(pos)
        if (valor != repe) Vd[pos] = valor;
        else eliminar(f, c);
        return;
    }
    // Determinar la posición en la que se tiene que insertar el elemento, si no será el último elemento,
    // entonces tenemos que recorrer los valores desde la posición para poder insertar el valor nuevo.
    pos = donde_insertar(f, c);
    if (pos != nt) {
        for (int i = pos + 1; i <= nt; i++) {
            Vc[i] = Vc[i - 1];
            Vd[i] = Vd[i - 1];
        }
    }
    // Escribir los valores de Vd y Vc:
    Vd[pos] = valor;
    Vc[pos] = c;
    // Incrementar los contadores de Vf y nt:
    for (int i = f; i < df + 1; i++) {
        Vf[i]++;
    }
    nt++;
}

matrizDispersaCSRVector::DATA_TYPE matrizDispersaCSRVector::elemento(int f, int c) {
    int pos = existe_elemento(f, c);
    return verificarRango(f, c) && pos >= 0 ? Vd[pos] : repe;
}

void matrizDispersaCSRVector::definir_valor_repetido(matrizDispersaCSRVector::DATA_TYPE valor) {
    // Eliminar los elementos de la matriz que coincidan con el nuevo valor para "repe"
    // y luego cambiar el valor en la estructura.
    for (int i = 1; i <= df; i++) {
        for (int j = 1; j <= dc; j++) {
            if (elemento(i, j) == valor)
                eliminar(i, j);
        }
    }
    repe = valor;

}

void matrizDispersaCSRVector::eliminar(int f, int c) {
    // Obtener la posición de f, c:
    int pos = existe_elemento(f, c);
    // A este método solo deberían pasarse valores que existen dentro de la matriz:
    if (pos == -1)
        return;
    // Desplazar un lugar hacia atrás Vc y Vd.
    for (int i = pos; i < nt - 1; i++) {
        Vc[i] = Vc[i + 1];
        Vd[i] = Vd[i + 1];
    }
    // Poner en 0 los valores de Vc y Vd.
    Vc[pos] = 0;
    Vd[pos] = 0;
    // Disminuir los contadores de nt y Vf.
    for (int i = f; i < df + 1; i++) {
        Vf[i]--;
    }
    nt--;
}

void matrizDispersaCSRVector::mostrar() {
    for (int i = 1; i <= df; i++) {
        for (int j = 1; j <= dc; j++) {
            std::cout << "[" << elemento(i, j) << "]";
        }
        std::cout << std::endl;
    }
}

bool matrizDispersaCSRVector::verificarRango(int f, int c) {
    // Verificar si los datos están dentro del rango de la matriz:
    if (f <= 0 || f > df) {
        std::cout << "Error: Fila fuera de rango." << std::endl;
        return false;
    }
    if (c <= 0 || c > dc) {
        std::cout << "Error: Columna fuera de rango." << std::endl;
        return false;
    }
    return true;
}


