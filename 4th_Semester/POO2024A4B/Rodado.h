/* 
 * File:   Rodado.h
 * Author: Adro Ornelas
 *
 * Created on 7 de junio de 2024, 03:02 PM
 */
#ifndef RODADO_H
#define RODADO_H

#include "Bien.h"

class Rodado : public Bien{
protected:
    int kilometraje;        
public:
    Rodado(double, int);
    void print();
    void amortizar();
};

#endif /* RODADO_H */
 

