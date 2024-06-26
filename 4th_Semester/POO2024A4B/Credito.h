/* 
 * File:   Credito.h
 * Author: Adro Ornelas
 *
 * Created on 2 de junio de 2024, 04:42 PM
 */

#ifndef CREDITO_H
#define CREDITO_H

#include <iostream>

using namespace std;

class Credito {

protected:
    bool    vencido;
    int     pago;
    int     valorCredito;
    double  interesNormal;
    double  interesMoratorio;
    int     saldoDisponible;
public:
    Credito(bool vencid, int valor);
    void print();
    void virtual interesesNormales(double interes) = 0;
    void virtual interesesMorosos(double interes) = 0;
    void virtual pagos(double pago) = 0;
    void virtual disposiciones(double dipos) = 0;
};

#endif /* CREDITO_H */