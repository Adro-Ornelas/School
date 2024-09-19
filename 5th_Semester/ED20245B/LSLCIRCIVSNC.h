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
    bool eliminar(int dato);
    bool insertar(int dato);
    int  cardinalidad();
    bool esElemento(int dato);
    bool esVacia();
    void despliega();
};

#endif /* LSLCIRCIVSNC_H */

