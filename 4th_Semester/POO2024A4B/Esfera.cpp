/* 
 * File:   Esfera.cpp
 * Author: Adro Ornelas
 * 
 * Created on 10 de febrero de 2024, 08:45 PM
 */

#include "Esfera.h"
#include <iostream>
#include <cmath>

Esfera::Esfera(double coordX, double coordY, double rad)
    : miCirculo(coordX, coordY, rad)
{
    
}

double Esfera::area(){
    return 4* M_PI * pow(miCirculo.obtenerradio(), 2);
}
double Esfera::volumen(){
    return (4.0 / 3.0) * M_PI * pow(miCirculo.obtenerradio(), 3);
}


