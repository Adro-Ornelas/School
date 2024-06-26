/* 
 * File:   Animal.cpp
 * Author: Adro Ornelas
 * 
 * Created on 23 de abril de 2024, 02:24 PM
 */

#include "Animal.h"

Animal::Animal(string nomCi, string nomVu, int fecNacimiento, int fecMuerte,
            int eV, bool alive)
            : Especie(nomCi, nomVu),
              bornDate(fecNacimiento),
              deceaseDate(fecMuerte)
{
    esperanzaVida = eV;
    vivo = alive;
}

void Animal::print(){
    Especie::print();
    cout << "Este animal nació el ";
    bornDate.print();
    cout << " y tiene una esperanza de vida de " 
              << esperanzaVida << " años, cuida a sus crias por \n"
              << diasCuidado << " días";
    if(vivo)
        cout << " y está vivo. ";
    else { 
        cout << " y está muerto desde el ";
        deceaseDate.print();
        cout << ". ";
        
    }
            
}