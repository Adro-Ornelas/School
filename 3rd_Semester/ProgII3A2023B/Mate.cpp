#include <math.h>
#include "Mate.h"
#include <stdio.h>

void Mate::AdivinaMiNum(int num1, int num2){
    
    int intento;
    while(1){
        printf("Jugador 1:\nAdivina el número: ");
        fflush(stdout);
        scanf("%d", &intento);
        if(num2 > intento)
            printf("El número es mayor\n.");
        else if(num2 < intento)
            printf("El número es menor\n.");
        else{
            printf("JUGADOR 1 HA GANADO EL JUEGO;");
            break;
        }
        printf("Jugador 2:\nAdivina el número: ");
        fflush(stdout);
        scanf("%d", &intento);
        if(num1 > intento)
            printf("El número es mayor\n.");
        else if(num1 < intento)
            printf("El número es menor\n.");
        else{
            printf("JUGADOR 2 HA GANADO EL JUEGO;");
            break;
        }
    }
}

double Mate::AreaCilindro(double h, double r){
    return 2 * M_PI * r * (h + r);
}

bool Mate::Divisible9(int number){
    int suma=0;
    while(number > 0){
        suma += number % 10;
        number /= 10;
    }
    return (suma % 9 == 0) ? true:false;
}

double Mate::SeriePi(){
    int signo = -1;
    double pi = 4;
    for(int i = 3; i < 100000000; i+=2){
        pi += (double)signo*4 / i;
        signo *= -1;
    }
    return pi;
}

void Mate::SumaYMediaDe200(int* suma, double* media){
    for(int i = 1; i <= 200; ++i){
        *suma = *suma + i;
    }
    *media = (double)*suma / 200; 
}

void Mate::Factores(int num){
    for(int cactor = 1; cactor <= num; ++cactor){
        if(!(num % cactor)){
            printf("%d, ", cactor);
        }
    }
}

int Mate::Invertido(int num){
    int invert = 0;
    
    while(num > 0){
        invert *= 10; 
        invert += num % 10;
        num /= 10;
    }
    return invert;
}

bool Mate::Multiplo(int num1, int num2){
    return !(num1 % num2);
}

int Mate::Mayor3(int num1, int num2, int num3){
    if(num1 >= num2 && num1 >= num3){
        return num1;
    } else if(num2 >= num1 && num2 >= num3) {
        return num2;
    } else {
        return num3;
    }   
}

void Mate::Operaciones(int num1, int num2, int* suma, int* resta, int* producto, float* cociente){
    *suma = num1 + num2;
    *resta = num1 - num2;
    *producto = num1 * num2;
    *cociente = (float)num1 / num2;
}

bool Mate::ParesRango(int num){

    if(num < 100 || num > 200 || num % 2 != 0)
        return false;
    
    for(int i = num, renglon = 1; i <= 200; i+=2, ++renglon){
        printf("%d\t", i);
        if(renglon % 10 == 0)
            printf("\n");
    }
    
    return true;
}

double Mate::PromedioHasta0(){
    double promedio = 0;
    int entrada = 0;
    int i = 0;
    do{
        promedio += entrada;
        printf("Introduce un número: (0-Salir): ");
        fflush(stdout);
        scanf("%d", &entrada);
        if(entrada != 0)++i;
    }while(entrada != 0);
    promedio /= (double)i;
    return promedio;
}

double Mate::Serie100(){
    double suma = 1;
    for(int i = 2; i <= 200; i+=4){
        suma -= 1.0 / i;
        suma += 1.0 / (i+2);
    }
    return suma;
    
    

}

void Mate::AreaEsfera(float radio, float* area){
    *area = 4 * M_PI * radio * radio;
}

bool Mate::SenX(int catetoOp, int hipotenusa, double* senX){
    if(0 == hipotenusa) return false;
    *senX = catetoOp / (double) hipotenusa;
    return true;

}

bool Mate::CosX(int catetoAd, int hipotenusa, double* cosX){
    if(0 == hipotenusa) return false;
    *cosX =  catetoAd / (double) hipotenusa;
    return true;
}

bool Mate::FormGeneral(double a, double b, double c, double* x1, double* x2){
    if((b * b - 4 * a * c) < 0 || 0 == a){  // Valida discriminante y división entre cero
        return false;
    } else {
        *x1 = (- b + sqrt(b * b - 4 * a * c)) / (2 * a);
        *x2 = (- b - sqrt(b * b - 4 * a * c)) / (2 * a);
    }
    return true;
}

void Mate::Mayor_Menor5(int n1, int n2, int n3, int n4, int n5, int* mayor, int* menor){
    *mayor = n1;
    if(n2 > *mayor) *mayor = n2;
    if(n3 > *mayor) *mayor = n3;
    if(n4 > *mayor) *mayor = n4;
    if(n5 > *mayor) *mayor = n5;
    *menor = n1;
    if(n2 < *menor) *menor = n2;
    if(n3 < *menor) *menor = n3;
    if(n4 < *menor) *menor = n4;
    if(n5 < *menor) *menor = n5;
    
}

void Mate::EstadisticosCiclo(int nDatos, int* mayor, int* menor, int* suma, double* promedio){

    int actual;
    printf("Proporcione el dato %d: ", 1);
    fflush(stdout);
    scanf("%d", &actual);

    *suma = actual;    
    *mayor = *menor = actual;
    
    for(int i = 2; i <= nDatos; ++i){
        printf("Proporcione el dato %d: ", i);
        fflush(stdout);
        scanf("%d", &actual);
        
        *suma += actual;
        if(actual > *mayor) *mayor = actual;
        else if(actual < *menor) *menor = actual;
    }
    *promedio = (float) *suma / nDatos;
    
}

void Mate::SumaNImpares(int n, int* suma){  // Es más legible una función int
    int impar = 1;                          // Ya que solo regresaría un valor
    *suma = 0;
    for(int i = 0; i < n; ++i){
        *suma += impar;
        impar += 2;
    }
}



