/* 
 * File:   TarjetaDeCredito.h
 * Author: Adro Ornelas
 *
 * Created on 2 de junio de 2024, 04:42 PM
 */

#ifndef TARJETADECREDITO_H
#define TARJETADECREDITO_H

#include "Credito.h"

class TarjetaDeCredito : public Credito {
public:
    TarjetaDeCredito(bool vencid, int valor, int interesNorm, int interesMor,
                     double pago, double dispos);
    void print();
    void interesesNormales(double interes);
    void interesesMorosos(double interes);
    void pagos(double pago);
    void disposiciones(double dispos);
};

#endif /* TARJETADECREDITO_H */

