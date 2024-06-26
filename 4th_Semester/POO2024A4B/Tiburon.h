/* 
 * File:   Tiburon.h
 * Author: Adro Ornelas
 *
 * Created on 23 de abril de 2024, 02:26 PM
 */

#ifndef TIBURON_H
#define TIBURON_H

#include "Pez.h"

class Tiburon : public Pez{

protected:
    int filasDientes;
        
public:
    Tiburon(string nomCi, string nomVu, int fecNacimiento, int fecMuerte,
            int eV, bool alive, int fd, bool eAD, int dcc, string repro, string ener);
    
    void print();
    void aguaDulce(bool ad);
    void diasSobrevivenciaCrias(int dsc);  // Se concretan las funciones abstracttas
    void formaReproduccion(string repro);
    void obtenerEnergia(string energy);
};

#endif /* TIBURON_H */

