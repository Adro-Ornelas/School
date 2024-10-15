/* 
 * File:   LSLCIRCIPCNC.cpp
 * Author: PatoServer
 * 
 * Created on 18 de septiembre de 2024, 06:43 PM
 */

#include <stdlib.h>
#include <iostream>
#include "LSLCIRCIPCNC.h"

using namespace std;

LSLCIRCIPCNC::LSLCIRCIPCNC() {
    p = (struct Nodo*)malloc(sizeof(struct Nodo));
    p->pNext = p;
}

LSLCIRCIPCNC::~LSLCIRCIPCNC() {
}


int  LSLCIRCIPCNC::cardinalidad(){
    int cuantos = 0;
    for(struct Nodo *tmp = p->pNext; tmp != p; tmp = tmp->pNext)
            ++cuantos;
    return cuantos;
}
void LSLCIRCIPCNC::despliega()
{
    for(struct Nodo *tmp = p->pNext; tmp != p; tmp = tmp->pNext)
            cout << tmp->dato << '\t';
    cout << endl;
}
bool LSLCIRCIPCNC::eliminar(int *dato, int pos){
    struct Nodo *pOld = p,
                *pTmp = p->pNext;
    int miPos = 1;
    for(;miPos < pos && pTmp != p; ++miPos){
        pOld = pTmp;
        pTmp = pTmp->pNext;        
    }
    if(miPos != pos || pTmp == p)
        return false;
    *dato = pTmp->dato;
    
    pOld->pNext = pTmp->pNext;
    free(pTmp);
    return true;
}
bool LSLCIRCIPCNC::esElemento(int dato){
    for(struct Nodo *tmp = p->pNext; tmp != p; tmp = tmp->pNext)
        if(tmp->dato == dato)
            return true;
    return false;
}
bool LSLCIRCIPCNC::esVacia(){
    return (p->pNext == p);
}
bool LSLCIRCIPCNC::insertar(int dato, int pos){
    struct Nodo *pNue =
    (struct Nodo*)malloc(sizeof(struct Nodo));
    
    if(pNue == NULL) return false;
    
    pNue->dato = dato;
    
    struct Nodo *pOld = p,
                *pTmp = p->pNext;
    
    int miPos = 1;
    for(;miPos < pos && pTmp != p; ++miPos){
        pOld = pTmp;
        pTmp = pTmp->pNext;        
    }
    
    if(miPos != pos){
        free(pNue);
        return false;
    }
    pNue->pNext = pTmp;
    pOld->pNext = pNue;
    return true;
       
}

