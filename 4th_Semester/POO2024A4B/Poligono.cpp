/* 
 * File:   Poligono.cpp
 * Author: Adro Ornelas
 * 
 * Created on 17 de junio de 2024, 02:07 PM
 */

#include "Poligono.h"

using namespace std;

Poligono::Poligono() {
}

ostream &operator<<(ostream &output, const Poligono &figura){
    output << "El área es de " << figura.Farea << endl
           << "El perímetro es de " << figura.Fperimetro << endl;
    return output;
}

