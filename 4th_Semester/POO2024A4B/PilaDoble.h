/* 
 * File:   PilaDoble.h
 * Author: Adro Ornelas
 *
 * Created on 21 de marzo de 2024, 07:30 PM
 */

#ifndef PILADOBLE_H
#define PILADOBLE_H

#include "Pila.h"

class PilaDoble : public Pila{
private:
    int topeInferior;
public:
    PilaDoble();
    int  cardinalidad(int sense);
    bool eliminar(int* num, int sense);
    bool insertar(int num, int sense);
    bool isFull();
    bool isEmpty(int sense);
    bool isThere(int num, int sense);
    void print(int sense);

};

#endif /* PILADOBLE_H */

