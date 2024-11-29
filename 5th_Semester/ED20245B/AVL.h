/* 
 * File:   AVL.h
 * Author: Adro Ornelas
 *
 * Created on 28 de noviembre de 2024, 03:53 PM
 */

#ifndef AVL_H
#define AVL_H

#include "ABB.h"

class AVL : public ABB{
    
protected:
    void ddRotation(struct NodoA *pdad, struct NodoA *ptmp);
    void diRotation(struct NodoA *pdad, struct NodoA *ptmp);
    void idRotation(struct NodoA *pdad, struct NodoA *ptmp);
    void iiRotation(struct NodoA *pdad, struct NodoA *ptmp);
    
public:    
    bool inserta(int dato);
    
private:

};

#endif /* AVL_H */

