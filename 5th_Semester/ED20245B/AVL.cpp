/* 
 * File:   AVL.cpp
 * Author: Adro Ornelas
 * 
 * Created on 28 de noviembre de 2024, 03:53 PM
 */

#include "AVL.h"

#include <iostream>
#include <stdlib.h>

using namespace std;

bool AVL::inserta(int dato){
    
    if(!ABB::inserta(dato))
        return false;
    
    struct NodoA *ptmp, *pdad;
    ptmp = pdad = p;
    while(1) {
        
        if(ptmp->dato == dato)
            return true;
        
        // Determinar si está desbalanceado por cualquier modo:
        if( (altura(ptmp->pizq) > altura(ptmp->pder) + 1) || 
            (altura(ptmp->pder) > altura(ptmp->pizq) + 1) )
            break;
        pdad = ptmp;
        ptmp = (ptmp->dato > dato) ? ptmp->pizq : ptmp->pder;
    }
    
    // Si esta desbalanceado, se determina que rotación hacer
    
    if(altura(ptmp->pder) > altura(ptmp->pizq)) { // Rder
        
        if(altura(ptmp->pder->pder) > altura(ptmp->pder->pizq))
            ddRotation(pdad, ptmp); // DD
        else
            diRotation(pdad, ptmp); // DI
        
    } else { // Rizq
        
        if(altura(ptmp->pizq->pizq) > altura (ptmp->pizq->pder))
            iiRotation(pdad, ptmp); // II
        else
            idRotation(pdad, ptmp); // ID
    }
    return true;
}

void AVL::ddRotation(NodoA *pdad, NodoA *ptmp){   
    // Balanceo DD
    if(pdad->pder == ptmp){
        pdad->pder = ptmp->pder;
        ptmp->pder = ptmp->pder->pizq;
        pdad->pder->pizq = ptmp;
    } else if(pdad->pizq == ptmp) {
        pdad->pizq = ptmp->pder;
        ptmp->pder = ptmp->pder->pizq;
        pdad->pizq->pizq = ptmp;
    } else if(ptmp == p) {
        p = ptmp->pder;
        ptmp->pder = p->pizq;
        p->pizq = ptmp;
    }
}

void AVL::iiRotation(NodoA *pdad, NodoA *ptmp){   
    // Balanceo II
    if(pdad->pder == ptmp){
        pdad->pder = ptmp->pizq;
        ptmp->pizq = ptmp->pizq->pder;
        pdad->pder->pder = ptmp;
    } else if(pdad->pizq == ptmp) {
        pdad->pizq = ptmp->pizq;
        ptmp->pizq = ptmp->pizq->pder;
        pdad->pizq->pder = ptmp;
    } else if(ptmp == p) {
        p = ptmp->pizq;
        ptmp->pizq = p->pder;
        p->pder = ptmp;
    }
}

void AVL::diRotation(NodoA* pdad, NodoA* ptmp) {
    
    iiRotation(ptmp, ptmp->pder);
    ddRotation(pdad, ptmp);

}

void AVL::idRotation(NodoA* pdad, NodoA* ptmp) {
    
    ddRotation(ptmp, ptmp->pizq);
    iiRotation(pdad, ptmp);

}
