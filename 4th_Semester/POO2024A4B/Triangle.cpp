/* 
 * File:   Triangle.cpp
 * Author: Adro Ornelas
 * 
 * Created on 17 de junio de 2024, 02:08 PM
 */

#include "Triangle.h"
#include <cmath>
using namespace std;

Triangle::Triangle(double longitudLado)
    : PoligonoRegular(longitudLado)
{
    numLados = 3;
}

void Triangle::presentar(){
    cout << "Esté triángulo es un polígono regular y cada lado mide "
         << longitudLado << endl;
}

void Triangle::area(){    
    // Deducible del teorema de pitágoras:
    Farea = sqrt(3) * pow(longitudLado, 2) / 4;
}

void Triangle::perimetro(){
    Fperimetro = numLados * longitudLado;
}





