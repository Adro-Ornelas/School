// Matriz.cpp

#include <iostream>
#include "Matriz.h"

// Para iniciar una matriz define filas y columas
Matriz::Matriz(int rows, int cols){
    setSize(rows, cols);
    /*
        Marca todas las casillas como 0 (valor por defecto)
    */
    for(int r = 0; r < rows; ++r) {
        for(int c = 0; c < cols; ++c) {
            contenido[r][c] = 0;
        }
    }
}

Matriz::~Matriz() {
    //std::cout << "Destruido";   
}

/* 
    Para poder multiplicar matrices, la primera debe tener el mismo
    número de columas que filas de la segunda
*/
bool Matriz::isMultiplicable(Matriz matriz) {
    return (cols == matriz.rows);
}

/*
    Para poder sumar y restar matrices, deben ser del mismo tamaño
*/
bool Matriz::isSumable(Matriz matriz) {

    return ((rows == matriz.rows) && (cols == matriz.cols) );

}

Matriz Matriz::sumar(Matriz matriz) {
    
    // La matriz resultante sería del mismo tamaño
    Matriz resultM(rows, cols);

    if(isSumable(matriz)){

        // Si es sumable, suma
        for(int r = 0; r < rows; ++r) {
            for(int c = 0; c < cols; ++c) {
                resultM.contenido[r][c] = contenido[r][c] + matriz.contenido[r][c];
            }
        }
      

    } else {
        std::cout << "No es sumable";
    }
    return resultM;
}

Matriz Matriz::restar(Matriz matriz) {
    
    // La matriz resultante sería del mismo tamaño
    Matriz resultM(rows, cols);

    if(isSumable(matriz)){

        // Si es restable, resta
        for(int r = 0; r < rows; ++r) {
            for(int c = 0; c < cols; ++c) {
                resultM.contenido[r][c] = contenido[r][c] - matriz.contenido[r][c];
            }
        }
      
    } else {
        std::cout << "No es restable";

        // El resultado tiene un tamaño de 0x0 (inválido)
        resultM.setSize(0, 0);
    }
 
    return resultM;
}

Matriz Matriz::multiplicar(Matriz matriz) {

    /*
        La matriz resultante tendrá el número de filas de la primera
        y el número de columnas de la segunda
    */
    Matriz resultM(rows, matriz.cols);

    if(isMultiplicable(matriz)) {

        // Guardará el resultado de la suma de multiplicaciones
        double resul_mult;

        // Si es multiplicable, multiplica
        for(int r = 0; r < rows; ++r) {
            for(int c = 0; c < matriz.cols; ++c) {
                
                resul_mult = 0;
                // Suma el proucto de filas por columa
                for(int i = 0; i < cols; ++i) {
                    resul_mult += contenido[r][i] * matriz.contenido[i][c];
                }

                // Añade resultado a matriz resultante
                resultM.contenido[r][c] = resul_mult;
            }
        }    

    } else {
        std::cout << "No es multiplicable";
        
        // El resultado tiene un tamaño de 0x0 (inválido)
        resultM.setSize(0, 0);
    }

    return resultM;

}

Matriz Matriz::operator+(Matriz matriz) {
    return sumar(matriz);
}
Matriz Matriz::operator-(Matriz matriz) {
    return restar(matriz);
}
Matriz Matriz::operator*(Matriz matriz) {
    return multiplicar(matriz);
}

void Matriz::imprimir() {

    for(int r = 0; r < rows; ++r) {
        for(int c = 0; c < cols; ++c) {
            std::cout << "[" << contenido[r][c] << "]";
        }
        std::cout << "\n";
    }
}

void Matriz::llenarMatriz(void) {

    for(int r = 0; r < rows; ++r){
        for(int c = 0; c < cols; ++c) {
            std::cout << "Elemento [" << r << "][" << c << "]: ";
            std::cin >> contenido[r][c];
        }
    }
}

void Matriz::setSize(int rows, int cols) {
    this->rows = rows;
    this->cols = cols;
}

int Matriz::getRows() {
    return rows;
}

int Matriz::getCols() {
    return cols;
}