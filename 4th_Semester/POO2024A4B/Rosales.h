/* 
 * File:   Rosales.h
 * Author: Adro Ornelas
 *
 * Created on 14 de mayo de 2024, 01:59 PM
 */

#ifndef ROSALES_H
#define ROSALES_H

#include "Angiosperma.h"

class Rosales : public Angiosperma {
protected:
    int intensidadAroma;
public:
    Rosales(string nomCi, string nomVu, bool esVasc, bool esFlor,
            int intensidadA, string repro, string energy, string peFlor);
    void print();
    void formaReproduccion(string repro);
    void obtenerEnergia(string energy); 
    void periodoFlor(string peFloracion);
    void vascular(bool es);
    void floral(bool es);
};

#endif /* ROSALES_H */

