#include "Punto.h"
#include <iostream>
#include <cmath>

Punto::Punto(){
    x = y = 0;
}
Punto::Punto(double coord_x, double coord_y) {
    x = coord_x;
    y = coord_y;
}

void Punto::print(){
    std::cout << '(' << x << ',' << y << ')';
}

double Punto::distancia(Punto punto2){
    return sqrt(pow(punto2.x - x, 2) + pow(punto2.y - y, 2));
}

double Punto::getX(){
    return x;
}
double Punto::getY(){
    return y;
}
