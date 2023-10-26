#include "Games.h"
#include <stdio.h>

int Games::Boliche(){
    int total_puntos = 0,
        tiro1 = 0,
        tiro2 = 0,
        chuza_spair = 0,// Bolas que serán tomadas en cuenta como doble o triple
        chuzas_count = 0;
    
    for(int i = 1; i <= 10; ++i){
        printf("Tiro %d, bola 1: ", i);
        fflush(stdout);
        scanf("%d", &tiro1);
        
        if(tiro1 == 10){
            ++chuzas_count;
            if(chuza_spair > 0){
                if(chuzas_count >= 3)
                    // Para 2 o más chuzas seguidas:
                    total_puntos += tiro1 * 3;
                else  // Para 1 y dos chuzas anteriores:
                total_puntos += tiro1 * 2;
                    
                --chuza_spair;
            } else {
                total_puntos += tiro1;
            }
            chuza_spair = 2;    // Serán contados los sig. dos tiros
        } else {
            if(chuza_spair > 0){
                if(chuzas_count >= 3)
                    // Para 2 o más chuzas seguidas:
                    total_puntos += tiro1 * 3;
                else  // Para 1 y dos chuzas anteriores:
                total_puntos += tiro1 * 2;
                
                --chuza_spair;
                chuzas_count = 0;   // Rompe racha de chuzas
            } else {
                total_puntos += tiro1;
                
                chuzas_count = 0;
            }
            printf("Tiro %d, bola 2: ", i);
            fflush(stdout);
            scanf("%d", &tiro2);
            
            if(chuza_spair > 0){
                total_puntos += tiro2 * 2;
                --chuza_spair;
            } else {
                total_puntos += tiro2;
            }
            
            if(tiro1 + tiro2 == 10)
                chuza_spair = 1;
        }
    }
   
    while(chuza_spair > 0){
            printf("Tiro 11, bola %d: ", (3 - chuza_spair) );
            fflush(stdout);
            scanf("%d", &tiro1);
            if(chuzas_count >= 3){
                total_puntos += tiro1 * 2;
                chuzas_count = 0; // Rompe la racha de chuzas
            } else
                total_puntos += tiro1;
            
            --chuza_spair;
    }
    
    return total_puntos;
}

int Games::Balero(){
    int tipo_tiro;
    int total = 0;
    for(int i = 1; i <= 20; ++i){
        printf("\nTiro %d:", i);
        tipo_tiro = TipoDeTiroBalero();
        int acertado;
        printf("¿Fue acertado? (1) SÍ (0) NO: ");
        fflush(stdout);
        scanf("%d", &acertado);
        if(acertado){
            switch(tipo_tiro){
                case 1: total += 1;
                break;
                case 2: total += 5;
                break;
                case 3: 
                case 4: total += 10;
                break;
                case 5: total += 50;
                break;
                case 6: total += 100;
                break;
                case 7: total += 250;
                break;
                case 8: total += 500;
                break;
            }
        }
    }
    return total;
}

int Games::TipoDeTiroBalero(){
    int tipo;
    printf("\n"
           "1) Sencillo\n"
           "2) Capirucho sencillo\n"
           "3) Clásico\n"
           "4) Capirucho complicado\n"
           "5) Cruzado\n"
           "6) Revés\n"
           "7) Jalón\n"
           "8) Invertido");
    do{
    printf("\nSeleccione el tipo de tiro (1-8): ");
    fflush(stdout);
    scanf("%d", &tipo);
    } while(tipo > 8 || tipo < 1);
    return tipo;
}

