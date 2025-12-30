// Matriz.h

#define MAX 10

class Matriz {


    private:

    double contenido[MAX][MAX];
    int rows;
    int cols;

    public:

    Matriz(int = 0, int = 0);
    ~Matriz();

    Matriz sumar(Matriz);
    Matriz restar(Matriz);
    Matriz multiplicar(Matriz);
    
    Matriz operator+(Matriz);
    Matriz operator-(Matriz);
    Matriz operator*(Matriz);

    bool isMultiplicable(Matriz);
    bool isSumable(Matriz);     // Also returns if decreseable
    void imprimir(void);
    void llenarMatriz(void);
    void setSize(int, int);
    int getRows();
    int getCols();
    
};