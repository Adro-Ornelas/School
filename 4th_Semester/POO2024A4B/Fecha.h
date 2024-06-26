/* 
 * File:   Fecha.h
 * Author: Adro Ornelas
 *
 * Created on 16 de febrero de 2024, 02:53 PM
 */

#ifndef FECHA_H
#define FECHA_H

class Fecha {
private:
    int a, d, m;
    int dpmonth;
    int fec;
public:
    Fecha(int f);
    void print();    
    int day();
    int month();
    int year();

};

#endif /* FECHA_H */

