/* 
 * File:   Departamento.cpp
 * Author: Adro Ornelas
 * 
 * Created on 21 de junio de 2024, 08:58 AM
 */

#include <iostream>
#include "Departamento.h"
#include "String.h"

Departamento::Departamento(char nombreProfe[50], int numRegistro,
                           int anio_registro, char nombreDepa[50],
                           int codigoDepa)
    : teacherEins(nombreProfe, numRegistro, anio_registro)
{    
    strcpy(nameDepa, nombreDepa);
    codeDepa = codigoDepa;
}

void Departamento::despliega(){
    std::cout << "Bienvenido al departamento de " << nameDepa << "\n"
              << "Este departamento tiene el código " << codeDepa << "\n"
              << "Procedemos a mostrar la información del profesor encargado:"
              << std::endl;
    teacherEins.despliega();
}



