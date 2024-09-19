/* 
 * File:   LSLTNIPCNC.h
 * Author: PatoServer
 *
 * Created on 18 de septiembre de 2024, 07:25 PM
 */

#ifndef LSLTNIPCNC_H
#define LSLTNIPCNC_H

#include "LSLTNIVSNC.h"

class LSLTNIPCNC : public LSLTNIVSNC{
public:
    LSLTNIPCNC();
    virtual ~LSLTNIPCNC();
    int  cardinalidad();
    void despliega();
    bool eliminar(int *dato, int pos);
    bool esElemento(int dato);
    bool esVacia();
    bool insertar(int dato, int pos);
private:

};

#endif /* LSLTNIPCNC_H */

