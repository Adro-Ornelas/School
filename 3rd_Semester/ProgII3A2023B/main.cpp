#include <stdio.h>
#include "Conversiones.h"
#include "Fechas.h"
#include "Mate.h"
#include "Negocios.h"
#include "Nutrition.h"
#include "Fisica.h"
#include "Chars.h"
#include "Escuela.h"
#include "Games.h"
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv) {
    
    /*
    // FARENHETI TO CELCIUS
    Conversiones miConv;
    float farenheit, celcius;
    printf("Proporciona una temperatura en grados Farenheit: ");
    fflush(stdout);    // Vaciar e búfer de salida para mostrar mensaje inicial
    scanf("%f", &farenheit);
    celcius = miConv.farnhToCelcius(farenheit);
    printf("%f °F = %.2f °C", farenheit, celcius);
 
    
    // FECHAS AAAAMMDD 
    Fechas miFec;
    int fecha, a, m, d;
    printf("Introduce una fecha en formato AAAAMMDD: ");
    fflush(stdout);
    scanf("%d", &fecha);
    
    a = miFec.Anio(fecha);
    m = miFec.Mes(fecha);
    d = miFec.Dia(fecha);
    
    printf("La fecha %d quiere decir:"
           "\n%d Años \n%d Meses \n%d Días\n", fecha, a, m, d);
  
    
    // AREA CILINDRO
    Mate miMat;
    double h, r, area;
    printf("CALCULAR ÁREA DE UN CILINDRO\n");
    printf("Introduce la altura (h): ");
    fflush(stdout);
    scanf("%lf", &h);
    printf("Introduce el radio (r): ");
    fflush(stdout);
    scanf("%lf", &r);
    area = miMat.AreaCilindro(h, r);
    printf("El área es: %lf", area);
    
    
    // SI ES MÚLTIPLO
    Mate miMate;
    int num1, num2;
    printf("Dame un número: ");
    fflush(stdout);
    scanf("%d", &num1);
    printf("Dame otro número: ");
    fflush(stdout);
    scanf("%d", &num2);
    
    if(miMate.Multiplo(num1, num2)){
        printf("%d sí es múltiplo de %d", num2, num1);
    } else {
        printf("No es múltiplo");
    }
    
    
    // SI ES MÚLTIPLO
    Mate miMate;
    int num1, num2, num3, mayor;
    
    printf("Dame el primer número: ");
    fflush(stdout);
    scanf("%d", &num1);
    printf("Dame el segundo número: ");
    fflush(stdout);
    scanf("%d", &num2);
    printf("Dame el tercer número: ");
    fflush(stdout);
    scanf("%d", &num3);
    mayor = miMate.Mayor3(num1, num2, num3);
    printf("El número mayor es: %d", mayor);
       
    
    // PUNTEROS, OPERACIONES BÁSICAS
    // '*' a donde apunta  (desreferencia)
    // '&' la dirección de (referencia)
      
    Mate miMate;
    int num1, num2, suma, resta, multip;
    float divis;
    
    printf("Dame el primer número: ");
    fflush(stdout);
    scanf("%d", &num1);
    printf("Dame el segundo número: ");
    fflush(stdout);
    scanf("%d", &num2);
    
    // Dirección de
    miMate.Operaciones(num1, num2, &suma, &resta, &multip, &divis);
        
    printf("Suma:          d + d = %d \n"
           "Resta          d + d = %d \n"
           "Multiplicación d + d = %d \n"
           "División:      d + d = %f \n",
            suma, resta, multip, divis);
    
    
    // CALCULAR IVA
    Negocios miBusin;
    float monto, el_iva, con_iva;
    
    printf("Dame el monto a calcular su IVA: ");
    fflush(stdout);
    scanf("%f", &monto);
    miBusin.calcIVA(monto, &el_iva, &con_iva);
    printf("Monto original: %f\n"
           "Su IVA:         %f\n"
           "Monto + IVA:    %f\n",
           monto, el_iva, con_iva);   
   
       
    // RADIO ESFERA
    Mate miMate;
    float radio, area;
    printf("Dame el radio para calcular el área de su esfera: ");
    fflush(stdout);
    scanf("%f", &radio);
    miMate.AreaEsfera(radio, &area);
    printf("El área es: %f", area);
    

    // SENO
    Mate miMate;
    int cateO, hipot;
    double seno;
    
    printf("Introduce la longitud del cateto opuesto: ");
    fflush(stdout);
    scanf("%d", &cateO);
    printf("Introduce la longitud de la hipotenusa: ");
    fflush(stdout);
    scanf("%d", &hipot);
    if(miMate.SenX(cateO, hipot, &seno))
        printf("El seno de x = %lf", seno);   
    
    // COSENO
    Mate miMate;
    int cateA, hipot;
    double coseno;
    
    printf("Introduce la longitud del cateto adyacente: ");
    fflush(stdout);
    scanf("%d", &cateA);
    printf("Introduce la longitud de la hipotenusa: ");
    fflush(stdout);
    scanf("%d", &hipot);
    if(miMate.SenX(cateA, hipot, &coseno))
        printf("El coseno de x = %lf", coseno);
    else
        printf("Error, la hipotensa no puede ser cero");    
    
    // Fórmula general
    Mate miMa;
    double a, b, c, x1, x2;
    printf("Dado la ecuación cuadrática de la forma:\n\n"
           " Ax^2 + Bx + C = 0\n\n"
           "Proporciona los valores:\n"
           "A: ");
    fflush(stdout);
    scanf("%lf", &a);
    printf("B: ");
    fflush(stdout);
    scanf("%lf", &b);
    printf("C: ");
    fflush(stdout);
    scanf("%lf", &c);
    
    if(miMa.FormGeneral(a, b, c, &x1, &x2)){
        if(x1 == x2){
            printf("La única respuesta es:\n x = %.4lf", x1);
        } else {
            printf("Las respuestas son:\n x1 = %.4lf\n x2 = %.4lf",
                   x1, x2);
        }
    } else {
        printf("La ecuación proporcionada no tiene resultados reales.\n");
    }
 
    
    // IMC
    Nutrition miNut;
    float kg, altura, imc;
    printf("Calcular IMC\nProporcione su peso en kilogramos (kg): ");
    fflush(stdout);
    scanf("%f", &kg);
    printf("Proporciones su altura en metros (m) ");
    fflush(stdout);
    scanf("%f", &altura);
    imc = miNut.IMC(kg, altura);
    printf("Su IMC es de: %f, usted tiene ", imc);
    if(imc < 18.5) printf("peso bajo.");
    else if(imc < 24.9) printf("peso normal.");
    else if(imc < 29.9) printf("sobrepeso.");
    else if(imc < 34.99) printf("obesidad");
    else printf("obesidad mórbida");

    
    // Año bisiesto
    Fechas miF;
    int a, fecha;
    
    printf("Bisiesto\nDame una fecha AAAAMMDD: ");
    fflush(stdout);
    scanf("%d", &fecha);
    a =  miF.Anio(fecha);
    if(miF.EsBisiesto(a))
        printf("SI es bisiesto");
    else
        printf("NO es bisiesto");
    
    
    // CHOQUE DE TRENES 
    Fisica miFis; 
    double v1, v2, d, a;
    
    printf("CHOQUE DE TRENES\nProporcione la velocidad 1 (v1): ");
    fflush(stdout);
    scanf("%lf", &v1);
    printf("Proporcione la velocidad 2 (v2): ");
    fflush(stdout);
    scanf("%lf", &v2);
    printf("Proporcione distancia (d): ");
    fflush(stdout);
    scanf("%lf", &d);
    printf("Proporcione la desaceleración (a): ");
    fflush(stdout);
    scanf("%lf", &a);
    
    if(miFis.ChoqueTrenes(v1, v2, d, a))
        printf("LOS TRENES CHOCARON");
    else 
        printf("LOS TRENES NO CHOCARON");
    printf("\n");
    
    
    
    // ORDEN ALFABÉTICO
    char c1, c2, enter;
    Chars miCh;
    printf("Dame un caracter: ");
    fflush(stdout);
    scanf("%c", &c1);
    printf("Dame otro caracter: ");
    fflush(stdout);
    scanf("%c%c", &enter, &c2);
    
    if(miCh.OrdenAlfa(c1, c2))
        printf("Están en orden alfabético");
    else
        printf("No están en orden alfabético");
    
    
    // MAYOR Y MENOR DE 5
    Mate miM;
    int num1, num2, num3, num4, num5;
    int mayor, menor;
    
    printf("Escribe 5 números separados por un espacio: ");
    fflush(stdout);
    scanf("%d%d%d%d%d", &num1, &num2, &num3, &num4, &num5);
    miM.Mayor_Menor5(num1, num2, num3, num4, num5, &mayor, &menor);

    printf("El mayor es: %d\nEl menor es: %d", mayor, menor);   
    
    
    // Caracter entre I y M
    Chars miCh;
    char c1, enter;
    printf("Dame un caracter: ");
    fflush(stdout);
    scanf("%c%c", &c1, &enter); // En este caso no es necesario capturar enter
    if(miCh.Entre_I_M(c1))
        printf("SÍ esta entre I y M");
    else 
        printf("NO esta entre I y M");
    
    
    // Promedio calificaciones
    int numAlumnos, reprobados = 0, aprobados = 0;
    float promedio;
    Escuela miSchool;
    
        printf("Introduza el número de alumnos: ");
        fflush(stdout);
        scanf("%d", &numAlumnos);
      
        miSchool.ResultadosCurso(numAlumnos, &aprobados, &reprobados, &promedio);
        printf("No. Alumnos:\t%d\n"
               "Aprobados:\t%d\n"
               "Reprobados:\t%d\n"
               "Promedio:\t%f\n", numAlumnos, aprobados, reprobados, promedio);
        
    // For para cuando sabes n de iteraciones
    // While para cuando no se sabe n de iteraciones
    // Do-While para cuando se necesite al menos una iteración
        
    int numDatos, suma, menor, mayor;
    double promedio;
    
    printf("Proporcione el número de valores a evaluar: ");
    fflush(stdout);
    scanf("%d", &numDatos);
    
    Mate miMath;
    miMath.EstadisticosCiclo(numDatos, &mayor, &menor, &suma, &promedio);

    printf("\nNúmero de datos:\t%d\n"
           "Mayor:\t%d\n"
           "Menor:\t%d\n"
           "Suma:\t%d\n" 
           "Promedio:\t%f\n", numDatos, mayor, menor, suma, promedio);
    
    
    // Números impares
    int n_impares, suma;
    Mate myMath;
    
    printf("Escribe n cantidad de los primeros números impares: ");
    fflush(stdout);
    scanf("%d", &n_impares);
    
    myMath.SumaNImpares(n_impares, &suma);
    
    printf("La suma total es: %d\n", suma);
    
    
    // Números pares entre 100 y 200
    int num;
    Mate Math;
    
    printf("Escribe un número par comprendido entre 100 y 200: ");
    fflush(stdout);
    scanf("%d", &num);
    
    if(!(Math.ParesRango(num)))
        printf("El número proporcionado no está comprendido"
               "entre 100 y 200 o no es un número par.");
    
    // Caracter aleatorio
    Chars miChar;
    miChar.AdivinaCarcter();
    
    // Factores
    int number;
    Mate myMath;
    printf("Dame un número a calcular sus factores: ");
    fflush(stdout);
    scanf("%d", &number);
    myMath.Factores(number);
    
    // Adivina mi número
    Mate myMath;
    int num1, num2;
    do{
        printf("Jugador 1:\nEscribe un número entre 1 y 100: ");
        fflush(stdout);
        scanf("%d", &num1);
    }while(num1 > 100 || num1 < 1);
    
    system("cls");
    do{
        printf("Jugador 2:\nEscribe un número entre 1 y 100: ");
        fflush(stdout);
        scanf("%d", &num2);
    }while(num2 > 100 || num2 < 1);
    
    system("cls");
    myMath.AdivinaMiNum(num1, num2);
    
    
    // Inversor de números
    Mate myMath;
    int num, invert;
    
    printf("Escribe un número para invertirlo: ");
    fflush(stdout);
    scanf("%d", &num);
    
    invert = myMath.Invertido(num);
    printf("%d", invert);
    
    // Serie 100
    Mate myMath;
    double suma;
    suma = myMath.Serie100();
    printf("El resultado de la serie es: %lf", suma);
    
    // Calcular pi
    Mate myM;
    double pi = myM.SeriePi();
    printf("Pi es aproximadamente: %lf", pi);    
    
    Mate myM;
    double promedio = myM.PromedioHasta0();
    printf("El promedio es: %lf", promedio);
    
    // Boliche
    Games myGame;
    int puntos = myGame.Boliche();
    printf("El total de puntos fue %d", puntos);
    */
    
    // Divisible entre 9
    Mate Math;
    int numb;
    printf("Escribe un número para saber si es divisble entre 9: ");
    fflush(stdout);
    scanf("%d", &numb);
    if(Math.Divisible9(numb)) 
        printf("%d SÍ es divisible entre 9", numb);
    else
        printf("%d NO es divisible entre 9", numb);
        
    return 0;
     
}


