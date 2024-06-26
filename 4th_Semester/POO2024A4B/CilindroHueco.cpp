/* 
 * File:   CilindroHueco.cpp
 * Author: Adro Ornelas
 * 
 * Created on 18 de abril de 2024, 11:58 PM
 */
#include <iostream>
#include <cmath>
#include "CilindroHueco.h"

CilindroHueco::CilindroHueco(double coordX, double coordY, double rad,
                double altura, double radio_in)
    : Cilindro(coordX, coordY, rad, altura)
{
    radio_interior = radio_in;
}

double CilindroHueco::area(){
    return 2 * M_PI * (pow(radio, 2) - pow(radio_interior, 2))
            + Circulo::perimetro() * height
            + 2 * M_PI * radio_interior * height;
}

double CilindroHueco::volumen(){
    return M_PI * (pow(radio, 2) - pow(radio_interior, 2)) * height;
}

double CilindroHueco::print(){
    Cilindro::print();
    std::cout << "\nPero el radio interior de " << radio_interior
              << " lo convierte en un cilindro hueco";
    
}
