/* 
 * File:   LDLTNIVSNC.cpp
 * Author: Adro Ornelas
 * 
 * Created on 24 de octubre de 2024, 01:37 PM
 */

#include "LDLTNIVSNC.h"

#include <iostream>
#include <stdlib.h>

using namespace std;

bool LDLTNIVSNC::eliminar(int dato){

    struct NodoD *ptmp = p;
    
    while(ptmp != NULL){
        if(ptmp->dato == dato)
            break;
        ptmp = ptmp->pder;
    }
    if(ptmp == NULL)    // Dato no encontrado o vacía
        return false;
    
    // Que lista deje de apuntr a nodo
    if(ptmp->pizq == NULL) {  // Cuando elimina primer elemento
        p = ptmp->pder;
        if(p != NULL)   // Cuando la lista queda vacía
            p->pizq = NULL; 
    } else {
        ptmp->pizq->pder = ptmp->pder;
        if(ptmp->pder != NULL)  // Cuando elimina el nodo del final
            ptmp->pder->pizq = ptmp->pizq;
    }
    
    free(ptmp);
    
    return true;
}

bool LDLTNIVSNC::insertar(int dato){
    
    // Inicializo nodo
    struct NodoD *pNue = (struct NodoD*)malloc(sizeof(struct NodoD));
    if(pNue == NULL)
        return false;
    pNue->dato = dato;
    
    if(esVacia()){  // en lista vacía
        p = pNue;
        p->pizq = p->pder = NULL;
        return true;
    }
    if(p->dato > dato){ // Inserta en 1era posicion
        pNue->pder = p;
        pNue->pizq = NULL;
        p->pizq = pNue;
        p = pNue;
        return true;
    }
    
    struct NodoD *ptmp = p;
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

