/* 
 * File:   Curso.cpp
 * Author: Adro Ornelas
 * 
 * Created on 16 de febrero de 2024, 03:10 PM
 */

#include "Curso.h"
#include <iostream>
#include <String.h>

Curso::Curso(char nombreDocente[50], int numRegistro, int anio_registro,
             char nombreCurso[50], char cicloEscolar[50], int codeClase)
             : teacher(nombreDocente, numRegistro, anio_registro)
{
    strcpy(courseName, nombreCurso);
    strcpy(school_cycle, cicloEscolar);
    course_code = codeClase;
}

void Curso::print(){
    std::cout << "Bienvenido al curso " << courseName << '\n'
              << "del ciclo " << school_cycle << " con código "
              << course_code << "\nEscuche la presentación de tu maestro:"
              << std::endl;
    teacher.despliega();
}

