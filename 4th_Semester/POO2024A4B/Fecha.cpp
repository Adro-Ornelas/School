#include "Fecha.h"
#include <iostream>

Fecha::Fecha(int fechaComp)
{
    fec = fechaComp;
    d = day();
    m = month();
    a = year();
}

void Fecha::print(){
    std::cout.width(2);
    std::cout.fill('0');
    std::cout << d << '/';
    std::cout.width(2);
    std::cout.fill('0');
    std::cout << m << '/' << a;
}

int Fecha::year(){
    return (fec % 10000);
}
int Fecha::month(){
    return (fec / 10000) % 100;
}
int Fecha::day(){
    return (fec / 1000000);    
}