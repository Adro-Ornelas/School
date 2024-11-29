/* 
 * File:   ABB.h
 * Author: Adro Ornelas
 *
 * Created on 7 de noviembre de 2024, 10:58 AM
 */


#ifndef ABB_H
#define ABB_H

#include <iostream>

struct NodoA {
    int dato;
    struct NodoA *pizq;
    struct NodoA *pder;
};

class ABB {
protected:
    struct NodoA *p;
    void inOrden(struct NodoA *);
    void inPreorden(struct NodoA *);
    void inPosorden(struct NodoA *);
    int  cardinalidad(struct NodoA *);
    bool inserta(struct NodoA *ptmp, struct NodoA *pNue);
    bool esElemento(struct NodoA *ptmp, int dato);
    bool elimina(struct NodoA *ptmp, struct NodoA *pold, int dato);
    int altura(struct NodoA* ptmp);
    void imprimirArbol(struct NodoA* ptmp, int nivel, std::string);
    
public:
    ABB();
    virtual ~ABB();
    
    // Interfaz de la clase 
    bool esVacia();
    void despliega();
    int cardinalidad();
   
    bool inserta(int dato); // SIEMPRE INSERTA NODO HOJA
    bool esElemento(int dato);
    bool elimina(int dato);
    void printTree();
    void imprimirArbol();
};

#endif /* ABB_H */

