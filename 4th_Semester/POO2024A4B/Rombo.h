/* 
 * File:   Rombo.h
 * Author: Adro Ornelas
 *
 * Created on 17 de junio de 2024, 02:08 PM
 */

#ifndef ROMBO_H
#define ROMBO_H

#include "PoligonoIrregular.h"

class Rombo : public PoligonoIrregular {
private:
    double diagonal1, diagonal2;
public:
    Rombo(double diagonal1, double diagonal2);
    
    void area();
    void perimetro();
    void presentar();
};

#endif /* ROMBO_H */

