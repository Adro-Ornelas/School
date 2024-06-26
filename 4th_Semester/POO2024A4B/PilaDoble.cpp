/* 
 * File:   PilaDoble.cpp
 * Author: Adro Ornelas
 * 
 * Created on 21 de marzo de 2024, 07:30 PM
 */

#include "PilaDoble.h"
#include <iostream>
using std::cout;
using std::endl;
// For sense 1 is with upper, 2 is for lower

PilaDoble::PilaDoble(){
    Pila();
    topeInferior = TAMPILA;
}

int PilaDoble::cardinalidad(int sense){
    if(1 == sense)
        Pila::cardinalidad();
    else
        return (TAMPILA - topeInferior);   
}

void PilaDoble::print(int sense){
    if(1 == sense){
        Pila::print();
    } else if (2 == sense){
        for(int i = topeInferior; i < TAMPILA; ++i)
        cout << '[' << datos[i] << "] ";
        cout << endl;
    }
}

bool PilaDoble::eliminar(int* num, int sense){
    if(isEmpty(sense))
        return false;
    if(1 == sense)
        return Pila::eliminar(num);
    else if(2 == sense){
        *num = datos[topeInferior];    
        ++topeInferior;
    }
    return true;
}

bool PilaDoble::insertar(int num, int sense){
    if(isFull())
        return false;
    if(1 == sense)
        return Pila::insertar(num);
    else
        datos[--topeInferior] = num;
    return true;
}

bool PilaDoble::isFull(){
    // Si una pila esta llena la otra también
    return (tope == topeInferior - 1) ? true:false;
}

bool PilaDoble::isEmpty(int sense){
    if(1 == sense)
        return Pila::isEmpty();
    if(2 == sense){
        return (TAMPILA == topeInferior) ? true:false;
    }
}

bool PilaDoble::isThere(int num, int sense){
    if(1 == sense){
        return Pila::isThere(num);
    } else
        for(int i = topeInferior; i < TAMPILA; ++i)
            if(datos[i] == num)
                return true;
    return false;
}


 