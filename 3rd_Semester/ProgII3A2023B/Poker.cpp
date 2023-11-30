#include "Poker.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

Poker::Poker() {
    for(int i = 0; i < BARAJAS * 52; ++i)
        mazo[i] = -1;
    indiceMazo = 0;
}

void Poker::Barajar(){
    srand(time(0));
    bool existe;
    for(int i = 0, random; i < BARAJAS * 52; ++i){  // LLena de 0 - 51
        random = rand() % (BARAJAS * 52);
        existe =  false;
        for(int j = 0; j < i; ++j)
            if(random == mazo[j]){
                existe = true;
                --i;
                break;
            }
        if(!existe)
            mazo[i] = random;
    }        
}
bool Poker::EsCorrida(int jugador, int* cartaMenor, int* cartaMayor){
    return false;
}
bool Poker::EsPar(int jugador, int* valor){
    int repeticiones = 0, indicePar;
    for(int i = 0; i < MANO_TAM -1; ++i)
        for(int j = i + 1; j < MANO_TAM; ++j)
            if(Valor(mano[jugador][i]) == Valor(mano[jugador][j])){
                ++repeticiones;
                indicePar = i;
            }else 
                if(repeticiones > 1) return false;
    if(1 == repeticiones){
        *valor = Valor(mano[jugador][indicePar]);
        return true;
    }
    return false;
}
bool Poker::EsFlorImperial(int jugador, int* valor){
    return false;
}
bool Poker::EsFlor(int jugador, int* color){
    return false;
}
bool Poker::EsQuintilla(int jugador, int* valor){
    return false;
}
bool Poker::EvaluaManos(){
    int jugador, valor, cartaMenor, cartaMayor, valorTercia, valorPar;
    int color, valorMenor;
    int carMayor[JUGADORES] = {-1},
        carMenor[JUGADORES] = {-1},
        col[JUGADORES] = {-1},
        val[JUGADORES] = {-1};
    
    
    for(int i = 0; i < JUGADORES; ++i){
        vmano[i] = ValorMano(i,&valor,&cartaMenor,&cartaMayor,
                  &valorTercia,&valorPar,
                  &color,&valorMenor);
        val[i] = valor;
        carMenor[i] = cartaMenor;
        carMayor[i] = cartaMayor;
        col[i] = color;
    }
}
void Poker::DespliegaCarta(int carta){
    int valor = Valor(carta);
    int palo = Palo(carta);
    DespliegaValor(valor);
    printf(" de ");
    DespliegaPalo(palo);
    printf("\n");
}
void Poker::DespliegaMano(int jugador){
    printf("JUGADOR %d:\n", jugador + 1);
    for(int i = 0; i < MANO_TAM; ++i){
        DespliegaCarta(mano[jugador][i]);
    }
    printf("\n");
}
void Poker::DespliegaManosss(){
    for(int i = 0; i < JUGADORES; ++i){
        DespliegaMano(i);
    }
}
void Poker::DespliegaPalo(int carta){
    switch(carta){
        case 0:
            printf("Corazones");
            break;
        case 1:
            printf("Picas");
            break;
        case 2:
            printf("Diamantes");
            break;
        case 3:
            printf("Tréboles");
            break;
    }
}
void Poker::DespliegaValor(int carta){
    switch(carta){
        case 0:
            printf("Az");
            break;
        case 1:
            printf("Dos");
            break;
        case 2:
            printf("Tres");
            break;
        case 3:
            printf("Cuatro");
            break;
        case 4:
            printf("Cinco");
            break;
        case 5:
            printf("Seis");
            break;
        case 6:
            printf("Siete");
            break;
        case 7:
            printf("Ocho");
            break;
        case 8:
            printf("Nueve");
            break;
        case 9:
            printf("Diez");
            break;
        case 10:
            printf("Joto");
            break;
        case 11:
            printf("Reina");
            break;
        case 12:
            printf("Rey");
            break;
    }
}
void Poker::NuevaMano(int jugador){
    for(int i = 0; i < MANO_TAM; ++i){
        mano[jugador][i] = mazo[indiceMazo];
        mazo[indiceMazo] = -1;
        ++indiceMazo;
    }
}
void Poker::RepartoInicial(){
    for(int i = 0; i < JUGADORES; ++i){
        NuevaMano(i);
    }
}
int Poker::Palo(int carta){
    return (carta / 13) % 4;
}
void Poker::PruebaMano(){
    // Flor
    mano[0][0] = 1;
    mano[0][1] = 3;
    mano[0][2] = 5;
    mano[0][3] = 10;
    mano[0][4] = 12;
    // Escalera
    mano[0][0] = 1;
    mano[0][1] = 2;
    mano[0][2] = 3;
    mano[0][3] = 4;
    mano[0][4] = 5;
}
void Poker::PrintMazo(){
    for(int i = 0; i < BARAJAS * 52; ++i){
        DespliegaCarta(mazo[i]);
    }
}
int Poker::Valor(int carta){
    return carta % 13;
}
int Poker::ValorMano(int jugador, int* valor, int* cartaMenor,
                     int* cartaMayor, int* valorTercia,
                     int* valorPar, int* color, int* valorMenor){
    if(EsFlorImperial(jugador, valor)){
        printf("Jugador %d tuvo flor imperial\n", jugador);
        return 11;
    }
     
    if(EsQuintilla(jugador, valor)){
        printf("Jugador %d tuvo quintilla de %d\n", jugador, *valor);
        return 10;
    }
    if(EsCorrida(jugador, cartaMenor, cartaMayor)){
        printf("Jugador %d tuvo escalera de ", jugador+1);
        DespliegaValor(*cartaMenor);
        printf(" al ");
        DespliegaValor(*cartaMayor);
        printf("\n");
        return 6;
    }
    if(EsFlor(jugador, color)){
        printf("Jugador %d tuvo flor de ", jugador+1);
        DespliegaPalo(*color);
        printf("\n");        
        return 4;
    }
    if(EsPar(jugador, valor)){
        printf("Jugador %d tuvo par de ", jugador+1);
        DespliegaValor(*valor);
        printf("\n");
        return 2;
    }
    return 0;
}