/* 
 * File:   Anfibio.h
 * Author: Adro Ornelas
 *
 * Created on 28 de abril de 2024, 08:12 AM
 */

#ifndef ANFIBIO_H
#define ANFIBIO_H

#include "Animal.h"

class Anfibio : public Animal {

protected:
        int tiempoBranqueas;
public:
    Anfibio(string nomCi, string nomVu, int fecNacimiento, int fecMuerte,
            int eV, bool alive);
    
    void print();
    void virtual timeBranqueas(int time) = 0;
    void virtual diasSobrevivenciaCrias(int dsc) = 0;
    void virtual formaReproduccion(string repro) = 0;
    void virtual obtenerEnergia(string energy) = 0;
};

#endif /* ANFIBIO_H */

