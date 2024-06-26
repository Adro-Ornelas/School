/* 
 * File:   PoligonoIrregular.h
 * Author: Adro Ornelas
 *
 * Created on 17 de junio de 2024, 02:07 PM
 */

#ifndef POLIGONOIRREGULAR_H
#define POLIGONOIRREGULAR_H

#include "Poligono.h"

class PoligonoIrregular : public Poligono {
protected:
    
public:
    PoligonoIrregular();
    
    virtual void area() = 0;
    virtual void perimetro() = 0;
    virtual void presentar() = 0;
};

#endif /* POLIGONOIRREGULAR_H */

