/* 
 * File:   Ortoedro.h
 * Author: Adro Ornelas
 *
 * Created on 23 de febrero de 2024, 09:54 AM
 */

#ifndef ORTOEDRO_H
#define ORTOEDRO_H
#include "Rectangulo.h"

class Ortoedro {
private:
    Rectangulo miRectangle;
    int ancho;
    
public:
    Ortoedro(int height, int length, int);
    int volumen();
    int area();


};

#endif /* ORTOEDRO_H */

