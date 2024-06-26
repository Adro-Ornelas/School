/* 
 * File:   Cilindro.h
 * Author: Adro Ornelas
 */
#ifndef CILINDRO_H
#define CILINDRO_H

#include "Circulo.h"

class Cilindro : public Circulo {
protected:
    int height;
public:
    Cilindro(double coordX, double coordY, double rad, double altura);
    double area();
    double volumen();
    void print();

};

#endif /* CILINDRO_H */

