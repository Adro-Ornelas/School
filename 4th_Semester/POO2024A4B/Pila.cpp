/* 
 * File:   Pila.cpp
 * Author: Adro Ornelas
 * 
 * Created on 1 de marzo de 2024, 03:13 PM
 */

#include "Pila.h"
#include <iostream>
using std::cout;
using std::endl;

Pila::Pila() {
    tope = -1;  // Index
    for(int i = 0; i < TAMPILA; ++i)    // Fill of zeroes
        datos[i] = 0;
}

int Pila::cardinalidad(){
    return tope + 1;    // If return 0, tope = -1
                        // If return 10, tope = 0
}

void Pila::print(){
    for(int i = 0; i <= tope; ++i)
        cout << '[' << datos[i] << "] ";
    cout << endl;
}

bool Pila::eliminar(int* num){
    if(isEmpty())
        return false;
    *num = datos[tope];    
    --tope;
    return true;
}

bool Pila::insertar(int num){
    if(isFull())
        return false;
    
    datos[++tope] = num;
    return true;
}

bool Pila::isFull(){
    // If tope = Tampila its full
    return (tope == TAMPILA -1) ? true:false;
}

bool Pila::isEmpty(){
    return (-1 == tope) ? true:false;
}

bool Pila::isThere(int num){
    for(int i = 0; i < tope; ++i)
        if(datos[i] == num)
            return true;
    return false;
}



