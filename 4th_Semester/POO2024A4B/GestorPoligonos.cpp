/* 
 * File:   GestorPoligonos.cpp
 * Author: Adro Ornelas
 * 
 * Created on 17 de junio de 2024, 02:48 PM
 */

#include "GestorPoligonos.h"
using namespace std;
GestorPoligonos::GestorPoligonos() {
}

void GestorPoligonos::imprimirPol(Poligono *pol) {
    pol->presentar();
    pol->area();
    pol->perimetro();
    cout << *pol;    
}
