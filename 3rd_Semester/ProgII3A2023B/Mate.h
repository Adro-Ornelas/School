#ifndef MATE_H
#define MATE_H

class Mate {
    public:
        void AdivinaMiNum(int, int);
        double AreaCilindro(double, double);
        
        double SeriePi();
        void EstadisticosCiclo(int nDatos, int* mayor, int* menor, int* suma,
                               double* promedio);
        void Factores(int num);
        int Invertido(int num);
        bool Multiplo(int, int);
        int Mayor3(int, int, int);
        void Operaciones(int num1, int num2, int* suma,
             int* resta, int* producto, float* cociente);   // A donde apunta
        bool ParesRango(int num);
        double PromedioHasta0();
        double Serie100();
        void AreaEsfera(float radio, float* area);
        void SumaNImpares(int n, int* suma);
        bool SenX(int catetoOp, int hipotenusa, double* senX);
        bool CosX(int catetoAd, int hipotenusa, double* cosX);
        bool FormGeneral(double a, double b, double c, double* x1, double* x2);
        void Mayor_Menor5(int n1, int n2, int n3, int n4, int n5, int* mayor, int* menor);

};

#endif /* MATE_H */

