/* 
 * File:   Queue.cpp
 * Author: Adro Ornelas
 * 
 * Created on 2 de marzo de 2024, 07:37 PM
 */

#include "Queue.h"
#include <iostream>

Queue::Queue() {
    frente = fondo = -1;

    for(int i = 0; i < TAMQUEUE; ++i)    // Fill of zeroes
        fila[i] = 0;
}

bool Queue::eliminar(int* num){
    if(isEmpty())
        return false;
    else
        *num = fila[++frente]; // ++frente because frente's place is the first in
    // If the queue wasnt empty 
    fila[frente] = 0;
    if(frente == fondo)  // If them are equal, the queue is empty
        empty(); 
    return true;
        
}

bool Queue::empty(){
    frente = fondo = -1;
    for(int i = 0; i < TAMQUEUE; ++i)
        fila[i] = 0;
}

int Queue::getFrente(){
    return frente + 1;
}
int Queue::getFondo(){
    return fondo + 1;
}

bool Queue::insetar(int num){
    if(isFull())
        return false;
    else
        fila[++fondo] = num;
    
    // If the method didn't return false it will return true:
    return true;
}

bool Queue::isFull(){
    return (fondo == TAMQUEUE - 1) ?  true:false;
}

bool Queue::isEmpty(){
    if(frente == -1 && -1 == fondo)
        return true;
    else
        return false;
}

bool Queue::isThere(int num){
    for(int i = 0; i < TAMQUEUE; ++i)
        if (num == fila[i])
            return true;
    return false;
}

void Queue::print(){
    for(int i = 0; i < TAMQUEUE; ++i)
        std::cout << '[' << fila[i] << "] ";
    std::cout << std::endl;
}


