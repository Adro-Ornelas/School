/* 
 * File:   Pez.h
 * Author: Adro Ornelas
 *
 * Created on 23 de abril de 2024, 02:25 PM
 */

#ifndef PEZ_H
#define PEZ_H

#include "Animal.h"

class Pez : public Animal {
protected:
    bool esAguaDulce;
public:
    Pez(string nomCi, string nomVu, int fecnacimiento, int fecmuerte,
            int eV, bool alive);
    
    void print();
    void virtual aguaDulce(bool ad) = 0;
    void virtual diasSobrevivenciaCrias(int dsc) = 0;
    void virtual formaReproduccion(string repro) = 0;
    void virtual obtenerEnergia(string energy) = 0;
    
};

#endif /* PEZ_H */

