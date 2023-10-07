#include "Chars.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void Chars::AdivinaCarcter(){
    // rand() genera un numéro pseudoaleatorio entre 1 y RANDMAX
    srand(time(0));
    char random_char = rand() % 25 + 1; // Aleatorio de 0-25
    char intento, intro;
    
    while(1){
        printf("Introduce un caracter: ");
        fflush(stdout);
        scanf("%c%c", &intento, &intro);
        if(random_char > intento) 
            printf("El carácter que buscas es mayor.\n");
        else if(random_char < intento)
            printf("El carácter que buscas es menor.\n");
        else {
            printf("HAS ENCONTRADO EL CARACTER!");
            break;
        }
    }
    
}

bool Chars::OrdenAlfa(char carac1, char carac2){
    return (carac1 < carac2);
    // A - 65, Z - 90
    // a - 97, z - 122
}

bool Chars::Entre_I_M(char c1){
    // I = 73, M = 77, i = 105, m = 108
    
    if(c1 >=  73 && c1 <= 77 || c1 >=  105 && c1 <= 108) // Comprueba ASCII
        return true;
    else 
        return false;
    
    // return (c1 >= 'I' && c1 <= 'M' || c1 >= 'i' && c1 <= 'm') ? true:false;
    
    
}