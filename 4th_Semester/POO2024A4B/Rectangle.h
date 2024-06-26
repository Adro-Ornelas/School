/* 
 * File:   Rectangle.h
 * Author: Adro Ornelas
 *
 * Created on 17 de junio de 2024, 02:08 PM
 */

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "PoligonoRegular.h"

class Rectangle : public PoligonoRegular {
public:
    Rectangle(double);
    void presentar();
    void area();
    void perimetro();
};

#endif /* RECTANGLE_H */

