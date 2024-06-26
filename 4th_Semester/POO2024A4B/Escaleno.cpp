/* 
 * File:   Escaleno.cpp
 * Author: Adro Ornelas
 * 
 * Created on 17 de junio de 2024, 02:08 PM
 */

#include "Escaleno.h"
#include <cmath>
using namespace std;

Escaleno::Escaleno(double lado1, double lado2, double lado3) {
    this->lado1 = lado1;
    this->lado2 = lado2;
    this->lado3 = lado3;
}


void Escaleno::presentar(){
    cout << "Esté rombo es un polígono irregular, " << endl;
}

void Escaleno::area(){    
    // Fórmula de Herón
    double se = (lado1 + lado2 + lado3) / 2;
    Farea = sqrt((se*(se - lado1)*(se - lado2)*(se - lado3)));
}

void Escaleno::perimetro(){
    Fperimetro = lado1 + lado2 + lado3;
}




