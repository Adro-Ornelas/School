/* 
 * File:   LSLCIRCIPSNC.cpp
 * Author: Adro Ornelas
 * 
 * Created on 20 de septiembre de 2024, 09:43 AM
 */
#include <iostream>
#include <stdlib.h>
#include "LSLCIRCIPSNC.h"

using namespace std;

LSLCIRCIPSNC::LSLCIRCIPSNC()
{
    p = NULL;   // Cuando vacia
}

LSLCIRCIPSNC::~LSLCIRCIPSNC()
{
}

int  LSLCIRCIPSNC::cardinalidad() {
    if(esVacia())
        return 0;

    int cuantos = 1;  // Si no es vacia minimo hay uno  
    struct Nodo *ptmp = p;
    while(ptmp->pNext != p) {
        ++cuantos;
        ptmp = ptmp->pNext;
    }
    
    return cuantos;
    
}
void LSLCIRCIPSNC::despliega() {
    struct Nodo *ptmp = p;
    if(!esVacia()){
        do {
            cout << ptmp->dato << '\t';
            ptmp = ptmp->pNext;
        } while(ptmp != p);
    }
    cout << endl;
}
bool LSLCIRCIPSNC::eliminar(int *dato, int pos) {
    
    if(esVacia())
        return false;
    
    int miPos = 1;
    struct Nodo *ptmp, *pold;
    ptmp = pold = p;
    
    do {
        if(miPos == pos)
            break;
        ++miPos;
        pold = ptmp;
        ptmp = ptmp->pNext;
    } while(ptmp != p);
    
    if(miPos != pos)
        return false;
    
    *dato = ptmp->dato;
    
    if(pos == 1){   // Elimina primera posición
        if(ptmp->pNext == p) { // Si elimina único nodo
            p = NULL;
        } else {
            p = ptmp->pNext;
            while(ptmp->pNext != pold)
                ptmp = ptmp->pNext;
            ptmp->pNext = p;
            ptmp = pold;    // Para posterior liberación de ptmp
        }
    } else {
        pold->pNext = ptmp->pNext;
    }
    free(ptmp);
    return true;
}
bool LSLCIRCIPSNC::esElemento(int dato) {
    if(esVacia())
        return false;    
    struct Nodo *ptmp = p;
    do
    {
        if(ptmp->dato == dato)
            return true;
        ptmp = ptmp->pNext;
    } while(ptmp != p);
    return false;
}

bool LSLCIRCIPSNC::esVacia(){
    return (p == NULL);
}
bool LSLCIRCIPSNC::insertar(int dato, int pos) {
    
    struct Nodo *pNue = (struct Nodo*)malloc(sizeof(struct Nodo));
    if(pNue == NULL)
        return false;
    pNue->dato = dato;
    
    if(esVacia()){
        p = pNue;
        p->pNext = p;
        return true;
    }
    
    int miPos = 1;
    struct Nodo *ptmp, *pold;
    ptmp = pold = p;
    
    do {
        if(miPos == pos)
            break;
        ++miPos;
        pold = ptmp;
        ptmp = ptmp->pNext;
    } while(ptmp != p);
    
    
    if(miPos != pos){
        free(pNue);
        return false;
    }
    
    if(1 == pos) {

        pNue->pNext = pold;    // Nodo apunte a lista
        while(ptmp->pNext != pold)  // Busca final de lista
            ptmp = ptmp->pNext;
        ptmp->pNext = pNue; // Final apunta a nodo
        p = pNue;   // Nuevo apuntador inicio
        
    } else {    
        pold->pNext = pNue; // Lista apunta a nodo
        pNue->pNext = ptmp; // Nodo apunta a lista   
    }
    return true;
}
