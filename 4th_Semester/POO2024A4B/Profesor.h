/* 
 * File:   Profesor.h
 * Author: Adro Ornelas
 *
 * Created on 21 de junio de 2024, 08:58 AM
 */

#ifndef PROFESOR_H
#define PROFESOR_H

class Profesor {
private:
    char name[50];
    int code_reg;
    int year_enroll;
public:
    Profesor(char*, int, int);
    void despliega();
};

#endif /* PROFESOR_H */

