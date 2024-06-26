/* 
 * File:   Rombo.cpp
 * Author: Adro Ornelas
 * 
 * Created on 17 de junio de 2024, 02:08 PM
 */

#include "Rombo.h"
#include <iostream>
#include <cmath>

using namespace std;

Rombo::Rombo(double diagonal1, double diagonal2)
{
    this->diagonal1 = diagonal1;
    this->diagonal2 = diagonal2;
}

void Rombo::presentar(){
    cout << "Esté rombo es un polígono irregular, "
         << "la diagonal uno mide " << diagonal1
         << " y la diagonal dos mide " << diagonal2 << endl;
}

void Rombo::area(){    
    Farea = diagonal1 * diagonal2 / 2;
}

void Rombo::perimetro(){
    Fperimetro = 2 * sqrt(pow(diagonal1, 2) + pow(diagonal2, 2));
}

