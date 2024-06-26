/* 
 * File:   Rodado.cpp
 * Author: Adro Ornelas
 * 
 * Created on 7 de junio de 2024, 03:02 PM
 */

#include "Rodado.h"

Rodado::Rodado(double valor, int km)
    : Bien(valor)
{
    kilometraje = km;
}

void Rodado::print(){
    Bien::print();
    cout << "Este rodado ha viajado " << kilometraje << " km, se deprecia"
            "en 80 centavos por kilómetro " << endl
         << "Se ha devaluado en $ " << valorDepreciado
         << endl << "Por lo que ahora vale $ " << valorActual;
}

void Rodado::amortizar(){
    valorDepreciado = kilometraje * 0.8;   // Suponemos que se devalúa $0.8/km
    valorActual = valor - valorDepreciado;
}

