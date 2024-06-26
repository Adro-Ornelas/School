/* 
 * File:   Anfibio.cpp
 * Author: Adro Ornelas
 * 
 * Created on 28 de abril de 2024, 08:12 AM
 */

#include "Anfibio.h"

Anfibio::Anfibio(string nomCi, string nomVu, int fecNacimiento, int fecMuerte,
            int eV, bool alive) 
    : Animal(nomCi, nomVu, fecNacimiento, fecMuerte, eV, alive)
{
    diasCuidado = 0; // Los anfibios son unos desobligados
}

void Anfibio::print(){
    Animal::print();
    cout << "Este anfibio tiene la capacidad de sobrevivir "
         << tiempoBranqueas << " horas debajo del agua" << endl;
}
