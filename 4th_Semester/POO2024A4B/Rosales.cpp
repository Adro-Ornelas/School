/* 
 * File:   Rosales.cpp
 * Author: Adro Ornelas
 * 
 * Created on 14 de mayo de 2024, 01:59 PM
 */

#include "Rosales.h"

Rosales::Rosales(string nomCi, string nomVu, bool esVasc, bool esFlor,
            int intensidadA, string repro, string energy, string peFlor)
    : Angiosperma(nomCi, nomVu, esVasc, esFlor)
{
    intensidadAroma = intensidadA;
    formaReproduccion(repro);
    obtenerEnergia(energy);
    periodoFlor(peFlor);
    vascular(esVasc);
    floral(esFlor);
}


void Rosales::print(){
    Angiosperma::print();
    cout << "¿Y esta rosa?, tiene una intensidad de aroma de "
         << intensidadAroma;
}

void Rosales::formaReproduccion(string repro){
    tipoReproduccion = repro;
}
void Rosales::obtenerEnergia(string energy){
    energia = energy;
}
void Rosales::periodoFlor(string peFloracion){
   periodoFloracion = peFloracion;
}
void Rosales::vascular(bool es){
    esVascular = es;
}
void Rosales::floral(bool es){
    esFloral = es;
}