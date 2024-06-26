#include "Circulo.h"
#include <cmath>
#include <iostream>

Circulo::Circulo(double coordX, double coordY, double rad)
    : centro(coordX, coordY)
{
    radio = rad;
}


double Circulo::area(){
    return pow(M_PI * radio, 2);
}

double Circulo::perimetro(){
    return 2 * M_PI * radio;
}

void Circulo::print(){
    std::cout << "Círculo con centro en ";
    centro.print();
    std::cout << "\nradio: " << radio;
}

double Circulo::obtenerradio(){
    return radio;
}