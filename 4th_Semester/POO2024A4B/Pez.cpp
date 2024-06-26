/* 
 * File:   Pez.cpp
 * Author: Adro Ornelas
 * 
 * Created on 23 de abril de 2024, 02:25 PM
 */

#include "Pez.h"
Pez::Pez(string nomCi, string nomVu, int fecNacimiento, int fecMuerte,
            int eV, bool alive)
    : Animal(nomCi, nomVu, fecNacimiento, fecMuerte, eV, alive)
{
    
}

void Pez::print(){
    Animal::print();
    cout << "Este pez " << (esAguaDulce ? "si":"no")
              << " es de agua dulce. ";
    
}