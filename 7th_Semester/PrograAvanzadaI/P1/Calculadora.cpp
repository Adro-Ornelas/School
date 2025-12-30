// Calculadora.cpp

#include <iostream>
// #include "Numero.h"
#include "Expresion.h"

using namespace std;


int main(){
    
    while(1){
    int num, deno;
    char op;
    cout << "Escribe el término 1: ";
    cin >> num >> deno;
    
    Numero num1(num, deno);
    cout << "Escribe la operación (+, -, *, /): ";
    cin >> op;
    cout << "Escribe el término 2: ";
    cin >> num >> deno;
    Numero num2(num, deno);

    Numero res;
    cout << endl;
    num1.imprimir();
    cout << " " << op << " ";
    num2.imprimir();
    cout << " = ";

    switch (op) {

        case '+':
        res = num1.sumar(num2);
        
        break;


        case '-':
        res = num1.restar(num2);
        
        break;

        case '*':
        res = num1.multiplicar(num2);
        
        break;

        case '/':
        res = num1.dividir(num2);
        
        break;

        default:
        break;

    
    }
    cout << endl;
    res.imprimir();
    cout << endl;
    }

    return 0;
}

