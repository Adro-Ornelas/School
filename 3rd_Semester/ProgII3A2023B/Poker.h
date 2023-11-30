#ifndef POKER_H
#define POKER_H

#define BARAJAS 1
#define MANO_TAM 5 
#define JUGADORES 4

class Poker {
public:
    Poker();
    void Barajar();     // 0 - 51
    bool EsCorrida(int jugador, int* cartaMenor, int* cartaMayor);
    bool EsFlorImperial(int jugador, int* valor);
    bool EsPar(int jugador, int* valor);    // Par 
    bool EsFlor(int jugador, int* color);    
    bool EsQuintilla(int jugador, int* valor);
    bool EvaluaManos(); //Quien ganó
    void PrintMazo();
  
    void DespliegaCarta(int carta);
    void DespliegaMano(int jugador);
    void DespliegaManosss();
    void DespliegaPalo(int carta);
    void DespliegaValor(int carta);
    void NuevaMano(int jugador);
    void RepartoInicial();
    int  Palo(int carta);
    void PruebaMano();
    int  Valor(int carta);
    int  ValorMano(int jugador, int* valor, int* cartaMenor, int* cartaMayor,
                   int* valorTercia, int* valorPar,
                   int* color, int* valorMenor);
    
private:
    int mazo[BARAJAS * 52];
    int indiceMazo;
    int mano[JUGADORES][MANO_TAM];
    int vmano[JUGADORES];
};

#endif /* POKER_H */

