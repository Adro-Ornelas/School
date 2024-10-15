/* 
 * File:   LDLCIRCIPCNC.cpp
 * Author: Adro Ornelas
 * 
 * Created on 3 de octubre de 2024, 09:57 AM
 */

#include <iostream>
#include <stdlib.h>

#include "LDLCIRCIPCNC.h"

using namespace std;

LDLCIRCIPCNC::LDLCIRCIPCNC() {
    p = (struct NodoD*)malloc(sizeof(struct NodoD));
    p->pizq = p->pder = p;    
}

LDLCIRCIPCNC::~LDLCIRCIPCNC() {
}


int  LDLCIRCIPCNC::cardinalidad(){
    int cuantos = 0;
    for(struct NodoD *tmp = p->pder; tmp != p; tmp = tmp->pder)
            ++cuantos;
    return cuantos;
}
void LDLCIRCIPCNC::despliega()
{
    for(struct NodoD *tmp = p->pder; tmp != p; tmp = tmp->pder)
            cout << tmp->dato << '\t';
    cout << endl;
}
bool LDLCIRCIPCNC::eliminar(int *dato, int pos){
    
    struct NodoD *pTmp = p->pder;
    
    int miPos = 1;
    for(;miPos < pos && pTmp != p; ++miPos)
        pTmp = pTmp->pder;     

    if(miPos != pos || pTmp == p)
        return false;
    
    *dato = pTmp->dato;
    
    // Lista deje de apuntar a nodo
    pTmp->pizq->pder = pTmp->pder; // Que nodo anterior apunte al siguiente
    pTmp->pder->pizq = pTmp->pizq; // Que nodo siguiente apunte al anterior
    
    free(pTmp);
    
    return true;
}
bool LDLCIRCIPCNC::esElemento(int dato){
    for(struct NodoD *tmp = p->pder; tmp != p; tmp = tmp->pder)
        if(tmp->dato == dato)
            return true;
    return false;
}
bool LDLCIRCIPCNC::esVacia(){
    return (p->pder == p);
}
bool LDLCIRCIPCNC::insertar(int dato, int pos){

    struct NodoD *pNue = (struct NodoD*)malloc(sizeof(struct NodoD));
    
    if(pNue == NULL)
        return false;
    pNue->dato = dato;
    
    struct NodoD *pTmp = p->pder;
    
    int miPos = 1;
    for(;miPos < pos && pTmp != p; ++miPos){
        pTmp = pTmp->pder;        
    }
    
    if(miPos != pos){
        free(pNue);
        return false;
    }
    
    // Que nodo apunte a la lista
    pNue->pizq = pTmp->pizq;
    pNue->pder = pTmp;
    
    // Que lista apunte a nodo
    pTmp->pizq->pder = pNue;
    pTmp->pizq = pNue;
    
    return true;
       
}

