/* 
 * File:   CilindroHueco.h
 * Author: Adro Ornelas
 *
 * Created on 18 de abril de 2024, 11:58 PM
 */

#ifndef CILINDROHUECO_H
#define CILINDROHUECO_H

#include "Cilindro.h"

class CilindroHueco : public Cilindro {
private:
    double radio_interior;
public:
    CilindroHueco(double coordX, double coordY, double rad,
                double altura, double radio_in);
    double area();
    double volumen();
    double print();
};

#endif /* CILINDROHUECO_H */

