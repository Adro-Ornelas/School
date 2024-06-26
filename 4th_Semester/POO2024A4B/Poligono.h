/* 
 * File:   Poligono.h
 * Author: Adro Ornelas
 *
 * Created on 17 de junio de 2024, 02:07 PM
 */

#ifndef POLIGONO_H
#define POLIGONO_H

#include <iostream>

#define MAX 50

class Poligono {  
    friend std::ostream &operator<<(std::ostream &, const Poligono &); 
  
protected:
    double Farea;
    double Fperimetro;
public:
    Poligono();
    virtual void area() = 0;
    virtual void perimetro() = 0;
    virtual void presentar() = 0;

};

#endif /* POLIGONO_H */

