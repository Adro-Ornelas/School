/* 
 * File:   GestorContable.cpp
 * Author: Adro Ornelas
 * 
 * Created on 14 de junio de 2024, 08:51 AM
 */

#include "GestorContable.h"

GestorContable::GestorContable() {
}

void GestorContable::imprimeBien(Bien *unBien){
    unBien->amortizar();    // Para acceder al método de un apuntador de clase
    unBien->print();
    cout << *unBien;
}

