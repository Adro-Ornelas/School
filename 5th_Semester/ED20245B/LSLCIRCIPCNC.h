/* 
 * File:   LSLCIRCIPCNC.h
 * Author: PatoServer
 *
 * Created on 18 de septiembre de 2024, 06:43 PM
 */

#ifndef LSLCIRCIPCNC_H
#define LSLCIRCIPCNC_H

#include "LSLTNIVSNC.h"

class LSLCIRCIPCNC : public LSLTNIVSNC {
public:
    LSLCIRCIPCNC();
    virtual ~LSLCIRCIPCNC();
    int  cardinalidad();
    void despliega();
    bool eliminar(int *dato, int pos);
    bool esElemento(int dato);
    bool esVacia();
    bool insertar(int dato, int pos);
private:

};

#endif /* LSLCIRCIPCNC_H */

