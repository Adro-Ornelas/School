/* 
 * File:   TarjetaDeCredito.cpp
 * Author: Adro Ornelas
 * 
 * Created on 2 de junio de 2024, 04:42 PM
 */

#include "TarjetaDeCredito.h"

TarjetaDeCredito::TarjetaDeCredito(bool vencid, int valor, int interesNorm,
        int interesMor, double pago, double dispos)
        : Credito(vencid, valor)
{
    interesesNormales(interesNorm);
    interesesMorosos(interesMor);
    pagos(pago);
    disposiciones(dispos); 
}

void TarjetaDeCredito::print(){
    Credito::print();
    
    if(vencido){
        cout << "El monto de este crédito ha vencido en su fecha de pago,\n"
                "por lo que se tendrán que pagar: $ "
                << (interesNormal + interesMoratorio) / 100.0 * valorCredito
                << endl;
    } else {
        cout << "El monto de este crédito ha sido pagado a tiempo,\n"
                "por lo que se tendrán que pagar: $ "
                << interesNormal / 100.0 * valorCredito  << endl;
    }
    
}
void TarjetaDeCredito::interesesNormales(double interes){
    interesNormal = interes;
}
void TarjetaDeCredito::interesesMorosos(double interes){
    interesMoratorio = interes;
}
void TarjetaDeCredito::pagos(double pag){
    TarjetaDeCredito::pago = pag;
}
void TarjetaDeCredito::disposiciones(double dispos){
    saldoDisponible = dispos;
}


