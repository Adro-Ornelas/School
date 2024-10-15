/* 
 * File:   LSLCIRCIVCNC.cpp
 * Author: Adro Ornelas
 * 
 * Created on 20 de septiembre de 2024, 01:01 PM
 */

#include <iostream>
#include <stdlib.h>

#include "LSLCIRCIVCNC.h"

using namespace std;

LSLCIRCIVCNC::LSLCIRCIVCNC()
{
    p = (struct Nodo*)malloc(sizeof(struct Nodo));
    p->pNext = p;
}

LSLCIRCIVCNC::~LSLCIRCIVCNC() {
}

int  LSLCIRCIVCNC::cardinalidad()
{
    int cuantos = 0;
    struct Nodo *pTmp = p->pNext;
    while(pTmp != p)
    {
        ++cuantos;
        pTmp = pTmp->pNext;
    }
    return cuantos;
}
void LSLCIRCIVCNC::despliega()
{
    struct Nodo *pTmp = p->pNext;
    while(pTmp != p)
    {
        cout << pTmp->dato << '\t';
        pTmp = pTmp->pNext;
    }
    cout << endl;
}
bool LSLCIRCIVCNC::eliminar(int dato)
{
    struct Nodo *pOld = p,
                *pTmp = p->pNext;
    while(pTmp != p)
    {
        if(pTmp->dato == dato)
            break;
        pOld = pTmp;
        pTmp = pTmp->pNext;
    }
    if(pTmp == p || pTmp->dato != dato)
        return false;
    
    pOld->pNext = pTmp->pNext;
    free(pTmp);
    return true;    
}

bool LSLCIRCIVCNC::esElemento(int dato)
{
    struct Nodo *pTmp = p->pNext;
    while(pTmp != p)
    {
        if(pTmp->dato == dato)
            return true;
        pTmp = pTmp->pNext;
    }    
    return false;
}

bool LSLCIRCIVCNC::esVacia()
{
    return (p == p->pNext);
}

bool LSLCIRCIVCNC::insertar(int dato)
{
    // Crear nuevo nodo
    struct Nodo *pNue = (struct Nodo*)malloc(sizeof(struct Nodo));
    if(pNue == NULL)
        return false;
    pNue->dato = dato;
    
    struct Nodo *pOld = p,
                *pTmp = p->pNext;
    while(pTmp != p)
    {
        if(pTmp->dato > dato)
            break;
        pOld = pTmp;
        pTmp = pTmp->pNext;
    }
    pOld->pNext = pNue;
    pNue->pNext = pTmp;
    return true;
}
