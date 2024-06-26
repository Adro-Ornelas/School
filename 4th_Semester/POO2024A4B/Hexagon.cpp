/* 
 * File:   Hexagon.cpp
 * Author: Adro Ornelas
 * 
 * Created on 17 de junio de 2024, 02:08 PM
 */

#include "Hexagon.h"
#include <cmath>
using namespace std;

Hexagon::Hexagon(double longitudLado)
    : PoligonoRegular(longitudLado)
{
    numLados = 6;
}
void Hexagon::presentar(){
    cout << "Esté hexágono es un polígono regular y cada lado mide "
         << longitudLado << endl;
}

void Hexagon::area(){    
    // Deducible del teorema de pitágoras:
    Farea = 6 * sqrt(3) * pow(longitudLado, 2) / 4;;
}

void Hexagon::perimetro(){
    Fperimetro = numLados * longitudLado;
}
