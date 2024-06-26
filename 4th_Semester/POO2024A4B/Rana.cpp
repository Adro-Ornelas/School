/* 
 * File:   Rana.cpp
 * Author: Adro Ornelas
 * 
 * Created on 28 de abril de 2024, 08:12 AM
 */

#include "Rana.h"

Rana::Rana(string nomCi, string nomVu, int fecNacimiento, int fecMuerte,
            int eV, bool alive, int timeBr, double alturaJump, 
            string repro, string ener)
    : Anfibio(nomCi, nomVu, fecNacimiento, fecMuerte, eV, alive)
{
    alturaSalto = alturaJump;
    timeBranqueas(timeBr);
    diasSobrevivenciaCrias(0);
    formaReproduccion(repro);
    obtenerEnergia(ener);    
}


void Rana::print(){
    Anfibio::print();
    cout << "Esta Rana es capaz de saltar " << alturaSalto
         << " metros";
}
void Rana::timeBranqueas(int time){
    tiempoBranqueas = time;
}
void Rana::diasSobrevivenciaCrias(int dsc){
    diasCuidado = dsc;
}
void Rana::formaReproduccion(string repro){
    tipoReproduccion = repro;
}
void Rana::obtenerEnergia(string energy){
    energia = energy;
}


