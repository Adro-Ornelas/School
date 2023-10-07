#include "Fechas.h"

int Fechas::Anio(int fec){
    return fec / 10000;
}

int Fechas::Dia(int fec){
    return fec % 100;
}

bool Fechas::EsBisiesto(int anio){
    if(anio % 4 == 0)
        if(anio <= 1582)
            return true;    // 1500
        else
            if(anio % 100 == 0)
                if(anio % 400 == 0)
                    return true;    // 2000    
                else
                    return false;   // 2100
            else
                return true;        // 2024
    else 
        return false;   // 2023
    
}

int Fechas::Mes(int fec){
    return (fec / 100) % 100;
}



