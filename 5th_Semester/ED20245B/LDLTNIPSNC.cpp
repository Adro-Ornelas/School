/* 
 * File:   LDLTNIPSNC.cpp
 * Author: Adro Ornelas
 * 
 * Created on 4 de octubre de 2024, 01:23 PM
 */

#include "LDLTNIPSNC.h"

#include <iostream>
#include <stdlib.h>

using namespace std;

LDLTNIPSNC::LDLTNIPSNC() {
    p = NULL;   // Cuando vacía apunta null
}

LDLTNIPSNC::~LDLTNIPSNC() {
}

int  LDLTNIPSNC::cardinalidad(){
    
    int cuantos = 0;
    for(struct NodoD *ptmp = p; ptmp != NULL; ptmp = ptmp->pder)
        ++cuantos;    
    return cuantos;
}

void LDLTNIPSNC::despliega() {
 
    for(struct NodoD *ptmp = p; ptmp != NULL; ptmp = ptmp->pder)
        cout << ptmp->dato << '\t';
    cout << endl;
}
bool LDLTNIPSNC::eliminar(int *dato, int pos){

    if(esVacia())
        return false;
    struct NodoD *ptmp = p; 
    
    if(1 == pos) {
        p = p->pder;
        if(p != NULL)
            p->pizq = NULL;
        free(ptmp);
        return true;
    }
    
    ptmp = p->pder;
    int miPos = 2;
    while(miPos < pos && ptmp != NULL) {
        ++miPos;
        ptmp = ptmp->pder;
    }
    
    if(miPos != pos)   // Posicion invalida
        return false;
    
    
    *dato = ptmp->dato; // Guarda dato a eliminar
    
    // Que lista deje de apuntar al nodo a eliminar
    ptmp->pizq->pder = ptmp->pder;
    if(ptmp->pder != NULL)
        ptmp->pder->pizq = ptmp->pizq;
    
    free(ptmp);
    return true;
}
bool LDLTNIPSNC::esElemento(int dato){
    
    for(struct NodoD *ptmp = p; ptmp != NULL; ptmp = ptmp->pder)
        if(dato == ptmp->dato)
            return true;
    return false;
}
bool LDLTNIPSNC::esVacia(){
    return (NULL == p);
}
bool LDLTNIPSNC::insertar(int dato, int pos){

    struct NodoD *pNue = (struct NodoD*)malloc(sizeof(struct NodoD));
    if(pNue == NULL)
        return false;
    pNue->dato = dato;
    
    if(1 == pos) {
        
        pNue->pizq = NULL;
        pNue->pder = p;
        if(!esVacia()) 
            p->pizq = pNue;
        p = pNue;
        return true;
    }     
    struct NodoD *ptmp = p;
    int miPos = 2;
    while(miPos < pos && ptmp->pder != NULL) {
        ++miPos;
        ptmp = ptmp->pder;
    }
    
    if(miPos != pos){   // Posicion invalida
        free(pNue);
        return false;
    }
    
    // Que nodo apunte a lista
    pNue->pizq = ptmp;
    pNue->pder = ptmp->pder;
    
    // Que lista apunte a nodo
    if(ptmp->pder != NULL)
        ptmp->pder->pizq = pNue;    
    ptmp->pder = pNue;
    
    return true;
}