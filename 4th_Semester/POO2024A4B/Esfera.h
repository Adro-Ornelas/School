/* 
 * File:   Esfera.h
 * Author: Adro Ornelas
 *
 * Created on 10 de febrero de 2024, 08:45 PM
 */
#ifndef ESFERA_H
#define ESFERA_H
#include "Circulo.h"

class Esfera {    
private:
    Circulo miCirculo;    
public:
    Esfera(double, double, double);
    double area();
    double volumen();
};

#endif /* ESFERA_H */

