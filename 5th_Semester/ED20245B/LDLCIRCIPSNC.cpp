/* 
 * File:   LDLCIRCIPSNC.cpp
 * Author: Adro Ornelas
 * 
 * Created on 24 de octubre de 2024, 04:13 PM
 */

#include "LDLCIRCIPSNC.h"

#include <iostream>
#include <stdlib.h>

using namespace std;

bool LDLCIRCIPSNC::eliminar(int *dato, int pos){
    
    if(esVacia())
        return false;
    
    struct NodoD *ptmp = p;
    
    int miPos = 1;
    do {
        if(miPos == pos)
            break;
        ++miPos;
        ptmp = ptmp->pder;
    } while(ptmp->pder != p);
    
    if(miPos != pos)    // Posicion inválida
        return false;
    
    *dato = ptmp->dato; // Guardo dato a eliminar
    
    if(pos == 1)
        if(p->pizq == p) // Cuando último elemento
            p = NULL;
        else 
            p = p->pder;       
    
    // Que lista deje de apuntar a nodo
    ptmp->pizq->pder = ptmp->pder;
    ptmp->pder->pizq = ptmp->pizq;
    
    free(ptmp);
    return true;
}

bool LDLCIRCIPSNC::insertar(int dato, int pos){
    
    // Crear nuevo nodo
    struct NodoD *pNue = (struct NodoD*)malloc(sizeof(struct NodoD));
    if(pNue == NULL)
        return false;
    pNue->dato = dato;
   
    if(esVacia()){
        pNue->pder = pNue->pizq = p = pNue;
        return true;
    }
   
    struct NodoD *ptmp = p;
    
    int miPos = 1;
    // Inserto a la izquierda de ptmp
    do{
        if(miPos == pos)
            break;
        ++miPos;
        ptmp = ptmp->pder;
    } while(ptmp != p);
    
    if(miPos != pos){    // Posicion inválida
        free(pNue);
        return false;
    }
    
    if(pos == 1)
        p = pNue;
    
    // Que nodo nuevo apunte a lista
    pNue->pder = ptmp;
    pNue->pizq = ptmp->pizq;
    
    // Que lista apunte a nodo nuevo
    ptmp->pizq->pder = pNue;
    ptmp->pizq = pNue;
       
    return true;
    \
}
