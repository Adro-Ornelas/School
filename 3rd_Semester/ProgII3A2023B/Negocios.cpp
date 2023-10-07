#include "Negocios.h"

#define IVA 0.15

void Negocios::calcIVA(float monto, float* iva, float* con_iva){
    *iva = monto * IVA;
    *con_iva = monto + *iva;
}
