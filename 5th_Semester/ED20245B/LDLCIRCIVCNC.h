/* 
 * File:   LDLCIRCIVCNC.h
 * Author: Adro Ornelas
 *
 * Created on 22 de octubre de 2024, 11:47 PM
 */

#ifndef LDLCIRCIVCNC_H
#define LDLCIRCIVCNC_H

#include "LDLCIRCIPCNC.h"

class LDLCIRCIVCNC : public LDLCIRCIPCNC {
public:
    // Heredo

    bool eliminar(int dato);
    bool insertar(int dato);
    
};

#endif /* LDLCIRCIVCNC_H */

