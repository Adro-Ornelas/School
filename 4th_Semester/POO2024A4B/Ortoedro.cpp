/*
 * Author: Adro Ornelas
 * 
 * Created on 23 de febrero de 2024, 09:54 AM
 */

#include "Ortoedro.h"

Ortoedro::Ortoedro(int height, int length, int width)
    : miRectangle(height, length)
{
    ancho = width;
}

int Ortoedro::volumen(){
    return miRectangle.area() * ancho;
}

int Ortoedro::area(){
    return (4 * miRectangle.area()) + 2 * (ancho * miRectangle.getHeight());
}