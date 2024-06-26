/* 
 * File:   Rana.h
 * Author: Adro Ornelas
 *
 * Created on 28 de abril de 2024, 08:12 AM
 */

#ifndef RANA_H
#define RANA_H

#include "Anfibio.h"

class Rana : public Anfibio {
protected:
    double alturaSalto;
public:
    Rana(string nomCi, string nomVu, int fecNacimiento, int fecMuerte,
            int eV, bool alive, int timeBr, double alturaJump,
            string repro, string ener);
    
    void print();
    void timeBranqueas(int time);
    void diasSobrevivenciaCrias(int dsc);
    void formaReproduccion(string repro);
    void obtenerEnergia(string energy);

};

#endif /* RANA_H */

