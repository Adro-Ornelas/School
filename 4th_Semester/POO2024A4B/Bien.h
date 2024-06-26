/* 
 * File:   Bien.h
 * Author: Adro Ornelas
 *
 * Created on 7 de junio de 2024, 03:02 PM
 */

#ifndef BIEN_H
#define BIEN_H


#include <iostream>
using namespace std;

class Bien {
protected:
    double valor;
    double valorDepreciado;
    double factorAmort;
    double valorActual;
public:
    Bien(double);
    void virtual amortizar() = 0;
    void print();
    friend ostream &operator<<(ostream &, const Bien &);

    // sobrecarga el operador << "ostream"
};
#endif /* BIEN_H */

