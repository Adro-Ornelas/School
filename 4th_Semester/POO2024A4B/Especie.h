/* 
 * File:   Especie.h
 * Author: Adro Ornelas
 *
 * Created on 23 de abril de 2024, 01:48 PM
 */

#ifndef ESPECIE_H
#define ESPECIE_H

#include <iostream>

using std::string;
using std::cout;
using std::endl;
//using namespace std;

class Especie {
protected:
    string nombreCientifico;
    string nombreVulgar;
    string tipoReproduccion;
    string energia;
private:
    
public:
    Especie(string nomCi, string nomVu);
    void print();
    void virtual formaReproduccion(string repro) = 0;
    void virtual obtenerEnergia(string energy) = 0; // 0 porque es puro
};

#endif /* ESPECIE_H */

