/* 
 * File:   Profesor.cpp
 * Author: Adro Ornelas
 * 
 * Created on 21 de junio de 2024, 08:58 AM
 */

#include "Profesor.h"
#include <iostream>
#include <String.h>

Profesor::Profesor(char nombre[50], int numRegistro, int anio_registro)
{
    strcpy(name, nombre);
    code_reg = numRegistro;
    year_enroll = anio_registro;
}

void Profesor::despliega(){
    std::cout << "Profesor: " << name << "\nCodigo: " << code_reg
              << "\nAño de de ingreso: " << year_enroll
              << std::endl;
}
