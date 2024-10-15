/* 
 * File:   LSLCIRCIPSNC.h
 * Author: Adro Ornelas
 *
 * Created on 20 de septiembre de 2024, 09:43 AM
 */

#ifndef LSLCIRCIPSNC_H
#define LSLCIRCIPSNC_H

#include "LSLCIRCIPCNC.h"

class LSLCIRCIPSNC : public LSLCIRCIPCNC{
public:
    LSLCIRCIPSNC();
    virtual ~LSLCIRCIPSNC();
    
    int  cardinalidad();
    void despliega();
    bool eliminar(int *dato, int pos);
    bool esElemento(int dato);
    bool esVacia();
    bool insertar(int dato, int pos);
private:

};

#endif /* LSLCIRCIPSNC_H */

