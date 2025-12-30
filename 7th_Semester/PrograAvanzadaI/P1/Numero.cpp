// Numero.cpp

#include "Numero.h"
#include <cstdio>
#include <iostream>
//#include <utility>

// Inicializa número
Numero::Numero(int num, int denom) {
    this->numerador = num;
    this->denominador = denom;
    
    /*
    std::cout << "Construyendo";
    getchar();
    */
}

Numero::~Numero() {
    
    /*
    std::cout << "Destruyendo";
    numerador = denominador = 0;
    getchar();
    */
}

Numero Numero::sumar(Numero num) {

    Numero res;
    
    // Primero normaliza denominador
    res.numerador = numerador * num.denominador;
    res.denominador = denominador * num.denominador;

    // Suma numeradores con mismo denominador
    res.numerador +=  num.numerador * denominador;

    // Returna expresión NO simplificada
    return res;
}

Numero Numero::restar(Numero num) {
    
    Numero res;

    // Normaliza denominador
    res.numerador = numerador * num.denominador;
    res.denominador = denominador * num.denominador;

    // Resta numeradores con mismo denominador
    res.numerador -=  num.numerador * denominador;
    return res;
}

Numero Numero::multiplicar(Numero num) {
    
    Numero res;

    // Multiplica recto las fracciones
    res.numerador = numerador * num.numerador;
    res.denominador = denominador * num.denominador;

    return res;
}
Numero Numero::dividir(Numero num) {
    
    Numero res;
    //if(num.numerador == 0 || num.denominador == 0)
     //   return res;
    // Multiplica cruzado
    res.numerador = numerador * num.denominador;
    res.denominador = denominador * num.numerador;
    
    // Si el denominador del segundo es cero, hace inde\

    if(num.denominador == 0)
        res.denominador = 0;
    return res;
}

void Numero::imprimir(){

    // Primero simplifica
    simplificar();

    std::cout << "(";
    
    if(0 == denominador) {
        
        std::cout << "indef";

    } else {
        
        // Si el denominador es uno, sólo es entero
        if(1 == denominador){

            std::cout << numerador;
            
        } else if(numerador > denominador) {
            // Fracción mixta
            
            // Imprime parte entera
            std::cout << numerador / denominador << " ";

            // Imprime fracción resultante
            std::cout << numerador % denominador
            << " / " <<
            denominador;

        } else {
             
            // Fracción propia

            // Imprime parte entera
            std::cout << numerador
            << " / "
            << denominador;
        }


    }

    std::cout << ")";
}

void Numero::simplificar() {

    // Simplifica la fracción
    if(denominador != 0) {

        // Primero revisa si es divisible
        if(numerador % denominador == 0){
            
            numerador = numerador / denominador;
            // Hace denminador uno
            denominador = 1;
        } else {
            // Si no es divisible, intenta simplificar
            int divisor = mcd(numerador, denominador);

            // Si no era divisible, esta dividiendo / 1
            numerador /= divisor;
            denominador /= divisor;

        }
    }
}

// Maximo común divisor, (algoritmo euclides)
// Si no es divisle, retorna cero
int Numero::mcd(int a, int b) {

    // Necesario que a >= b
    if (b > a)
        std::swap(a, b);

    int tmp;
    while(b != 0) {
        tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}