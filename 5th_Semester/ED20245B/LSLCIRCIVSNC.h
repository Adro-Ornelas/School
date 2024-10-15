/* 
 * File:   LSLCIRCIVSNC.h
 * Author: PatoServer
 *
 * Created on 31 de agosto de 2024, 11:51 AM
 */

#ifndef LSLCIRCIVSNC_H
#define LSLCIRCIVSNC_H

#include "LSLTNIVSNC.h"

class LSLCIRCIVSNC : public LSLTNIVSNC{
protected:
    struct Nodo* p; // Start
public:
    LSLCIRCIVSNC();
    ~LSLCIRCIVSNC();
    int  cardinalidad();
    void despliega();
    bool eliminar(int dato);
    bool esElemento(int dato);
    bool esVacia();
    bool insertar(int dato);    
};

#endif /* LSLCIRCIVSNC_H */

