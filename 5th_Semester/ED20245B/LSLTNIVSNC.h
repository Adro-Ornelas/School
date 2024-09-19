/* 
 * File:   LSLTNIVSNC.h
 * Author: Adro Ornelas
 *
 * Created on 23 de agosto de 2024, 07:35 PM
 */

#ifndef LSLTNIVSNC_H
#define LSLTNIVSNC_H

struct Nodo // La estructura nodo contiene un entero y un apuntador a otro nodo
{
    int dato;
    struct Nodo* pNext;
};

class LSLTNIVSNC {
protected:
    struct Nodo* p; // Principio
public:
    LSLTNIVSNC();
    ~LSLTNIVSNC();
    bool eliminar(int dato);
    bool insertar(int dato);
    bool esElemento(int dato);
    int  cardinalidad(); // Cuantos nodos
    bool esVacia();
    void despliega();
private:

};

#endif /* LSLTNIVSNC_H */

