/* 
 * File:   LDLCIRCIVSNC.h
 * Author: Adro Ornelas
 *
 * Created on 13 de octubre de 2024, 08:27 AM
 */

#ifndef LDLCIRCIVSNC_H
#define LDLCIRCIVSNC_H

#include "LDLTNIPSNC.h"

class LDLCIRCIVSNC : public LDLTNIPSNC {
public:
    // LDLCIRCIVSNC();
    // virtual ~LDLCIRCIVSNC();
    
    int  cardinalidad();
    void despliega();
    bool eliminar(int dato);
    bool esElemento(int dato);
    // bool esVacia();
    bool insertar(int dato);   
private:

};

#endif /* LDLCIRCIVSNC_H */

