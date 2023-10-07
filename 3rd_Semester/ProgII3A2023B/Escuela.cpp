#include "Escuela.h"
#include <stdio.h>

void Escuela::ResultadosCurso(int numAlumn, int* aproved, int* reproved, float* promedio){
    int calif, suma = 0;
    
    for(int i = 1; i <= numAlumn; ++i){
        printf("Introduza la calificación del alumno #%d: ", i);
        fflush(stdout);
        scanf("%d", &calif);
        suma += calif;
        if(calif < 70)
            *reproved = *reproved + 1;  // *reproved++ es erróneo
        else 
            (*aproved)++;       // No es legible
    }
    *promedio = (float)suma / numAlumn;
}

