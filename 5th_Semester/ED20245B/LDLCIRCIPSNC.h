/* 
 * File:   LDLCIRCIPSNC.h
 * Author: Adro Ornelas
 *
 * Created on 24 de octubre de 2024, 04:13 PM
 */

#ifndef LDLCIRCIPSNC_H
#define LDLCIRCIPSNC_H

#include "LDLCIRCIVSNC.h"

class LDLCIRCIPSNC : public LDLCIRCIVSNC {
public:
    
    // Heredo 
    
    bool eliminar(int *dato, int pos);
    bool insertar(int dato, int pos);
private:

};

#endif /* LDLCIRCIPSNC_H */

