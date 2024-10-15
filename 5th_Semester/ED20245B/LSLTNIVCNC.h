/* 
 * File:   LSLTNIVCNC.h
 * Author: Adro Ornelas
 *
 * Created on 20 de septiembre de 2024, 08:07 AM
 */

#ifndef LSLTNIVCNC_H
#define LSLTNIVCNC_H

#include "LSLTNIVSNC.h"

class LSLTNIVCNC : public LSLTNIVSNC{
public:
    LSLTNIVCNC();
    virtual ~LSLTNIVCNC();
    int  cardinalidad();
    void despliega();
    bool eliminar(int dato);
    bool esElemento(int dato);
    bool esVacia();
    bool insertar(int dato);
private:

};

#endif /* LSLTNIVCNC_H */

