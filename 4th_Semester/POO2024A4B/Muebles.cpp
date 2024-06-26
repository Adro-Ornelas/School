/* 
 * File:   Muebles.cpp
 * Author: Adro Ornelas
 * 
 * Created on 14 de junio de 2024, 08:51 AM
 */

#include "Muebles.h"

Muebles::Muebles(double valor, int aO, int aA)
    : Bien(valor)
{
    anioOriginal = aO;
    anioActual = aA;
}

void Muebles::print(){
    Bien::print();
    cout << "Este mueble fue adquirido en " << anioOriginal <<
            " y por eso se ha depreciado en " << valorDepreciado <<
            " y ahora vale " << valorActual;
}

void Muebles::amortizar(){
    factorAmort = (anioActual - anioOriginal) * 0.05;
    if(factorAmort > 1)
        factorAmort = 1;
    valorDepreciado = valor * factorAmort;
    valorActual = valor - valorDepreciado;
}
