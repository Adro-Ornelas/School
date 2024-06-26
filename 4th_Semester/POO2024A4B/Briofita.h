/* 
 * File:   Briofita.h
 * Author: Adro Ornelas
 *
 * Created on 14 de mayo de 2024, 01:58 PM
 */

#ifndef BRIOFITA_H
#define BRIOFITA_H

#include "Planta.h"

class Briofita : public Planta{
protected:
    string sustrato;   
public:
    Briofita(string nomCi, string nomVu, bool esVasc, bool esFlor);
    void print();
    void virtual formaReproduccion(string repro) = 0;
    void virtual obtenerEnergia(string energy) = 0;
    void virtual tipoDeSustrato(string sustrat) = 0;
    void virtual vascular(bool es) = 0;
    void virtual floral(bool es) = 0;
};

#endif /* BRIOFITA_H */

