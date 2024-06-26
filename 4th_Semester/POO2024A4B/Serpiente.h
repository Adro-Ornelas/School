/* 
 * File:   Serpiente.h
 * Author: Adro Ornelas
 *
 * Created on 22 de mayo de 2024, 02:17 PM
 */

#ifndef SERPIENTE_H
#define SERPIENTE_H

#include "Reptil.h"

class Serpiente : public Reptil{
private:
    int vecesMuda;
public:
    Serpiente(string nomCi, string nomVu, int fecnacimiento, int fecmuerte,
            int eV, bool alive, bool esTerr, int vecesMuda, 
            string repro, string ener);
    void print();
    void diasSobrevivenciaCrias(int dsc);
    void formaReproduccion(string repro);
    void obtenerEnergia(string energy);
};

#endif /* SERPIENTE_H */

