/* 
 * File:   LDLTNIPCNC.h
 * Author: PatoServer
 *
 * Created on 31 de octubre de 2024, 05:44 PM
 */

#ifndef LDLTNIPCNC_H
#define LDLTNIPCNC_H

#include "LDLTNIVCNC.h"

class LDLTNIPCNC : public LDLTNIVCNC{
public:
    LDLTNIPCNC();
    virtual ~LDLTNIPCNC();
    bool eliminar(int *dato, int pos);
    bool insertar(int dato, int pos);
private:

};

#endif /* LDLTNIPCNC_H */

