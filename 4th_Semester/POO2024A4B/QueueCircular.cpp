/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QueueCircular.cpp
 * Author: Adro Ornelas
 * 
 * Created on 19 de marzo de 2024, 08:15 AM
 */

#include "QueueCircular.h"
#include <iostream>

int QueueCircular::cardinalidad() {
    if(frente <= fondo)
        return Queue::getFondo(); // Porque es una queue normal
    return (fondo + 1) + (TAMQUEUE - frente); // Suma los de arriba mas abajo
}

void QueueCircular::print() {
    if(frente <= fondo)
        Queue::print(); // Porque es una queue normal
    
    // Imprime primera mitad
    for(int i = frente; i < TAMQUEUE; ++i)
        std::cout << fila[i] << '\t';
    // Imprime segunda mitad
    for(int i = 0; i < fondo; ++i)
        std::cout << fila[i] << '\t';
    std::cout << std::endl;
    
}

bool QueueCircular::isFull(){
    return (((frente == 0) && (fondo == TAMQUEUE - 1))
            || fondo == (frente - 1)) ? true:false;
}

bool QueueCircular::insetar(int num){
    if(isFull())
        return false;
    fondo = (fondo == TAMQUEUE - 1) ? 0: fondo + 1;
    fila[fondo] = num;
    return true;
}

bool QueueCircular::eliminar(int* num){
    if(isEmpty())
        return false;
    if(frente <= fondo)
        Queue::eliminar(num);
    *num = fila[frente];
    frente = (frente == TAMQUEUE - 1) ? 0:++frente;
    return true;
}














