/* 
 * File:   LDLCIRCIVSNC.cpp
 * Author: Adro Ornelas
 * 
 * Created on 13 de octubre de 2024, 08:28 AM
 */
#include <iostream>
#include <stdlib.h>
#include "LDLCIRCIVSNC.h"
#include "LSLTNIVSNC.h"

using namespace std;

LDLCIRCIVSNC::LDLCIRCIVSNC() {
    p = NULL; // Cuando vacía
}

LDLCIRCIVSNC::~LDLCIRCIVSNC() {
}

int  LDLCIRCIVSNC::cardinalidad() {
    
    if(esVacia())
        return 0;
    
    int elements = 0;
    struct NodoD* ptmp = p;
    do{
        ++elements;
        ptmp = ptmp->pder;
    }while(ptmp != p);
    
    return elements;
}
void LDLCIRCIVSNC::despliega() {

    if(!esVacia()) {

        struct NodoD* ptmp = p;
        do{
            cout << ptmp->dato << '\t';
            ptmp = ptmp->pder;
        } while(ptmp != p);
    }
    cout << endl;
}
bool LDLCIRCIVSNC::eliminar(int dato) {

    if(esVacia()) // Cuando lista vacia
        return false;
    
    struct NodoD *ptmp = p;
    do{
        if(ptmp->dato == dato)
            break;
        ptmp = ptmp->pder;
    } while(ptmp != p);
    
    if(ptmp->dato != dato)  // Elemento inválido
        return false;
    
    if(p->dato == dato)  // Cuando 1er nodo de la lista
        if(p->pizq == p) // Cuando único elemento
            p = NULL;
        else             // Cuando no es el único
        p = p->pder;
    
    // Que lista deje de apuntar a nodo
    ptmp->pizq->pder = ptmp->pder;
    ptmp->pder->pizq = ptmp->pizq;
   
    // Liber nodo
    free(ptmp);

    return true;
}

bool LDLCIRCIVSNC::esElemento(int dato) {
    
    if(esVacia())
        return false;
    
    struct NodoD* ptmp = p;
    do{
        if(dato == ptmp->dato)
            return true;
        ptmp = ptmp->pder;
    } while(ptmp != p);
    
    return false;
}
bool LDLCIRCIVSNC::esVacia() {
    return (p == NULL);
}
bool LDLCIRCIVSNC::insertar(int dato) {
    
    struct NodoD *pNue = (struct NodoD*)malloc(sizeof(struct NodoD));
    if(pNue == NULL)
        return false;
    pNue->dato = dato;
    
    if(esVacia()) { // Cuando lista vacia
        p = pNue;
        p->pder = p->pizq = p;
        return true;
    }
    
    struct NodoD *ptmp = p;
    do{
        if(ptmp->dato > dato)
            break;
        ptmp = ptmp->pder;
    } while(ptmp != p);
    
    if(p->dato > dato)  // Cuando 1era posición
        p = pNue;
    
    // Que nodo nuevo apunte a lista
    pNue->pder = ptmp;
    pNue->pizq = ptmp->pizq;
    
    // Que lista apunte a nodo
    ptmp->pizq->pder = pNue;
    ptmp->pizq = pNue;
    
    return true;
}

