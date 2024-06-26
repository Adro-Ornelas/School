/* 
 * File:   Musgos.h
 * Author: Adro Ornelas
 *
 * Created on 14 de mayo de 2024, 01:59 PM
 */

#ifndef MUSGOS_H
#define MUSGOS_H

#include "Briofita.h"

class Musgos : public Briofita{

public:
    Musgos(string nomCi, string nomVu, bool esVasc, bool esFlor,
            string sustrat, string repro, string energy);
    void print();
    void formaReproduccion(string repro);
    void obtenerEnergia(string energy);
    void tipoDeSustrato(string sustrat);
    void vascular(bool es);
    void floral(bool es);
    
};

#endif /* MUSGOS_H */

