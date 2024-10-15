/* 
 * File:   LSLTNIVCNC.cpp
 * Author: Adro Ornelas
 * 
 * Created on 20 de septiembre de 2024, 08:07 AM
 */

#include <iostream>
#include <stdlib.h>
#include "LSLTNIVCNC.h"

using namespace std;

LSLTNIVCNC::LSLTNIVCNC()
{
    p = (struct Nodo*)malloc(sizeof(Nodo));
    p->pNext = NULL;
}

LSLTNIVCNC::~LSLTNIVCNC() {
}

int  LSLTNIVCNC::cardinalidad() {
    
    int cuantos = 0;
    for(struct Nodo *tmp = p->pNext; tmp != NULL; tmp = tmp->pNext)
        ++cuantos;
    
    return cuantos;
}
void LSLTNIVCNC::despliega() {
    
    for(struct Nodo *tmp = p->pNext; tmp != NULL; tmp = tmp->pNext)
        cout << tmp->dato << '\t';
    cout << endl;
}

bool LSLTNIVCNC::eliminar(int dato) {   
    if(esVacia())
        return false;
    
    struct Nodo *pOld = p,
                *pTmp = p->pNext; 
    
    for(; pTmp != NULL; pTmp = pTmp->pNext)
    {
        if(pTmp->dato == dato)
            break;
        pOld = pTmp;
    }
    if(pTmp == NULL || pTmp->dato != dato)
        return false;
    
    
    pOld->pNext = pTmp->pNext;  // Omito el nodo a eliminar
    
    free(pTmp);    
}

bool LSLTNIVCNC::esElemento(int dato)
{
    for(struct Nodo *tmp = p->pNext; tmp != NULL; tmp = tmp->pNext)
        if(tmp->dato == dato)
            return true;
    return false;
}

bool LSLTNIVCNC::esVacia() {
    return (p->pNext == NULL);
}

bool LSLTNIVCNC::insertar(int dato) {
    
    struct Nodo *pNue = (struct Nodo*)malloc(sizeof(struct Nodo));
    if(pNue == NULL)
        return false;
    pNue->dato = dato;
    
    struct Nodo *pOld = p,
                *pTmp = p->pNext; 
    for(; pTmp != NULL; pTmp = pTmp->pNext) {
        
        if(pTmp->dato > dato)
            break;
        pOld = pTmp;
    }
    
    pOld->pNext = pNue; // Que lista apunte a Nodo
    pNue->pNext = pTmp; // Que nodo apunte a lista
    return true;
}

