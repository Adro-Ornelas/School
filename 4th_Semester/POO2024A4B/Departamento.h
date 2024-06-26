/* 
 * File:   Departamento.h
 * Author: Adro Ornelas
 *
 * Created on 21 de junio de 2024, 08:58 AM
 */

#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H

#include "Profesor.h"

class Departamento {
private:
    Profesor teacherEins;
    char nameDepa[50];
    int codeDepa;
public:
    Departamento(char*, int, int, char*, int);
    void despliega();
};

#endif /* DEPARTAMENTO_H */

