/* 
 * File:   Vector.h
 * Author: Adro Ornelas
 *
 * Created on 8 de marzo de 2024, 09:57 AM
 */

#ifndef VECTOR_H
#define VECTOR_H
#include "Punto.h"

class Vector {
private:
    Punto pOrigen;
    Punto pFinal;
public:
    Vector(double, double, double, double);
    Vector suma2Vectores(Vector v2);
    void print();
    Vector operator +(Vector); // Sobrecargando operador (+)
    
};

#endif /* VECTOR_H */

