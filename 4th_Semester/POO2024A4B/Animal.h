/* 
 * File:   Animal.h
 * Author: Adro Ornelas
 *
 * Created on 23 de abril de 2024, 02:24 PM
 */

#ifndef ANIMAL_H
#define ANIMAL_H

#include "Especie.h"
#include "Fecha.h"

class Animal : public Especie{
protected:
        int diasCuidado;
        Fecha bornDate, deceaseDate;
        int esperanzaVida;
        bool vivo;
public:
    Animal(string nomCi, string nomVu, int fecnacimiento, int fecmuerte,
            int eV, bool alive);
    void print();
    void virtual diasSobrevivenciaCrias(int dsc) = 0;
    void virtual formaReproduccion(string repro) = 0;
    void virtual obtenerEnergia(string energy) = 0;
};

#endif /* ANIMAL_H */

