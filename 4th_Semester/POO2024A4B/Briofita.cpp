/* 
 * File:   Briofita.cpp
 * Author: Adro Ornelas
 * 
 * Created on 14 de mayo de 2024, 01:58 PM
 */

#include "Briofita.h"

Briofita::Briofita(string nomCi, string nomVu, bool esVasc, bool esFlor)
    : Planta(nomCi, nomVu, esVasc, esFlor)
{
}

void Briofita::print(){
    Planta::print();
    cout << "Esta briofita tiene un sustrato del tipo " << sustrato
         << '.' << endl;
}

