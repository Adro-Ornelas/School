/* 
 * File:   Triangle.h
 * Author: Adro Ornelas
 *
 * Created on 17 de junio de 2024, 02:08 PM
 */

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "PoligonoRegular.h"

class Triangle : public PoligonoRegular{
public:
    Triangle(double);
    void presentar();
    void area();
    void perimetro();
};

#endif /* TRIANGLE_H */

