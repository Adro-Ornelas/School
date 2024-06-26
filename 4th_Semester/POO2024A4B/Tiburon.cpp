/* 
 * File:   Tiburon.cpp
 * Author: Adro Ornelas
 * 
 * Created on 23 de abril de 2024, 02:26 PM
 */

#include "Tiburon.h"

Tiburon::Tiburon(string nomCi, string nomVu, int fecNacimiento, int fecMuerte,
            int eV, bool alive, int fd, bool eAD, int dcc, string repro, string ener) 
    :Pez(nomCi, nomVu, fecNacimiento, fecMuerte, eV, alive)
{
    filasDientes = fd;
    aguaDulce(eAD);
    diasSobrevivenciaCrias(dcc);
    formaReproduccion(repro);
    obtenerEnergia(ener);
}


void Tiburon::print(){
    Pez::print();
    cout << "Este tiburón tiene " << filasDientes
              << " filas de dientes" << std::endl;
}
void Tiburon::aguaDulce(bool ad){
    esAguaDulce = ad;
}
void Tiburon::diasSobrevivenciaCrias(int dsc){
    diasCuidado = dsc;
}
void Tiburon::formaReproduccion(string repro){
    tipoReproduccion = repro;
}
void Tiburon::obtenerEnergia(string energy){
    energia = energy;
}