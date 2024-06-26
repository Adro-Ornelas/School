/* 
 * File:   Planta.h
 * Author: Adro Ornelas
 *
 * Created on 15 de mayo de 2024, 10:49 PM
 */

#ifndef PLANTA_H
#define PLANTA_H

#include "Especie.h"

class Planta : public Especie{
protected:
    bool esVascular;
    bool esFloral;
public:
    Planta(string nomCi, string nomVu, bool esVasc, bool esFlor);
    void print();
    void virtual formaReproduccion(string repro) = 0;
    void virtual obtenerEnergia(string energy) = 0; 
    void virtual vascular(bool es) = 0;
    void virtual floral(bool es) = 0;
};

#endif /* PLANTA_H */

