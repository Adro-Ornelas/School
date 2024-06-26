/* 
 * File:   Credito.cpp
 * Author: Adro Ornelas
 * 
 * Created on 2 de junio de 2024, 04:42 PM
 */

#include "Credito.h"

Credito::Credito(bool vencid, int valor) {
    vencido = vencid;
    valorCredito = valor;
    
}

void Credito::print(){
    cout << "Este crédito tiene un valor de $ " << valorCredito << endl;
}

