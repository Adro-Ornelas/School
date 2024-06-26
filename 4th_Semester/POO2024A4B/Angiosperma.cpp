/* 
 * File:   Angiosperma.cpp
 * Author: Adro Ornelas
 * 
 * Created on 14 de mayo de 2024, 01:58 PM
 */

#include "Angiosperma.h"

Angiosperma::Angiosperma(string nomCi, string nomVu, bool esVasc, bool esFlor)
    : Planta(nomCi, nomVu, esVasc, esFlor)
{
}

void Angiosperma::print(){
    Planta::print();
    cout << "Esta angiosperma tiene un periodo de floración de "
         << periodoFloracion << endl;
}

