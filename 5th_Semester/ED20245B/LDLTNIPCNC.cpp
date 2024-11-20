/* 
 * File:   LDLTNIPCNC.cpp
 * Author: PatoServer
 * 
 * Created on 31 de octubre de 2024, 05:44 PM
 */

#include "LDLTNIPCNC.h"

#include <iostream>
#include <stdlib.h>

using namespace std;

LDLTNIPCNC::LDLTNIPCNC() {
}

LDLTNIPCNC::~LDLTNIPCNC() {
}


bool LDLTNIPCNC::eliminar(int *dato, int pos){
    
    if(esVacia())
        return false;
    
    struct NodoD *ptmp = p->pder;
    int miPos = 1;
    
    while(ptmp != NULL){
        
        if(miPos == pos)
            break;
        ++miPos;
        ptmp = ptmp->pder;
    }
    
    if(ptmp == NULL)   // Valor invalido
        return false;
    *dato = ptmp->dato;
    
    // Que lista deje de apuntar a nodo
    ptmp->pizq->pder = ptmp->pder;
    if(ptmp->pder != NULL)
        ptmp->pder->pizq = ptmp->pizq;
    free(ptmp);
    
    return true;
}

bool LDLTNIPCNC::insertar(int dato, int pos){
    
    // Creo nuevo nodo
    struct NodoD *pNue = (struct NodoD*)malloc(sizeof(struct NodoD));
    if(pNue == NULL)
        return false;
    pNue->dato = dato;
    
    struct NodoD *ptmp = p;
    int miPos = 1;
    // Inserta a la derecha de ptmp
    while(ptmp->pder != NULL && miPos < pos){
        ++miPos;
        ptmp = ptmp->pder;
    }
    
    if(miPos != pos){
        free(pNue);
        return false;
    }
    
    // Que nodo nuevo apunte a lista
    pNue->pizq = ptmp;
    pNue->pder = ptmp->pder;
    
    // Que lista apunte a nodo nuevo
    if(ptmp->pder != NULL)
        ptmp->pder->pizq = pNue;
    ptmp->pder = pNue;
    
    return true;
}
