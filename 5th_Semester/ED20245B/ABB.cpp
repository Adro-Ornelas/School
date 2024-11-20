/* 
 * File:   ABB.cpp
 * Author: Adro Ornelas
 * 
 * Created on 7 de noviembre de 2024, 10:58 AM
 */

#include "ABB.h"

#include <iostream>
#include <stdlib.h>

using namespace std;

ABB::ABB() {
    p = NULL;
}


ABB::~ABB() {
    while(p != NULL)
        elimina(p, p, p->dato);
}

bool ABB::esVacia(){
    return (p == NULL);
}

void ABB::despliega() {
    inOrden(p);
    cout << endl;
}

void ABB::inOrden(NodoA *ptmp){
    if(ptmp == NULL)
        return;
    inOrden(ptmp->pizq);
    cout << ptmp->dato << "\t";
    inOrden(ptmp->pder);
}

int ABB::cardinalidad(){
    int cuantos = cardinalidad(p);
    return cuantos;
}

bool ABB::esElemento(int dato){
    return esElemento(p, dato);
}

bool ABB::esElemento(NodoA* ptmp, int dato){
    if(ptmp == NULL)
        return false;
    if(ptmp->dato > dato)
        return esElemento(ptmp->pizq, dato);
    if(ptmp->dato < dato)
        return esElemento(ptmp->pder, dato);
    return true;    // Si no es mayor ni menor, es igual
}

int ABB::cardinalidad(NodoA *ptmp){
    if(ptmp == NULL)
        return 0;
    return 1 + cardinalidad(ptmp->pizq) + cardinalidad(ptmp->pder);
}

bool ABB::elimina(int dato) {

    if(esVacia())
        return false;
    return elimina(p, p, dato);;
}

bool ABB::elimina(NodoA* ptmp, NodoA *pold, int dato) {
    
    if(ptmp == NULL)    // Cuando el dato no existe
        return false;
    
    if(ptmp->dato > dato) { // Busca nodo por la izquierda
        return elimina(ptmp->pizq, ptmp, dato);
    } else if ( ptmp->dato < dato) { // Busca nodo por la derecha
        return elimina(ptmp->pder, ptmp, dato);
    } else {    // Si no es mayor ni menor, es igual, se encontró el nodo
        
        if(ptmp->pder == NULL){ // Cuando por la derecha sea null
            
            if(p == ptmp)
                p = p->pizq;
            else
                if(pold->pder == ptmp)   
                    pold->pder = ptmp->pizq; // Si hijo derecho
                else    
                    pold->pizq = ptmp->pizq; // Si hijo izquierdo
            
            free (ptmp);
            return true;
            
        } else if(ptmp->pizq == NULL) { // Cuando por la izquierda sea null
            
            if(p == ptmp)
                p = p->pder;
            else
                if(pold->pder == ptmp)   
                    pold->pder = ptmp->pder; // Si hijo derecho
                else    
                    pold->pizq = ptmp->pder; // Si hijo izquierdo

            free (ptmp);
            return true;
        
        } else {    // Cuando el nodo tiene dos hijos 
            // Cuando no es null, busca siempre el más chico de los grandes
            // Elimina ese nodo y su valor lo pone en nodo ptmp
            struct NodoA *pchGrande = ptmp->pder; // Va por la derecha (grandes)
            while(pchGrande->pizq != NULL)  // Itera hasta obtener el más chico
                pchGrande = pchGrande->pizq;
            ptmp->dato = pchGrande->dato;
            return elimina(ptmp->pder, ptmp, pchGrande->dato);
        }
    } 
}

bool ABB::inserta(int dato) {
    
    struct NodoA *pNue = (struct NodoA*)malloc(sizeof(struct NodoA));
    if(pNue == NULL)
        return false;
    pNue->dato = dato;
    pNue->pder = pNue->pizq = NULL;
    
    if(esVacia()){    
        p = pNue;
        return true;
    }
    return inserta(p, pNue);
}

bool ABB::inserta(NodoA* ptmp, NodoA* pNue) {
    
    if(ptmp->dato > pNue->dato)
        if(ptmp->pizq != NULL) {
            return inserta(ptmp->pizq, pNue);
        } else {
            ptmp->pizq = pNue;
            return true;
        }
    else if(ptmp->dato < pNue->dato)
        if(ptmp->pder != NULL)
            return inserta(ptmp->pder, pNue);
        else {
            ptmp->pder = pNue;
            return true;
        }
    else { 
        free(pNue);
        return false;   // No puede haber dos nodos iguales
    }
}