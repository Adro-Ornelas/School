/* 
 * File:   Rectangle.cpp
 * Author: Adro Ornelas
 * 
 * Created on 17 de junio de 2024, 02:08 PM
 */

#include "Rectangle.h"

using namespace std;

Rectangle::Rectangle(double longitudLado)
    : PoligonoRegular(longitudLado)
{
    numLados = 4;
}

void Rectangle::presentar(){
    cout << "Esté rectángulo es un polígono regular y cada lado mide "
         << longitudLado << endl;
}

void Rectangle::area(){    
    // Deducible del teorema de pitágoras:
    Farea = longitudLado * longitudLado;
}

void Rectangle::perimetro(){
    Fperimetro = numLados * longitudLado;
}
