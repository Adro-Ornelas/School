/* 
 * File:   LSLCIRCIVCNC.h
 * Author: Adro Ornelas
 *
 * Created on 20 de septiembre de 2024, 01:01 PM
 */

#ifndef LSLCIRCIVCNC_H
#define LSLCIRCIVCNC_H

#include "LSLCIRCIVSNC.h"

class LSLCIRCIVCNC : public LSLCIRCIVSNC
{
public:
    LSLCIRCIVCNC();
    virtual ~LSLCIRCIVCNC();
    
    int  cardinalidad();
    void despliega();
    bool eliminar(int dato);
    bool esElemento(int dato);
    bool esVacia();
    bool insertar(int dato);  
private:
};

#endif /* LSLCIRCIVCNC_H */

