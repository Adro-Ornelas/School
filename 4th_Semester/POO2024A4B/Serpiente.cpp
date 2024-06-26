/* 
 * File:   Serpiente.cpp
 * Author: Adro Ornelas
 * 
 * Created on 22 de mayo de 2024, 02:17 PM
 */

#include "Serpiente.h"

Serpiente::Serpiente(string nomCi, string nomVu, int fecnacimiento, int fecmuerte,
            int eV, bool alive, bool esTerr, int vecesMud,
            string repro, string ener)
    : Reptil(nomCi, nomVu, fecnacimiento, fecmuerte, eV, alive, esTerr)
{
    vecesMuda = vecesMud;
    diasSobrevivenciaCrias(0);
    formaReproduccion(repro);
    obtenerEnergia(ener); 
}

void Serpiente::print(){
    Reptil::print();
    cout << "Esta serpiente muda " << vecesMuda
         << " veces de piel por año" << endl;
}

void Serpiente::diasSobrevivenciaCrias(int dsc){
    diasCuidado = dsc;
}

void Serpiente::formaReproduccion(string repro){
    tipoReproduccion = repro;
}

void Serpiente::obtenerEnergia(string energy){
    energia = energy;
}
