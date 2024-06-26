/* 
 * File:   Planta.cpp
 * Author: Adro Ornelas
 * 
 * Created on 15 de mayo de 2024, 10:49 PM
 */

#include "Planta.h"

Planta::Planta(string nomCi, string nomVu, bool esVasc, bool esFlor)
    : Especie(nomCi, nomVu)
{
}

void Planta::print(){
    Especie::print();
    cout << "Esta planta " << (esVascular ? "sí":"no") << " es vascular."
         << endl
         << "Además, " << (esFloral ? "sí":"no") << " es una planta floral."
         << endl;
}

