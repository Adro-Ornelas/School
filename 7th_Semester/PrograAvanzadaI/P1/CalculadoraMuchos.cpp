// CalculadoraMuchos.cpp

#include <cstdio>
#include <iostream>
#include <string>

#include "Expresion.h"

using namespace std;


int main(void) {

    string s_expresion;

    // Recibe expresión como string a evaluar
    cout << "Escribe la expresión a evaluar:\nEjemplo: 2 / 10 + 5 / 4\n";
    // Obtiene string con espacios
    getline(cin, s_expresion);

    // Construye expresión y estrcutura de datos
    Expresion miExp(s_expresion);
    
    /*
    Numero num(1, 4);

    cout << (miExp.insertar(num, '+'));
    num = num.sumar(num);

    cout << miExp.insertar(num, '-');
    num = num.sumar(num);

    cout << miExp.insertar(num, '*');
    num = num.sumar(num);

    cout << miExp.insertar(num, '/');
    
    Numero num2(1, 2);
    num = num.sumar(num2);
    cout << miExp.insertar(num, '+');

    */
    miExp.imprimirExpr();

    // miExp.resolver();

    //miExp.imprimirRes();

}