#include<math.h>
#include "Fisica.h"


bool Fisica::ChoqueTrenes(double v1, double v2, double d, double a){
    return ( d < (pow(v1 - v2, 2) / (2 * a)) ) ? true : false;
}

