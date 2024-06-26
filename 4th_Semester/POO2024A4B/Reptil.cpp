/* 
 * File:   Reptil.cpp
 * Author: Adro Ornelas
 * 
 * Created on 22 de mayo de 2024, 02:01 PM
 */

#include "Reptil.h"

Reptil::Reptil(string nomCi, string nomVu, int fecnacimiento, int fecmuerte,
            int eV, bool alive, bool esTerr)
    : Animal(nomCi, nomVu, fecnacimiento, fecmuerte, eV, alive)
{
    diasCuidado = 0; // Los reptiless son unos desobligados    
}

void Reptil::print(){
    Animal::print();
    cout << "Este reptil " << (esTerrestre ? "sí":"no")
         << " es terrestre." << endl;
}


