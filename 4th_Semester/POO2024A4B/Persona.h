/* 
 * File:   Persona.h
 * Author: Adro Ornelas
 *
 * Created on 16 de febrero de 2024, 03:01 PM
 */

#ifndef PERSONA_H
#define PERSONA_H
#include "Fecha.h"

class Persona {
private:
    Fecha bornDate;
    char name[50];
    char adress[40];
    unsigned int  phonenumb;
    char gender;
    
public:
    Persona(unsigned int f, char nom[50], char dir[50], unsigned int telefon, char genero);
    void print();
};

#endif /* PERSONA_H */

