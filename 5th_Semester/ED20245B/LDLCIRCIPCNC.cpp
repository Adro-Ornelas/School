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
    for(struct NodoD *ptmp = p->pder; ptmp != p; ptmp = ptmp->pder)
            ++cuantos;
    return cuantos;
}
void LDLCIRCIPCNC::despliega() {
    for(struct NodoD *ptmp = p->pder; ptmp != p; ptmp = ptmp->pder)
            cout << ptmp->dato << '\t';
    cout << endl;
}
bool LDLCIRCIPCNC::eliminar(int *dato, int pos){
    
    struct NodoD *ptmp = p->pder;
    
    int miPos = 1;
    for(;miPos < pos && ptmp != p; ++miPos)
        ptmp = ptmp->pder;     

    if(miPos != pos || ptmp == p)
        return false;
    
    *dato = ptmp->dato;
    
    // Lista deje de apuntar a nodo
    ptmp->pizq->pder = ptmp->pder; // Que nodo anterior apunte al siguiente
    ptmp->pder->pizq = ptmp->pizq; // Que nodo siguiente apunte al anterior
    
    free(ptmp);
    
    return true;
}
bool LDLCIRCIPCNC::esElemento(int dato){
    for(struct NodoD *ptmp = p->pder; ptmp != p; ptmp = ptmp->pder)
        if(ptmp->dato == dato)
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
    
    struct NodoD *ptmp = p->pder;
    
    int miPos = 1;
    for(;miPos < pos && ptmp != p; ++miPos){
        ptmp = ptmp->pder;        
    }
    
    if(miPos != pos){
        free(pNue);
        return false;
    }
    
    // Que nodo apunte a la lista
    pNue->pizq = ptmp->pizq;
    pNue->pder = ptmp;
    
    // Que lista apunte a nodo
    ptmp->pizq->pder = pNue;
    ptmp->pizq = pNue;
    
    return true;
       
}

