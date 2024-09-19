/* 
 * File:   LSLTNIPCNC.cpp
 * Author: PatoServer
 * 
 * Created on 18 de septiembre de 2024, 07:25 PM
 */
#include <iostream>
#include <stdlib.h>
#include "LSLTNIPCNC.h"
using namespace std;

LSLTNIPCNC::LSLTNIPCNC() {
    p = (struct Nodo*)malloc(sizeof(Nodo));
    p->pNext = NULL;
}

LSLTNIPCNC::~LSLTNIPCNC() {
}

int LSLTNIPCNC::cardinalidad(){
    int cuantos = 0;
    struct Nodo *pTmp = p->pNext;
    while(pTmp != NULL){
        ++cuantos;
        pTmp = pTmp->pNext;
    }
    return cuantos;
}

void LSLTNIPCNC::despliega() {
    struct Nodo *pTmp = p->pNext;
    while(pTmp != NULL){
        cout << pTmp->dato << '\t';   
        pTmp = pTmp->pNext;
    }
    cout << endl;
}

bool LSLTNIPCNC::eliminar(int *dato, int pos){
    struct Nodo *pOld = p,
                *pTmp = p->pNext;
    
    int miPos = 1;
    for(;miPos < pos && pTmp != NULL; ++miPos){
        pOld = pTmp;
        pTmp = pTmp->pNext;        
    }
    if(miPos != pos || esVacia()) // Posición inválida
        return false;
    
    *dato = pTmp->dato;
    pOld->pNext = pTmp->pNext;
    
    free(pTmp); // Libero nodo
    
}

bool LSLTNIPCNC::esElemento(int dato){
    struct Nodo *pTmp = p->pNext;
    while(pTmp != NULL){
        if(pTmp->dato == dato)
            return true;
        pTmp = pTmp->pNext;
    }
    return false;
}

bool LSLTNIPCNC::esVacia(){
    return (p->pNext == NULL);
}

bool LSLTNIPCNC::insertar(int dato, int pos){
    struct Nodo *pNue =
    (struct Nodo*)malloc(sizeof(struct Nodo));
    
    if(pNue == NULL) return false;
    
    pNue->dato = dato;
    struct Nodo *pOld = p,
                *pTmp = p->pNext;
    
    int miPos = 1;
    for(;miPos < pos && pTmp != NULL; ++miPos){
        pOld = pTmp;
        pTmp = pTmp->pNext;        
    }
    if(miPos != pos){ // Posición inválida
        free(pNue);
        return false;
    }
    
    // Inserto nuevo nodo
    pOld->pNext = pNue;
    pNue->pNext = pTmp;
    
}

