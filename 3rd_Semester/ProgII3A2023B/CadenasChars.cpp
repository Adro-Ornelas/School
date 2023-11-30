#include "CadenasChars.h"

CadenasChars::CadenasChars() {
}

void CadenasChars::Invierte(char cad[]){
    char tmp;
    for(int i = 0, j = strlen(cad) - 1; i < j; ++i, --j){
        tmp = cad[i];
        cad[i] = cad[j];
        cad[j] = tmp;
    }
}

void CadenasChars::CadToAtlas(char cadena[]){
    // i < strlen(cadena);
    for(int i = 0; cadena[i] != '\n'; ++i){
        if(cadena[i] >= 'a' && cadena[i] <= 'z')
            cadena[i] -=32;
    }
}

int CadenasChars::NumMinus(char cadena[]){
    int minus = 0;
    for(int i = 0; i < strlen(cadena); ++i){
        if(cadena[i] >= 'a' && cadena[i] <= 'z')
            ++minus;
    }
    return minus;
}

int CadenasChars::NumPalabras(char cadena[]){
    int palabras = 0;
    int i;
    for(i = 0; i < strlen(cadena); ++i)
        if(cadena[i] != ' ')
            if(cadena[i] != '\t')
                if(cadena[i] != '\n')
                    if(cadena[i+1] == ' '  ||
                       cadena[i+1] == '\t' ||
                       cadena[i+1] == '\n')
                        ++palabras;
    return palabras;
}

int CadenasChars::NumVocales(char cadena[]){
    int numb=0;
    for(int i = 0; i < strlen(cadena); ++i)
        switch(cadena[i]){
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                ++numb;
                break;
        }
    return numb;
}