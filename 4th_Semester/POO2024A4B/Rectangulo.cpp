/* 
 * File:   Rectangulo.cpp
 * Author: Adro Ornelas
 * 
 * Created on 23 de febrero de 2024, 09:47 AM
 */

#include "Rectangulo.h"

Rectangulo::Rectangulo(int height, int length)
{
    alto = height;
    largo = length;
}

int Rectangulo::area(){
    return alto * largo;
}

int Rectangulo::getLength(){
    return largo;
}
int Rectangulo::getHeight(){
    return alto;
}