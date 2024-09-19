/* 
 * File:   LSLCIRCIVSNC.cpp
 * Author: PatoServer
 * 
 * Created on 31 de agosto de 2024, 11:51 AM
 */

#include <iostream>
#include <stdlib.h>

#include "LSLCIRCIVSNC.h"


LSLCIRCIVSNC::LSLCIRCIVSNC() {
    p = NULL; // Cuando vacía apunta a null
}
LSLCIRCIVSNC::~LSLCIRCIVSNC() {
}

void LSLCIRCIVSNC::despliega(){
    if(p != NULL){ 
        struct Nodo* ptmp = p;
        
        do{
            std::cout << ptmp->dato << '\t';
            ptmp = ptmp->pNext;
        }while(ptmp != p);
        std::cout << std::endl;
    }
}

int  LSLCIRCIVSNC::cardinalidad(){
    int elements = 0;
    if(p != NULL){ 
        struct Nodo* ptmp = p;
        do{
            ++elements;
            ptmp = ptmp->pNext;
        }while(ptmp != p);
    }
    return elements;
}

bool LSLCIRCIVSNC::eliminar(int dato){
    if(p == NULL) return false;
    
    struct Nodo *pOld, *pTmp;
    pOld = pTmp = p;
    
    do{
        if(pTmp->dato == dato)
            break;
        pOld = pTmp;
        pTmp = pTmp->pNext;
    } while( pTmp != p);
    
    if(pTmp->dato != dato)
        return false;
    
    if(pOld == pTmp){
        if(p->pNext != p) { // Cuando no único
            for(pOld= p->pNext; pOld->pNext != p; pOld = pOld->pNext);
            pOld->pNext = pTmp->pNext;            
        }
        p = (pTmp->pNext == p) ? NULL : pTmp ->pNext; 
    } else {    // Cuando in middle
        pOld->pNext = pTmp->pNext;
    }
    
    free(pTmp);
    return true;
    

}

bool LSLCIRCIVSNC::esElemento(int dato){
    if(p != NULL){ 
        struct Nodo* ptmp = p;
        do{
            if(dato == ptmp->dato)
                return true;
            ptmp = ptmp->pNext;
        }while(ptmp != p);
    }
    return false;
}

bool LSLCIRCIVSNC::esVacia(){
    return ( p == NULL );
}

bool LSLCIRCIVSNC::insertar(int dato){
    
    // Nuevo nodo:
    struct Nodo *pNew = (struct Nodo *) malloc(sizeof(struct Nodo));
    pNew->dato = dato;
    
    // Apuntadores antes y después del nodo
    struct Nodo *pLower, *pUpper;
    pLower = pUpper = p;
    
    if(p != NULL){ 
        do{
            if(pUpper->dato > dato)
                break;
            pLower = pUpper;
            pUpper = pUpper->pNext;
        }while(pUpper != p);
        
        if(pLower != pUpper){   // Inserción en medio
            pLower->pNext = pNew;  
            pNew->pNext = pUpper;
            
        } else {    // Inserción al inicio
            
            // Encuentro el último nodo para apuntarlo al inicio
            while(pUpper->pNext != p) pUpper = pUpper->pNext;
            
            pUpper->pNext = pNew;   // Final apunta al inicio
            pNew->pNext = p;        // Inicio apunta al segundo
            p = pNew;               // El principio ahora es el nuevo nodo
            
        }
        
    } else {
        p = pNew;
        p->pNext = p;
    }
    
    

}        


