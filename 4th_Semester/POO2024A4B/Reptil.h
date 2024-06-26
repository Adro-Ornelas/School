/* 
 * File:   Reptil.h
 * Author: Adro Ornelas
 *
 * Created on 22 de mayo de 2024, 02:01 PM
 */

#ifndef REPTIL_H
#define REPTIL_H

#include "Animal.h"

class Reptil : public Animal {
protected:
    bool esTerrestre;
    
public:
    Reptil(string nomCi, string nomVu, int fecnacimiento, int fecmuerte,
            int eV, bool alive, bool esTerr);
    void print();
    void virtual diasSobrevivenciaCrias(int dsc) = 0;
    void virtual formaReproduccion(string repro) = 0;
    void virtual obtenerEnergia(string energy) = 0;
};

#endif /* REPTIL_H */

