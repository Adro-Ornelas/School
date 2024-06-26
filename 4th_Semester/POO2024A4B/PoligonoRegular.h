/* 
 * File:   PoligonoRegular.h
 * Author: Adro Ornelas
 *
 * Created on 17 de junio de 2024, 02:07 PM
 */

#ifndef POLIGONOREGULAR_H
#define POLIGONOREGULAR_H

#include "Poligono.h"

class PoligonoRegular : public Poligono{
protected:
    double longitudLado; // Poligono regular: todos los lados miden lo mismo
    int numLados;
public:
    PoligonoRegular(double);
    virtual void area() = 0;
    virtual void perimetro() = 0;
    virtual void presentar() = 0;
};

#endif /* POLIGONOREGULAR_H */

