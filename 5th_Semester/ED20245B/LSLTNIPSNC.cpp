/* 
 * File:   LSLTNIPSNC.cpp
 * Author: Adro Ornelas
 * 
 * Created on 8 de octubre de 2024, 02:09 AM
 */

#include "LSLTNIPSNC.h"
#include "stdlib.h"
// Heredo constructor

bool LSLTNIPSNC::eliminar(int *dato, int pos) {
    
    if(esVacia())
        return false;
    
    struct Nodo *pold, *ptmp;
    int miPos = 1;
    pold = ptmp = p;
    
    while(ptmp != NULL && miPos != pos) {
        ++miPos;
        pold = ptmp;
        ptmp = ptmp->pNext;
    }
    
    if(miPos != pos)
        return false;
   
    *dato = ptmp->dato;
    // Que lista deje de apuntar a nodo
    if(ptmp == pold)    // 1era posicion
        p = ptmp->pNext;
    else
        pold->pNext = ptmp->pNext;
    
    free(ptmp);
    return true;    
}

bool LSLTNIPSNC::insertar(int dato, int pos) {
    
    struct Nodo *pNue = (struct Nodo*)malloc(sizeof(struct Nodo));
    if(pNue == NULL)
        return false;
    pNue->dato = dato;
    
    int miPos = 1;
    struct Nodo *ptmp, *pold;
    ptmp = pold = p;
    while(ptmp != NULL && miPos != pos){
        ++miPos;
        pold = ptmp;
        ptmp = ptmp->pNext;
    }
    if(miPos != pos){
        free(pNue);
        return false;
    }
    // Que nodo apunte a lista
    pNue->pNext = ptmp;
    
    // Que lista apunte a nodo
    if(pold == NULL || pold == ptmp) // 1er nodo ó primera posición
        p = pNue;
    else 
        pold->pNext = pNue;
    
}