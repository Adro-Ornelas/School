/* 
 * File:   Hexagon.h
 * Author: Adro Ornelas
 *
 * Created on 17 de junio de 2024, 02:08 PM
 */

#ifndef HEXAGON_H
#define HEXAGON_H

#include "PoligonoRegular.h"

class Hexagon : public PoligonoRegular {
public:
    Hexagon(double);
    void presentar();
    void area();
    void perimetro();
};

#endif /* HEXAGON_H */

