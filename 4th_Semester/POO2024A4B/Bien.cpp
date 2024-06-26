/* 
 * File:   Bien.cpp
 * Author: Adro Ornelas
 * 
 * Created on 7 de junio de 2024, 03:02 PM
 */

#include "Bien.h"

Bien::Bien(double valo) {
    valor = valo;
}


void Bien::print(){
    cout << "Este bien tiene un valor original de " << valor << endl;
}

ostream &operator<<(ostream &output, const Bien &obj){
     output << "Se ha depreciado en: "
            << obj.valorDepreciado
            << " y su valor actual es de "
            << obj.valorActual << endl;
    return output; 
}
 

