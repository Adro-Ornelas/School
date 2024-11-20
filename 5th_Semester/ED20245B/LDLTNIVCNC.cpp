/* 
 * File:   LDLTNIVCNC.cpp
 * Author: Adro Ornelas
 * 
 * Created on 19 de octubre de 2024, 08:55 PM
 */

#include "LDLTNIVCNC.h"

#include <iostream>
#include <stdlib.h>

using namespace std;

LDLTNIVCNC::LDLTNIVCNC() {
    p = (struct NodoD*)malloc(sizeof(struct NodoD));
    p->pder = p->pizq = NULL;
}

LDLTNIVCNC::~LDLTNIVCNC() {
}

int  LDLTNIVCNC::cardinalidad() {

    int cuantos = 0;
    for(struct NodoD *ptmp = p->pder; ptmp != NULL; ptmp = ptmp->pder)
        ++cuantos;    
    return cuantos;
}
void LDLTNIVCNC::despliega() {

    for(struct NodoD *ptmp = p->pder; ptmp != NULL; ptmp = ptmp->pder)
        cout << ptmp->dato << '\t';
    cout << endl;
}
bool LDLTNIVCNC::eliminar(int dato) {
    
    NodoD *ptmp = p->pder;
    while(ptmp != NULL){
        if(ptmp->dato == dato)
            break;
        ptmp = ptmp->pder;
    }
   
    if(ptmp == NULL)  // Valor invalido o si es vacia
        return false;
    
    // Que lista deje de apuntar a nodo
    ptmp->pizq->pder = ptmp->pder;
    if(ptmp->pder != NULL)
        ptmp->pder->pizq = ptmp->pizq;
    
    free(ptmp);
    return true;
}

bool LDLTNIVCNC::esElemento(int dato) {

    for(struct NodoD *ptmp = p->pder; ptmp != NULL; ptmp = ptmp->pder)
        if(dato == ptmp->dato)
            return true;
    return false;
}

bool LDLTNIVCNC::esVacia(){
    return (p->pder == NULL);
}

bool LDLTNIVCNC::insertar(int dato) {
    
    // Creo nuevo nodo
    struct NodoD *pNue = (struct NodoD*)malloc(sizeof(struct NodoD));
    if(pNue == NULL)
        return false;
    pNue->dato = dato;
    
    NodoD *ptmp = p;
    while(ptmp->pder != NULL){
        if(ptmp->pder->dato > dato)
            break;
        ptmp = ptmp->pder;
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