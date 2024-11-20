/* 
 * File:   Recursividad.cpp
 * Author: Adro Ornelas
 * 
 * Created on 25 de octubre de 2024, 07:42 PM
 */

#include "Recursividad.h"

long Recursividad::factorial(long num) {
    if(num == 0)
        return 1;
    return num * factorial(num-1);
}

long Recursividad::potencia(int num, int exponente){
    if(exponente == 0)
        return 1;
    else
        return num * potencia(num, exponente - 1);
}