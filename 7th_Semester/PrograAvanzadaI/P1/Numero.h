// Numero.h

/* 
    Un número es una expresión con numerador y denominador
*/

class Numero {

private:

    int numerador;
    int denominador;
    int mcd(int a, int b);

public:

    // Valores predeterminado para el constructor (0/1)
    Numero(int = 0, int = 1);   // Constructor
    ~Numero();                  // Destructor

    Numero  sumar(Numero);      // Este numero mas otro
    Numero  restar(Numero);     // Este numero enos otro
    Numero  dividir(Numero);    // Este numero entre otro
    Numero  multiplicar(Numero);// Este numero por otro
    void    imprimir();         // Imprime número
    void    simplificar();      // Convierte número a su misma expresión
    // Numero operator+(Numero const);
    

};