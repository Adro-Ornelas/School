/* 
 * File:   Persona.cpp
 * Author: Adro Ornelas
 * 
 * Created on 16 de febrero de 2024, 03:01 PM
 */

#include "Persona.h"
#include <String.h>
#include <iostream>

Persona::Persona(unsigned int f, char nom[50], char dir[50],
        unsigned int telefon, char genero)
    : bornDate(f),
      phonenumb(telefon),
      gender(genero)
{
    strcpy(name, nom);
    strcpy(adress, dir);
}

void Persona::print(){
    std::cout << "Hello!, my name is " << name << ", I was born on ";
    bornDate.print();
    std::cout << ".\nMy phone number is " << phonenumb\
              << " and I am a " << (gender == 'M' ? "man":"woman") << ".\n";
}

