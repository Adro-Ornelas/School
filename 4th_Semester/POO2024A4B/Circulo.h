#ifndef CIRCULO_H
#define CIRCULO_H

#include "Punto.h"

class Circulo {
protected:
    double radio;
private:
    Punto centro;
public:
    Circulo(double coordX, double coordY, double rad);
    double area();
    void   print();
    double perimetro();
    double obtenerradio();
    
};

#endif /* CIRCULO_H */

