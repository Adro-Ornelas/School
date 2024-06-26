/* 
 * File:   main.cpp
 * Author: Adro Ornelas
 *
 * Created on 9 de febrero de 2024, 03:02 PM
 */
#include <iostream>
#include "Punto.h"
#include "Circulo.h"
#include "Cilindro.h"
#include "CilindroHueco.h"
#include "Esfera.h"
#include "Fecha.h"
#include "Persona.h"
#include "Profesor.h"
#include "Curso.h"
#include "Rectangulo.h"
#include "Ortoedro.h"
#include "Pila.h"
#include "Queue.h"
#include "Vector.h"
#include "PilaDoble.h"
#include "Tiburon.h"
#include "Rana.h"
#include "Musgos.h"
#include "Rosales.h"
#include "Serpiente.h"
#include "Serpiente.h"
#include "TarjetaDeCredito.h"
#include "Rodado.h"
#include "GestorContable.h"
#include "Terreno.h"
#include "Muebles.h"
#include "GestorPoligonos.h"
#include "Poligono.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Hexagon.h"
#include "Rombo.h"
#include "Escaleno.h"

#include "Departamento.h"

using namespace std;

int main(int argc, char** argv) {
    
    /* PUNTO
    Punto p1(0, 0), p2(1, 1);
    cout << "P1: ";
    p1.print();
    cout << "\nP2: ";
    p2.print();
    cout << "\nLa distancia que los separa es de " << p1.distancia(p2)
         << endl;
    
     * CIRCULO
    Circulo circ(3, 3, 5);
    circ.Print();
    cout << "\nÁrea: " << circ.Area() << endl
         << "Perímetro: " << circ.Perimetro() << endl;
   
    Esfera miEsfera(3, 3, 5);
    cout << "El área es: " << miEsfera.area() << endl;
    cout << "El volumen es: " << miEsfera.volumen() << endl;
    
    * FECHA Y PERSONA
    Persona miF(14042007, "Adro Yael Ornelas Ornelas", "Juan Álvarez 143 Z", 3334879175, 'M');
    miF.print();  
    Persona miFrau(1012000, "Ariadna Castro", "Juan Alacachofa", 333232375, 'F');
    miFrau.print();
     
    
    // CLASE CURSO Y PROFESOR
    Curso poo1("Sergio Ellerbrakcke", 22300939, 2015, "Programación O.O.",
               "2024-A", 5623123);
    poo1.print();
    
    
    // Rectangulo rect1(3, 5);
    // cout << "El area es " << rect1.area();
    Ortoedro miBox1(3, 4, 5);
    cout << "La caja tiene un volumen de " << miBox1.volumen() << 
            "\nY una superficie de " << miBox1.area() << endl;
       
    Pila pila1;
    if(pila1.isEmpty())
        cout << "Esta vacía" << endl;
    if(pila1.cardinalidad() == 0)
        cout << "no tiene elemendtos" << endl;
    
    for(int i = 0 ; i < 5; ++i){
        cout << "Tope = " << pila1.cardinalidad() << endl;
        pila1.insertar(i*4);
    }
    cout << "La pila: " << endl;
    pila1.print();
     * 
    
    Queue kiwiFila;
    cout << "Fila inicial:";
    kiwiFila.print();
    
    if(kiwiFila.isEmpty())
        cout << "Está vacía";
    cout << "Llenando:" << endl;
    int numb1;
    for(int i = 0; i < TAMQUEUE + 2; ++i){
        numb1 = (i+1) * 5;
        cout << "Insernción de " << numb1;
        if(kiwiFila.insetar(numb1))
            cout << " acertada";
        else
            cout  << " errada";
        cout << endl;
    }
    if(kiwiFila.isFull())
        cout << "Está llena";
    cout << "Eliminar toda la fila menos dos: " << endl;
    for(int i = 0; i < TAMQUEUE - 2; ++i){
        if(kiwiFila.eliminar(&numb1))
            cout << " Acertada, elimado el " << numb1;
        else
            cout  << " Errada";
        
        cout << endl;
    }
    kiwiFila.print();
    cout << "Buscar elemento 54: "
         << ((kiwiFila.isThere(54)) ? "si está":"no está") << endl;
    cout << "Buscar elemento 50: "
         << ((kiwiFila.isThere(50)) ? "si está":"no está") << endl;
    cout << "Eliminar de más: " << endl;
    
    for(int i = 0; i < 5; ++i){
        if(kiwiFila.eliminar(&numb1))
            cout << " Acertada, elimado el " << numb1;
        else
            cout  << " Errada";
        
        cout << endl;
        
    }
    kiwiFila.print();
    cout << "Cardinalidad: " << kiwiFila.getFondo() << " "
         << kiwiFila.getFrente() << endl;
    
    
    cout << "Llenar y vaciar:" << endl;
    for(int i = 0; i < TAMQUEUE+1; ++i){
        numb1 = (i+1) * 3;
        cout << "Insernción de " << numb1;
        if(kiwiFila.insetar(numb1))
            cout << " acertada";
        else
            cout  << " errada";
        cout << endl;
    }
    kiwiFila.print();
    kiwiFila.empty();
    kiwiFila.print();
    
    
    Vector v1(0,0, 3, 4);
    Vector v2(0,0, 7, 5);
    // Vector v3 = v1.suma2Vectores(v2);
    Vector v3 = v1 + v2;
    
    cout << "Vector 1 con:" << endl;
    v1.print();
    cout << endl << "Vector 2 con " << endl;
    v2.print();
    cout << endl << "Vector resultante con " << endl;
    v3.print();
    
    */
    
    Departamento depaRecursosH("Marco Antonio Solís", 22300918,2007, 
                               "Recursos musicales", 185);
    depaRecursosH.despliega();
    
    /* 
    // PILA DOBLE
    PilaDoble dobleP;
    int numb;
    
    cout << "N de elementos iniciales: ";
    dobleP.cardinalidad(1);
    dobleP.cardinalidad(2);
    cout << "\nLlenar del 1 al 5 y del 5 al 1: " << endl;
    for(int i = 1; i <= 6; ++i){
        if (dobleP.insertar(i, 1))
            cout << i << " insertado en p1 " << endl;
        else 
            cout << i << " NO insertado en p1 " << endl;
        if (dobleP.insertar(i, 2))
            cout << i << " insertado en p2 " << endl;
        else 
            cout << i << " NO insertado en p2 " << endl;
    }
    cout << "Pila superior: ";
    dobleP.print(1);
    cout << "\nPila inferior: ";
    dobleP.print(1);
    cout << "Verificar que está llena: "<< endl;
    if(dobleP.isFull())
        cout << "Llena";
    else 
        cout << "No lena";
    cout << "Elimina dos elementos y verifica si está llena: "<< endl;
    dobleP.eliminar(&numb, 1);
    cout << numb << " eliminado" << endl;
    dobleP.eliminar(&numb, 2);
    cout << numb << " eliminado" << endl;
    if(dobleP.isFull())
        cout << "Llena";
    else 
        cout << "No llena";
    cout << endl;
    
    cout << "\nPila superior contiene " << dobleP.cardinalidad(1)
         << " elementos" << endl << "\nPila inferior contiene "
         << dobleP.cardinalidad(2) << " elementos" << endl;
    
    cout << "Pila superior: ";
    dobleP.print(1);
    cout << "\nPila inferior: ";
    dobleP.print(1);
    cout << "Buscar elementos: " << endl;
    
    cout << "El número 87 " << (dobleP.isThere(87, 1) ? "sí":"no")
         << " está en la pila superior;" << endl
         << "El número 2 " << (dobleP.isThere(2, 1) ? "sí":"no")
         << " está en la pila superior;" << endl
         << "El número 3 " << (dobleP.isThere(3, 2) ? "sí":"no")
         << " está en la pila inferior;" << endl
         << "El número 22 " << (dobleP.isThere(22, 2) ? "sí":"no")
         << " está en la pila inferior;" << endl;
            
    cout << endl << "Vacía fila 1 y verifica: " << endl;
    for(int i = 0; i < 5; ++i){
        if (dobleP.eliminar(&numb, 1))
            cout << numb << " eliminado en p1 " << endl;
        else 
            cout << "NO eliminado en p1 " << endl;
        if (dobleP.eliminar(&numb, 2))
            cout << numb << " eliminado en p2 " << endl;
        else 
            cout << "NO eliminado en p2 " << endl;
    }
    cout << "Pila superior" << (dobleP.isEmpty(1) ? "Vacia":"NO vacía")
         << endl 
         << "Pila inferior" << (dobleP.isEmpty(2) ? "Vacia":"NO vacía");;
            
    cout << "\nPila superior contiene " << dobleP.cardinalidad(1)
         << " elementos" << endl << "\nPila inferior contiene "
         << dobleP.cardinalidad(2) << " elementos" << endl;
    
    double x = 0,
           y = 0,
           rad = 10,
           altura = 12,
           radio_in = 5;
    
    CilindroHueco RolloDePapel(x, y, rad, altura, radio_in);
    RolloDePapel.area();
    
    RolloDePapel.print();
    cout << "\nÁrea: " << RolloDePapel.area();
    cout << "\nVolumen: " << RolloDePapel.volumen();
    
     *Tiburon  
    Tiburon tshark("Charchadon charcharias", "gran blanco",
            15042007, 11111111, 50, true, 4, false, 0, "sexual",
            "carnívoro");
    tshark.print();
    
    Rana croacR("Pelophylax perezi", "Rana verde", 5042001, 11111111,
            6, true, 5, 1.5, "sexual", "inscectívoro y carnívoro");
    croacR.print();
    
       
    Musgos verdecito("Bryophyta sensu stricto", "Musgo", false, false,
                     "rocoso", "asexual", "fotosíntesis");
    verdecito.print();
    cout << endl << endl;
    Rosales rosita1("Hibiscus rosa-sinensis", "Rosa de China", true, true,
                    2, "sexual", "fotosíntesis", "primavera");
    rosita1.print();
    
    Serpiente Cobra("Ophiophagus hannah", "cobra real",
            14042007, 11111111, 20, true, true, 2, "sexual", "carnívora");
    Cobra.print();
        
    TarjetaDeCredito tdc(false, 20000, 15, 120, 5000, 0);
    tdc.print();
    
    
    
    Rodado MazdaMX5(500000, 160000);
    MazdaMX5.amortizar();
    MazdaMX5.print();
    
    GestorContable gb = GestorContable();
    
    Bien *unBienRodado = new Rodado(30000, 1000);
    cout << "El rodado: ";
    gb.imprimeBien(unBienRodado);
    cout << endl;
    Bien *unTerreno = new Terreno(8400);
    cout << "El terreno: ";
    gb.imprimeBien(unTerreno);
    cout << endl;
      
    Bien *DasSofa = new Muebles(48000, 2020, 2024);
    
    cout << "Das Sofa: ";
    gb.imprimeBien(DasSofa);
    cout << endl;
    
    
    GestorPoligonos geMaster = GestorPoligonos();   
    
    Poligono *TrianguloUnitario = new Triangle(1);
    geMaster.imprimirPol(TrianguloUnitario);
    
    Poligono *CuadradoUnitario = new Rectangle(1);
    geMaster.imprimirPol(CuadradoUnitario);
    
    Poligono *HexagonoUnitario = new Hexagon(1);
    geMaster.imprimirPol(HexagonoUnitario);
    
    Poligono *Diamond = new Rombo(3, 9); 
    geMaster.imprimirPol(Diamond);
    
    Poligono *TrianguloEscaleno = new Escaleno(12, 13, 15);
    geMaster.imprimirPol(TrianguloEscaleno);
    */
    return 0;
}









