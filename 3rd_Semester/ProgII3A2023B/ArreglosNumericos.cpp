#include "ArreglosNumericos.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
    
ArreglosNumericos::ArreglosNumericos(bool randomize) {
    if(randomize){
        srand(time(0));
        for(int i = 0; i < TAMARAR; ++i)
            arreglo1[i] = rand() % 100 + 1;
        
    } else{ 
        arreglo1[0] = 14;
        arreglo1[1] = 23;
        arreglo1[2] = 52;
        arreglo1[3] = 6;
        arreglo1[4] = -4;
        arreglo1[5] = 72;
        arreglo1[6] = 9;
        arreglo1[7] = 91;
        arreglo1[8] = 18;
        arreglo1[9] = 36;
    }
}

void ArreglosNumericos::CorreDados(){
    srand(time(0));
    int aleatorio;
    for(int i = 0; i < TAMARAR; ++i)
        arreglo1[i] = 0;        // Llena de cero el arreglo
    for(int i = 0; i < 1000; ++i){
        aleatorio = rand() % 6 + 1 + rand() % 6 + 1; // Random 1-6 + 1-6
        ++arreglo1[aleatorio-2];    // Ya que aleatorio es de 2-12
    }
    
    printf(" Puntos\t Repeticiones\n");
    for(int i = 0; i < TAMARAR; ++i)
        printf(" %d    \t %d\n", i+2, arreglo1[i]);
    
}

void ArreglosNumericos::Despliega(){
    for(int i = 0; i < TAMARAR; ++i)
        printf("%d\t", arreglo1[i]);
    printf("\n");
    
}

void ArreglosNumericos::DespliegaArr(int arr[], int tam){
    for(int i = 0; i < tam; ++i)
        printf("[%d] ",arr[i]);
    printf("\n");
}

int ArreglosNumericos::DifConsecutivos(){
   
    int dif = (arreglo1[0] > arreglo1[1] ?
        arreglo1[0] - arreglo1[1] : arreglo1[1] - arreglo1[0]);
    
    for(int i = 1; i < TAMARAR - 1; ++i)
        if(arreglo1[i] > arreglo1[i+1])
            if(arreglo1[i] - arreglo1[i+1] > dif)
                dif = arreglo1[i] - arreglo1[i+1];
            else;
        else
            if(arreglo1[i+1] - arreglo1[i] > dif)
                dif = arreglo1[i+1] - arreglo1[i];
        
        return dif;
}

void ArreglosNumericos::DosMayores(int* mayor1, int* mayor2){
    *mayor1 = *mayor2 = arreglo1[0];
    for(int i = 1; i < TAMARAR; ++i)
        if(arreglo1[i] > *mayor1){
            *mayor2 = *mayor1;
            *mayor1 = arreglo1[i];
        } else 
            if(arreglo1[i] > *mayor2)
                *mayor2 = arreglo1[i];
}

int ArreglosNumericos::FactoresArr(int num, int arr[]){
    int i = 0;
    for(int cactor = 1; cactor <= num; ++cactor){
        if(!(num % cactor)){ // Si sí es divisible
            arr[i] = cactor;
            ++i;
        }
    }
    return i;
}

void ArreglosNumericos::FillArregloOrder(int arr[], int num, int tam){
        for(int i = 0; i < tam; ++i)
            arr[i] = num++;
}

void ArreglosNumericos::DespliegaFactores(int arr[], int tam, int num){
    printf("(");
    for(int i = 0; i < tam; ++i)
        if(i != tam-1)
            printf("%d, ", arr[i]);
        else
            printf("%d", arr[i]);
    printf(")");
}


float ArreglosNumericos::Mediana(int arr[], int tam){
    float mediana;
    if(tam % 2 != 0) // Si no es par
        mediana = arr[(tam - 1) / 2];
    else
        mediana = (arr[tam / 2 - 1] + arr[tam / 2]) / (float)2;
    return mediana;
}




