
/* 
 * File:   Terreno.h
 * Author: Adro Ornelas
 *
 * Created on 14 de junio de 2024, 09:01 AM
 */

#ifndef TERRENO_H
#define TERRENO_H

#include "Bien.h"

class Terreno : public Bien{
public:
    Terreno(double valor);
    void amortizar();
    void print();
};

        
#endif /* TERRENO_H */

