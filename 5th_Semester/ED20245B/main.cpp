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
#include "LDLTNIPSNC.h"

#include "LDLCIRCIVSNC.h"

using namespace std;

int main(int argc, char** argv)
{    
    //* LISTAS CON INSERCIÓN POR VALOR:
    
    /* DONE LISTS:
        LSLTNIVSNC list;   
        LSLTNIVCNC list;
        LSLCIRCIVSNC list;    
        LSLCIRCIVCNC list;
 
     */
    
    
    LDLCIRCIVSNC list;
    
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
      
    
    
    //* LISTAS CON INSERCIÓN POR POSICIÓN:
    /*
     DONE LISTS
     
        LSLTNIPSNC l;
        LSLTNIPCNC l;  
        LSLCIRCIPSNC l;
        LSLCIRCIPCNC l;
        
        LDLCIRCIPCNC l;
        LDLTNIPSNC l;
    */
    
    /*
  
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
    if(l.esVacia())
        cout << "Es vacía" << endl;
    cout << "Hay " << l.cardinalidad() << endl;
    l.insertar(7,1); // vacia
    l.despliega();
    cout << "Hay " << l.cardinalidad() << endl;
     */
    return 0;
}

    