// Expresion.h

/*
    Una expresión es una estructura de datos,
    donde cada nodo contiene un Numero (fracción)
    y un operando que apunt al siguiente

    TDP: JERARQUÍA DE OPERACIONES
    TDP: PARÉNTESIS

*/

#include <string>
#include <vector>
#include "Numero.h"

/*
    Cada nodo tiene:
    - Un número (fracción)
    - La operación al siguiente Nodo
    - Apuntador a siguiente Nodo

    Esto es, prácticamente una
    lista simplemente ligada
    sin nodo cabeza
    insercion por posición
*/

typedef struct nodoN {

    Numero num;
    char operacion;
    nodoN* nNext;

} nodoN;

class Expresion {

    public:

    Expresion(std::string);
    ~Expresion();
    bool llenarExpresion(std::string);  // Llena lista
    void resolver();    // Resuelve expresión y deja un sólo nodo con el resultado
    void imprimirRes();

    void imprimirExpr();

    bool insertar(Numero, char);

    private:
    
    nodoN* p;   // Apuntador principal

};