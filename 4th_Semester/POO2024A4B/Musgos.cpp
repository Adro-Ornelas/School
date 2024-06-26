/* 
 * File:   Musgos.cpp
 * Author: Adro Ornelas
 * 
 * Created on 14 de mayo de 2024, 01:59 PM
 */

#include "Musgos.h"

Musgos::Musgos(string nomCi, string nomVu, bool esVasc, bool esFlor,
              string sustrat, string repro, string energy)
    : Briofita(nomCi, nomVu, esVasc, esFlor)
{
    formaReproduccion(repro);
    obtenerEnergia(energy);
    tipoDeSustrato(sustrat);
    vascular(esVasc);
    floral(esFlor);
}

void Musgos::print(){
    Briofita::print();
}

void Musgos::formaReproduccion(string repro){
    tipoReproduccion = repro;
}
void Musgos::obtenerEnergia(string energy){
    energia = energy;
}
void Musgos::tipoDeSustrato(string sustrat){
    sustrato = sustrat;
}
void Musgos::vascular(bool es){
    esVascular = es;
}
void Musgos::floral(bool es){
    esFloral = es;
}


