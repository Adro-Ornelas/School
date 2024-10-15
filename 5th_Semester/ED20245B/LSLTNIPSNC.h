/* 
 * File:   LSLTNIPSNC.h
 * Author: Adro Ornelas
 *
 * Created on 8 de octubre de 2024, 02:09 AM
 */

#ifndef LSLTNIPSNC_H
#define LSLTNIPSNC_H

#include "LSLTNIVSNC.h"

class LSLTNIPSNC : public LSLTNIVSNC {
public:
    // HEREDO CONSTRUCTOR
    // HEREDO DESTRUCTOR
    // HEREDO cardinalidad()
    // HEREDO despliega()
    // HEREDO esElemento()
    // HEREDO esVacia()

    bool eliminar(int *dato, int pos);
    bool insertar(int dato, int pos);

};

#endif /* LSLTNIPSNC_H */

