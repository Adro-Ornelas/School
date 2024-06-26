/* 
 * File:   Curso.h
 * Author: Adro Ornelas
 *
 * Created on 16 de febrero de 2024, 03:10 PM
 */

#ifndef CURSO_H
#define CURSO_H
#include "Profesor.h"

class Curso {
private:
    Profesor teacher;
    char courseName[50];
    char school_cycle[10];
    int course_code;
public:
    Curso(char*, int, int, char*, char*, int);
    void print();
};

#endif /* CURSO_H */

