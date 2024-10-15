/* 
 * File:   LDLCIRCIPCNC.h
 * Author: Adro Ornelas
 *
 * Created on 3 de octubre de 2024, 09:57 AM
 */

#ifndef LDLCIRCIPCNC_H
#define LDLCIRCIPCNC_H


struct NodoD {
    int dato;
    NodoD* pizq;
    NodoD* pder;
};

class LDLCIRCIPCNC {
protected:
    struct NodoD* p;
    
public:
    LDLCIRCIPCNC();
    virtual ~LDLCIRCIPCNC();

    int  cardinalidad();
    void despliega();
    bool eliminar(int *dato, int pos);
    bool esElemento(int dato);
    bool esVacia();
    bool insertar(int dato, int pos);
};

#endif /* LDLCIRCIPCNC_H */

