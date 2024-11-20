/* 
 * File:   LDLCIRCIVCNC.cpp
 * Author: Adro Ornelas
 * 
 * Created on 22 de octubre de 2024, 11:47 PM
 */

#include "LDLCIRCIVCNC.h"
#include <cstdlib>
#include <iostream>
using namespace std;

bool LDLCIRCIVCNC::eliminar(int dato) {
    
    if(esVacia())
        return false;
    struct NodoD *ptmp = p->pder; 
    while(ptmp != p && ptmp->dato != dato)
        ptmp = ptmp->pder;        
    
    if(ptmp->dato != dato)
        return false;
    
    // Que lista deje de apuntar a nodo
    ptmp->pizq->pder = ptmp->pder;
    ptmp->pder->pizq = ptmp->pizq;
    free(ptmp);
    return true;
   
}

bool LDLCIRCIVCNC::insertar(int dato) {
    
    struct NodoD *pNue = (struct NodoD*)malloc(sizeof(struct NodoD));
    if(pNue == NULL)
        return false;
    pNue->dato = dato;
    
    struct NodoD *ptmp = p->pder;
    
    while(ptmp != p && ptmp->dato < dato)
        ptmp = ptmp->pder;        
            
    // Que nodo apunte a la lista
    pNue->pizq = ptmp->pizq;
    pNue->pder = ptmp;
    
    // Que lista apunte a nodo
    ptmp->pizq->pder = pNue;
    ptmp->pizq = pNue;
    
    return true;
}


