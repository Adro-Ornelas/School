#include "Examenes.h"
#include <stdio.h>

void Examenes::DistintosCero(){
    int valor;
    
    do{
        printf("Escribe un valor (Salir: 0): ");
        fflush(stdout);
        scanf("%d", &valor);
        if(valor != 0) printf("\n%d\n", valor);
    }while(valor != 0);
    
}

