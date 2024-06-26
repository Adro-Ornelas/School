/* 
 * File:   Escaleno.h
 * Author: Adro Ornelas
 *
 * Created on 17 de junio de 2024, 02:08 PM
 */

#ifndef ESCALENO_H
#define ESCALENO_H

#include "PoligonoIrregular.h"

class Escaleno : public PoligonoIrregular {
private:
    double lado1, lado2, lado3;
public:
    Escaleno(double, double, double);
    void area();
    void perimetro();
    void presentar();
};

#endif /* ESCALENO_H */

