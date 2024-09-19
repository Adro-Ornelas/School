#include <iostream>

// #include "LSLTNIVSNC.h"
#include "LSLCIRCIVSNC.h"
#include "LSLCIRCIPCNC.h"
#include "LSLTNIPCNC.h"
using namespace std;

int main(int argc, char** argv) {
    
    /*
    // LSLTNIVSNC list;
    LSLCIRCIVSNC list;   
    
    cout << (list.esVacia() ? "Vacía":"No vacía") << endl;
    cout << "Hay " << list.cardinalidad() << endl;
    list.insertar(15);  // Empty
    list.despliega();
    cout << "Hay " << list.cardinalidad() << endl;
    list.insertar(7);   // At the beginning
    cout << "Hay " << list.cardinalidad() << endl;
    list.insertar(49);  // At the end
    list.despliega();
    cout << "Hay " << list.cardinalidad() << endl;
    cout << (list.esVacia() ? "Vacía":"No vacía") << endl;
    cout << "Buscando el número 15... ";
    cout << ( (list.esElemento(15)) ? "sí ":"no " ) << "está" << endl;
    cout << "Buscando el número 999... ";
    cout << ( (list.esElemento(999)) ? "sí ":"no " ) << "está" << endl;
    list.insertar(30);   // In the middle;
    list.despliega();
    list.eliminar(15);
    cout << "El 15 eliminado" << endl;
    list.despliega();
    list.eliminar(49);
    cout << "El 49 eliminado" << endl;
    list.despliega();
    list.eliminar(7);
    cout << "El 7 eliminado" << endl;
    list.despliega();
    cout << "Hay " << list.cardinalidad() << endl;
    list.insertar(1);   // In the middle;
    list.despliega();
    cout << "Hay " << list.cardinalidad() << endl;
    */
    
    // LSLCIRCIPCNC list;
    LSLTNIPCNC list;
    LSLCIRCIPCNC l;
    l.insertar(7,1); // vacia
    l.despliega();
    l.insertar(15,1); // inicio
    l.despliega();
    l.insertar(37,3); // final
    l.despliega();
    l.insertar(49,3); // en medio
    l.despliega();
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

    return 0;
}

    