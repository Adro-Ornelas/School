/* 
 * File:   LDLTNIVCNC.h
 * Author: Adro Ornelas
 *
 * Created on 19 de octubre de 2024, 08:55 PM
 */

#ifndef LDLTNIVCNC_H
#define LDLTNIVCNC_H

#include "LDLCIRCIVSNC.h"

class LDLTNIVCNC : public LDLCIRCIVSNC{
public:
    LDLTNIVCNC();
    virtual ~LDLTNIVCNC();
    
    int  cardinalidad();
    void despliega();
    bool eliminar(int dato);
    bool esElemento(int dato);
    bool esVacia();
    bool insertar(int dato);
private:

};

#endif /* LDLTNIVCNC_H */

