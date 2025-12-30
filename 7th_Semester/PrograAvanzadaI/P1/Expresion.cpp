// Expresion.cpp

#include "Expresion.h"
#include <cstdlib>
#include <iostream>
#include <string>

Expresion::Expresion(std::string s_expresion) {
    
    p = NULL;
    std::cout << llenarExpresion(s_expresion);

}

Expresion::~Expresion() {

}


/*
    Función llenarExpresion
    Llena la lista (estructura de datos) con los elementos del arreglo
    Retorna false si la expresión es inválida
    Retorna true si se llenó correctamente
*/

bool Expresion::llenarExpresion(std::string s_expresion) {
    
    int numerador, denominador;
    char express;   // Guarda operador de expresión
    bool signoDiv;  // Flag para saber si numerador o denominador

    // Valores iniciales
    numerador = denominador = express = 0;
    signoDiv = false;

    // Si no está vacía
    if(!s_expresion.empty()) {

        // Recorre cadena
        for(int i = 0; i < s_expresion.length(); ++i) {
            
            // Si es un número
            if('0' <= s_expresion[i] && s_expresion[i] <= '9') {

                // Si no hay signo es numerador
                if(!signoDiv) {
                    numerador *= 10;
                    numerador += s_expresion[i] - '0';
                } else {    // Si no es denominador
                    denominador *= 10;
                    denominador += s_expresion[i] - '0';
                }

            } else {

                /*
                // Si no es cualquiera de estos, es inválido
                if( express != '+' && express != '-' &&
                    express != '*' && express != '/' &&
                    express != ' ')
                    return false;
*/
                
                if(!signoDiv && s_expresion[i] == '/'){
                    // Cuando se recibe el signo de división activa bandera
                    signoDiv = true;

                } else {
                    
                    express = s_expresion[i];

                    /*
                        En este caso ya recibió un fracción entera
                        Inserta fracción en lista y reinicia valores
                    */
                    if(express == '+' || express == '-' ||
                       express == '*' || express == '/') {

                        // Inserta nodo
                        Numero tmp(numerador, denominador);
                        std::cout << "Insertado "; tmp.imprimir();
                        insertar(tmp, express);

                        // Reinicia valores
                        numerador = denominador = express = 0;
                        signoDiv = false;
                        

                    }


                }                   
            }
        }

        // Inserta última fracción sin operador
        Numero tmp(numerador, denominador);
        insertar(tmp, '\0');

        return true;
    }
    return false;
    
}

bool Expresion::insertar(Numero num, char express) {

    // Crea nuevo objeto
    nodoN *nNew = (nodoN*) malloc(sizeof(nodoN));

    // Llena nuevo nodo
    nNew->num = num;
    nNew->operacion = express;
    nNew->nNext = NULL;

    // No hay memoria
    if(nNew == NULL)
        return false;

    // Inserción al inicio
    if(p == NULL) {
        p = nNew;

    } else {

        nodoN *ptmp = p;

        // Llega al último nodo (ptmp)
        while(ptmp->nNext != NULL)
            ptmp = ptmp->nNext;

        // Inserta
        ptmp->nNext = nNew;

    }
    return true;
}

void Expresion::resolver() {

    nodoN *ptmp, *pold;
    ptmp = pold = p;

    // jerarq 1 es suma/resta, jerarq2 es multiplicacion/div
    bool jerarq1; // jerarq2;  

    // Será true cuando ya no haya división ni multiplicación
    jerarq1 = false;

    // Hasta que quede un solo elemento
    while(p->nNext != NULL) {



        // Revisa por jerarquía
        if(jerarq1 == false) {
            
            // Multiplicación y divisiones

            if(ptmp->operacion == '/' || ptmp->operacion == '*') {

                
                if(ptmp->operacion == '/') {

                    ptmp->num.dividir(ptmp->nNext->num);
                } else {
                    // Siempre multiplicación
                    ptmp->num.multiplicar(ptmp->nNext->num);
                }

                // Asignar operación al nodo ptmp
                ptmp->operacion = ptmp->nNext->operacion;

                // Asina dirección al siguiente nodo
                pold = ptmp->nNext;
                ptmp->nNext = ptmp->nNext->nNext;
                
                free(pold);
                


            }




        } else {    
            // Suma y resta

            
        }
        
        // Itera al siguiente nodo
        pold = ptmp;
        ptmp = ptmp->nNext;
        
        // Si llegó al final, inicia de nuevo
        if(ptmp == NULL) {
            ptmp = p;

            // La segunda pasada es para primer nivel de jerarquía de operaciones
            jerarq1 = true;
        }

    }   
    

}

void Expresion::imprimirExpr() {
    
    std::cout << "Expresión:\n";
    // Si no está vacía
    if(p != NULL) {

        nodoN *ptmp = p;
        while(ptmp != NULL){
            ptmp->num.imprimir();
            std::cout << ' ' << ptmp->operacion << ' ';
            ptmp = ptmp->nNext;
        }
                       
    }
}