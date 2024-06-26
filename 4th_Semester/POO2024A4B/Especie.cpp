/* 
 * File:   Especie.cpp
 * Author: Adro Ornelas
 * 
 * Created on 23 de abril de 2024, 01:48 PM
 */

#include "Especie.h"

Especie::Especie(string nomCi, string nomVu)
{
    nombreCientifico = nomCi;
    nombreVulgar = nomVu;
}


void Especie::print(){
    cout << "Esta especie tiene el nombre científico: "
              << nombreCientifico << " se conoce como "
              << nombreVulgar << ".\nSe reproduce de manera "
              << tipoReproduccion << ".\nObtiene su energía al ser "
              << energia << "\n";
}


