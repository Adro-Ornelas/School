/* 
 * File:   LSLTNIVSNC.cpp
 * Author: Adro Ornelas
 * 
 * Created on 23 de agosto de 2024, 07:35 PM
 */

#include <iostream>
#include <stdlib.h>

#include "LSLTNIVSNC.h"


LSLTNIVSNC::LSLTNIVSNC() {
    p = NULL;   // Cuando vacía apunta null
}

LSLTNIVSNC::~LSLTNIVSNC() {
}

void LSLTNIVSNC::despliega()
{
    // Operando -> a donde apunta, pero para estructuras (como "." o "*")
    for(struct Nodo* pTmp = p; pTmp != NULL; pTmp = pTmp->pNext)
        std::cout << pTmp->dato << "\t";
    std::cout << std::endl;
}

bool LSLTNIVSNC::eliminar(int dato){
    
    if(esVacia())
        return false;
    
    struct Nodo *pOld, *pTmp;
    pOld = pTmp = p;           
    for( ; pTmp != NULL; pTmp = pTmp->pNext){
        if(pTmp->dato == dato)
            break;
        pOld = pTmp;
    }
    
    if(pTmp == NULL || pTmp->dato != dato)
        return false;
    
    if(pTmp == p)   // Si elimina 1era posicion
        p = pTmp->pNext;
    else
        pOld->pNext = pTmp->pNext;
    
    
    free(pTmp);
    
    return true;    
}

bool LSLTNIVSNC::insertar(int dato){
    // Nuevo apuntador a nuvo nodo
    struct Nodo *pNue = (struct Nodo *) malloc(sizeof(struct Nodo));
    
    if(pNue == NULL){
        // Si ya no hay espacio o no hay permiso para obtener memoria del OS
        return false;
    }
    pNue->dato = dato;
    
     // Para insercion por valor(en orden)
    struct Nodo *pOld,
                *pTmp;
    pOld = pTmp = p;           
    for( ; pTmp != NULL; pTmp = pTmp->pNext){
        if(pTmp->dato > dato)
            break;
        pOld = pTmp;
    }
    // Hago que el nodo nuevo apunte a la lista
    pNue->pNext = pTmp;
    
    // *NUll es error GRAVE
    // Hago que la lista apunte al nodo nuevo
    if(pOld == NULL || pOld == pTmp)
        p = pNue;
    else
        pOld->pNext = pNue;
    
    return true;
}

bool LSLTNIVSNC::esElemento(int dato) {
    
    for(struct Nodo* pTmp = p; pTmp != NULL; pTmp = pTmp->pNext)
        if(dato == pTmp->dato)
            return true;
    return false;
}

int  LSLTNIVSNC::cardinalidad() { // Cuantos nodos
    
    int ndatos = 0;
    for(struct Nodo* pTmp = p; pTmp != NULL; pTmp = pTmp->pNext)
        ++ndatos;
    return ndatos;
}

bool LSLTNIVSNC::esVacia()
{
    return (p == NULL);
}



