/* 
 * File:   Vector.cpp
 * Author: Adro Ornelas
 * 
 * Created on 8 de marzo de 2024, 09:57 AM
 */

#include "Vector.h"
#include <iostream>
Vector::Vector(double origenX, double origenY, double finalX, double finalY)
    : pOrigen(origenX, origenY), pFinal(finalX, finalY)
{    
}

Vector Vector::suma2Vectores(Vector v2){
    // Sumar inicio (x, y) y finales (x, y)
    double sumaOrigX = pOrigen.getX() + v2.pOrigen.getX(),
           sumaOrigY = pOrigen.getY() + v2.pOrigen.getY(),
           sumaFinX  = pFinal.getX() + v2.pFinal.getX(),
           sumaFinY  = pFinal.getY() + v2.pFinal.getY();
    Vector v3(sumaOrigX, sumaOrigY, sumaFinX, sumaFinY);
    return v3;
}

void Vector::print(){
    std::cout << "Origen en: ";
    pOrigen.print();
    std::cout << "Final en: ";
    pFinal.print();
}


Vector Vector::operator +(Vector v2){ // Sobrecargando operador (+)
    return Vector(pOrigen.getX(), pOrigen.getY(),
            pFinal.getX() + v2.pFinal.getX(),
            pFinal.getY() + v2.pFinal.getY());
}