/* 
 * File:   Muebles.h
 * Author: Adro Ornelas
 *
 * Created on 14 de junio de 2024, 08:51 AM
 */

#ifndef MUEBLES_H
#define MUEBLES_H

#include "Bien.h"
class Muebles : public Bien{
protected:
    int anioOriginal;
    int anioActual;
public:
    Muebles(double val, int aO, int aA);
    void amortizar();
    void print();
};

#endif /* MUEBLES_H */

