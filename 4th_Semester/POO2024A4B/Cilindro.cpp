/* 
 * File:   Cilindro.cpp
 * Author: Adro Ornelas
 * 
 * Created on 13 de febrero de 2024, 02:24 PM
 */

#include <iostream>
#include "Cilindro.h"

Cilindro::Cilindro(double coordX, double coordY, double rad, double altura)
    : Circulo(coordX, coordY, rad)
{
    height = altura;
}


double Cilindro::area(){
    return (Circulo::perimetro() * height) + (2 * Circulo::area());
}

double Cilindro::volumen(){
    return Circulo::area() * height;
}

void Cilindro::print(){
    std::cout << "Este cilindro es un ";
    Circulo::print();
    std::cout << "\nCon altura de " << height;
}
