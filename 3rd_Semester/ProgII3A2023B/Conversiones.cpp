#include "Conversiones.h"

float Conversiones::kmToM(float km){
    return km / 1.609;
}

float Conversiones::farnhToCelcius(float Farnh){
    return (Farnh -32) * 5.0 / 9.0;
}


