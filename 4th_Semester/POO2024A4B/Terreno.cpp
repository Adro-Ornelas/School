/* 
 * File:   Terreno.cpp
 * Author: Adro Ornelas
 * 
 * Created on 14 de junio de 2024, 09:01 AM
 */

#include "Terreno.h"

Terreno::Terreno(double valor)
    : Bien(valor)
{
}

void Terreno::print(){
    Bien::print();
    cout << "Este terreno se ha depreciado en 0";
}
void Terreno::amortizar(){
    valorActual = valor;
    valorDepreciado = 0;
}
