#ifndef ARREGLOSNUMERICOS_H
#define ARREGLOSNUMERICOS_H

#define TAMARAR 11

class ArreglosNumericos {
public:
    ArreglosNumericos(bool randomize);
    
    void CorreDados();
    void Despliega();
    void DespliegaArr(int arr[], int tam);
    int DifConsecutivos();
    void DosMayores(int* mayor1, int* mayor2);
    int FactoresArr(int num, int arr[]);
    void FillArregloOrder(int arr[], int num, int tam);
    void DespliegaFactores(int arr[], int tam, int num);
    float Mediana(int arr[], int tam);
    
private:
    
    int arreglo1[TAMARAR];

};

#endif /* ARREGLOSNUMERICOS_H */

