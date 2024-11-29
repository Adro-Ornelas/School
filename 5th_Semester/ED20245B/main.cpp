#include <iostream>

#include "LSLTNIVCNC.h"
#include "LSLTNIVSNC.h"
#include "LSLCIRCIVSNC.h"
#include "LSLCIRCIPCNC.h"

#include "LSLTNIPCNC.h"
#include "LSLTNIPSNC.h"
#include "LSLCIRCIVCNC.h"
#include "LSLCIRCIPSNC.h"

#include "LDLCIRCIPCNC.h"
#include "LDLCIRCIPSNC.h"
#include "LDLTNIPSNC.h"
#include "LDLTNIPCNC.h"

#include "LDLCIRCIVCNC.h"
#include "LDLCIRCIVSNC.h"
#include "LDLTNIVCNC.h"
#include "LDLTNIVSNC.h"

#include "Recursividad.h"
#include "ABB.h"
#include "AVL.h"

using namespace std;

int main(int argc, char** argv)
{    
    //* LISTAS CON INSERCIÓN POR VALOR:
    
    /* DONE LISTS:
        LSLTNIVSNC list;   
        LSLTNIVCNC list;
        LSLCIRCIVSNC list;    
        LSLCIRCIVCNC list;
 
        LDLTNIVSNC list;
        LDLTNIVCNC list;
        LDLCIRCIVSNC list;
        LDLCIRCIVCNC list;
     */
    /*
    LDLCIRCIVCNC list;
    
    cout << (list.esVacia() ? "Vacía":"No vacía") << endl;
    cout << "Hay " << list.cardinalidad() << endl;
    list.insertar(15);  // Empty
    list.despliega();
    cout << "Hay " << list.cardinalidad() << endl;
    list.insertar(7);   // At the beginning
    list.despliega();
    cout << "Hay " << list.cardinalidad() << endl;
    list.insertar(49);  // At the end
    list.despliega();
    cout << "Hay " << list.cardinalidad() << endl;
    list.insertar(30);   // In the middle;
    list.despliega();
    cout << "Hay " << list.cardinalidad() << endl;
    cout << (list.esVacia() ? "Vacía":"No vacía") << endl;
    cout << "Buscando el número 15... ";
    cout << ( (list.esElemento(15)) ? "sí ":"no " ) << "está" << endl;
    cout << "Buscando el número 999... ";
    cout << ( (list.esElemento(999)) ? "sí ":"no " ) << "está" << endl;
    list.eliminar(15);
    cout << "El 15 eliminado" << endl;
    list.despliega();
    cout << "Hay " << list.cardinalidad() << endl;
    list.eliminar(49);
    cout << "El 49 eliminado" << endl;
    list.despliega();
    cout << "Hay " << list.cardinalidad() << endl;
    list.eliminar(7);
    cout << "El 7 eliminado" << endl;
    if(!list.eliminar(999))
        cout << "No es posible elimnar un nodo que no existe" << endl;
    list.despliega();
    cout << "Hay " << list.cardinalidad() << endl;
    list.eliminar(30);
    cout << "El 30 eliminado" << endl;
    list.despliega();
    cout << "Hay " << list.cardinalidad() << endl;
    cout << (list.esVacia() ? "Vacía":"No vacía") << endl;           
    */
    //* LISTAS CON INSERCIÓN POR POSICIÓN:
    /*
     DONE LISTS
     
        LSLTNIPSNC l;
        LSLTNIPCNC l;  
        LSLCIRCIPSNC l;
        LSLCIRCIPCNC l;
        
        LDLCIRCIPSNC l;
        LDLCIRCIPCNC l;
        LDLTNIPSNC l;
    */
    /*
    LDLTNIPCNC l;
    
    cout << "Hay " << l.cardinalidad() << endl;
    if(l.esVacia())
        cout << "Es vacía" << endl;
    l.insertar(7,1); // vacia
    l.despliega();
    cout << "Hay " << l.cardinalidad() << endl;
    l.insertar(15,1); // inicio
    l.despliega();
    cout << "Hay " << l.cardinalidad() << endl;
    l.insertar(37,3); // final
    l.despliega();
    cout << "Hay " << l.cardinalidad() << endl;
    l.insertar(49,3); // en medio
    l.despliega();
    cout << "Hay " << l.cardinalidad() << endl;
    if(!l.insertar(14,14)) 
        cout << "Posicion Invalida" << endl;
    int valor;
    l.eliminar(&valor, 3); // en medio
    l.despliega();
    cout << "Elminaste el " << valor << endl; 
    l.eliminar(&valor, 1); // en inicio
    l.despliega();
    cout << "Elminaste el " << valor << endl; 
    if(!l.eliminar(&valor, 14)) cout << "Posicion invalida" << endl; // invalido
    l.eliminar(&valor, 2); // final
    l.despliega();
    cout << "Elminaste el " << valor << endl; 
    l.eliminar(&valor, 1); // ultimo
    l.despliega();
    cout << "Elminaste el " << valor << endl; 
    if(!l.eliminar(&valor, 1)) cout << "No se puede eliminar de una lista vacia\n";
    l.despliega();
    if(l.esVacia())
        cout << "Es vacía" << endl;
    
        
    Recursividad r;
    cout << endl;
    // cout << "Factorial de 7 es: " << r.factorial(7);
    cout << "5^4 = " << r.potencia(5, 4) << endl;
    */
    
    
    AVL bintree;
    cout << "Buscando 92..." << (bintree.esElemento(92) ? "SI":"NO")
         << " está" << endl;
    cout << (bintree.esVacia() ? "Vacio":"No Vacio");
    cout << "Hay" << bintree.cardinalidad() << endl;
    bintree.despliega();
    bintree.inserta(67);
    cout << "67 insertado" << endl;
    cout << "Hay" << bintree.cardinalidad() << endl;
    bintree.inserta(90);
    cout << "90 insertado" << endl;
    cout << "Hay " << bintree.cardinalidad() << endl;
    bintree.inserta(50);
    cout << "50 insertado" << endl;
    cout << "Hay " << bintree.cardinalidad() << endl;
    bintree.inserta(30);
    cout << "30 insertado" << endl;
    cout << "Hay " << bintree.cardinalidad() << endl;
    bintree.inserta(8);
    cout << "8 insertado" << endl;
    cout << "Hay " << bintree.cardinalidad() << endl;
    bintree.inserta(15);
    cout << "100 insertado" << endl;
    cout << "Hay " << bintree.cardinalidad() << endl;
    bintree.inserta(200);
    cout << "80 insertado" << endl;
    cout << "Hay " << bintree.cardinalidad() << endl;
    bintree.inserta(54);
    cout << "54 insertado" << endl;
    cout << "Hay " << bintree.cardinalidad() << endl;
    bintree.inserta(55);
    cout << "55 insertado" << endl;
    cout << "Hay " << bintree.cardinalidad() << endl;
    bintree.inserta(300);
    cout << "55 insertado" << endl;
    cout << "Hay " << bintree.cardinalidad() << endl;
    
    bintree.imprimirArbol();
    
    /*
    cout << "Buscando 8..." << (bintree.esElemento(8) ? "SI":"NO")
         << " está" << endl;
    cout << "Buscando 9..." << (bintree.esElemento(9) ? "SI":"NO")
         << " está" << endl;
    
    cout << "Buscando 30..." << (bintree.esElemento(30) ? "SI":"NO")
         << " está" << endl;
    
    if(!bintree.inserta(54))
        cout << "NO se puede insertar valor repetido" << endl;
    cout << (bintree.esVacia() ? "Vacio":"No Vacio") << endl;
    
    
    if(!bintree.elimina(51))
        cout << "NO es posile eliminar un nodo que no existe (15)" << endl;
    if(!bintree.elimina(68))
        cout << "NO es posile eliminar un nodo que no existe (68)" << endl;
    
    //bintree.~ABB();
    
    cout << bintree.elimina(8);    // Nodo sin hijos
    cout << " 8 eliminado" << endl;
    cout << "Hay " << bintree.cardinalidad() << endl;
    bintree.despliega();
    
    cout << bintree.elimina(50); // Nodo con dos hijos
    cout << " 50 eliminado" << endl;
    cout << "Hay " << bintree.cardinalidad() << endl;
    bintree.despliega();
    
    cout << bintree.elimina(54); // Nodo con dos hijos
    cout << " 54 eliminado" << endl;
    cout << "Hay " << bintree.cardinalidad() << endl;
    bintree.despliega();
        
    cout << bintree.elimina(90); // Nodo con dos hijos
    cout << " 90 eliminado" << endl;
    cout << "Hay " << bintree.cardinalidad() << endl;
    bintree.despliega();
    
    cout << bintree.elimina(67); // Nodo raíz
    cout << " 67 eliminado" << endl;
    cout << "Hay " << bintree.cardinalidad() << endl;
    bintree.despliega();
    
    cout << bintree.elimina(80); // Nodo raíz con 1 hijo por la derecha
    cout << " 80 eliminado" << endl;
    cout << "Hay " << bintree.cardinalidad() << endl;
    bintree.despliega();
    
    cout << bintree.elimina(55); // Nodo con 1 hijo por la izquierda
    cout << " 55 eliminado" << endl;
    cout << "Hay " << bintree.cardinalidad() << endl;
    bintree.despliega();
        
    cout << bintree.elimina(30); // Nodo  con 1 hijo por la izquierda
    cout << " 30 eliminado" << endl;
    cout << "Hay " << bintree.cardinalidad() << endl;
    bintree.despliega();
    
    cout << bintree.elimina(100); // Nodo raíz con 0 hijos
    cout << " 100 eliminado" << endl;
    cout << "Hay " << bintree.cardinalidad() << endl;
    bintree.despliega();
    
    cout << (bintree.esVacia() ? "Vacio":"No Vacio") << endl;
    bintree.despliega();
    
    */
    return 0;
}

    