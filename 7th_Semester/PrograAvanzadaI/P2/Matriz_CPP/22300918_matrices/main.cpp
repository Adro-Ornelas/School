// main.cpp
#include <iostream>
#include "Matriz.h"

using namespace std;

int main(void) {

    int rows, cols;
    char oper;

    cout << "Tamaño de matriz 1 (filas columnas):";
    cin >> rows >> cols;
    Matriz m1(rows, cols);
    m1.llenarMatriz();

    cout << "Operación (+, -, *): ";
    cin >> oper;

    cout << "Tamaño de matriz 2 (filas columnas):";
    cin >> rows >> cols;
    Matriz m2(rows, cols);
    m2.llenarMatriz();

    // Inicializa matriz de resultado con tamaño de matriz2
    Matriz m3;


    switch (oper) {
    case '*':
        m3 = m1 * m2;
        break;

    case '+':
        m3 = m1 + m2;
        break;

    case '-':
        m3 = m1 - m2;
        break;

    default:

        cout << "Operación no admitida";

    }


    // Si fue un resultado váido, imprime
    if(m3.getRows() > 0) {
        cout << endl;
        m1.imprimir();
        cout << "\n"<<oper<<"\n";
        m2.imprimir();
        cout << "\n=\n";
        m3.imprimir();

    }
    return 0;
}