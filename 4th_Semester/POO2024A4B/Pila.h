/* 
 * File:   Pila.h
 * Author: Adro Ornelas
 *
 * Created on 1 de marzo de 2024, 03:13 PM
 */

#ifndef PILA_H
#define PILA_H
#define TAMPILA 10

class Pila {
protected:
    int datos[TAMPILA];
    int tope;
public:
    Pila();
    int  cardinalidad();
    bool eliminar(int* num);
    bool insertar(int num);
    bool isFull();
    bool isEmpty();
    bool isThere(int);
    void print();
};

#endif /* PILA_H */

