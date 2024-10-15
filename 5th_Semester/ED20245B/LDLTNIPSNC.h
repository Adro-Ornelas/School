/* 
 * File:   LDLTNIPSNC.h
 * Author: Adro Ornelas
 *
 * Created on 4 de octubre de 2024, 01:23 PM
 */

#ifndef LDLTNIPSNC_H
#define LDLTNIPSNC_H

#include "LDLCIRCIPCNC.h"

class LDLTNIPSNC : public LDLCIRCIPCNC{
public:
    LDLTNIPSNC();
    virtual ~LDLTNIPSNC();

    int  cardinalidad();
    void despliega();
    bool eliminar(int *dato, int pos);
    bool esElemento(int dato);
    bool esVacia();
    bool insertar(int dato, int pos);
};

#endif /* LDLTNIPSNC_H */

