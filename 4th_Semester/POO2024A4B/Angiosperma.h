/* 
 * File:   Angiosperma.h
 * Author: Adro Ornelas
 *
 * Created on 14 de mayo de 2024, 01:58 PM
 */

#ifndef ANGIOSPERMA_H
#define ANGIOSPERMA_H

#include "Planta.h"

class Angiosperma : public Planta{
protected:
    string periodoFloracion;
public:
    Angiosperma(string nomCi, string nomVu, bool esVasc, bool esFlor);
    void print();
    void virtual formaReproduccion(string repro) = 0;
    void virtual obtenerEnergia(string energy) = 0; 
    void virtual periodoFlor(string peFloracion) = 0;
    void virtual vascular(bool es) = 0;
    void virtual floral(bool es) = 0;
};

#endif /* ANGIOSPERMA_H */

