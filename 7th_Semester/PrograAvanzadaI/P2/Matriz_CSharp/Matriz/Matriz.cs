// Matriz.cs



//namespace Matriz;

public class Matriz
{
    
    //public const int MAX = 10;
    private double[,] contenido = new double[10, 10];
    
    private int rows;
    private int cols;

    public Matriz(int rows = 0, int cols = 0){
        setSize(rows, cols);
    
        //  Marca todas las casillas como 0 (valor por defecto)
    
        for(int r = 0; r < rows; ++r) {
            for(int c = 0; c < cols; ++c) {
            contenido[r, c] = 0;
            }
        }
    }
    //public ~Matriz(){}

    public Matriz sumar(Matriz matriz){
            // La matriz resultante sería del mismo tamaño
    Matriz resultM = new Matriz(rows, cols);

    if(isSumable(matriz)){

        // Si es sumable, suma
        for(int r = 0; r < rows; ++r) {
            for(int c = 0; c < cols; ++c) {
                resultM.contenido[r, c] = contenido[r, c] + matriz.contenido[r, c];
            }
        }
      

    } else {
        Console.WriteLine("No es sumable");
    }
    return resultM;
    }
    
    public Matriz restar(Matriz matriz){
        // La matriz resultante sería del mismo tamaño
        Matriz resultM = new Matriz(rows, cols);

        if(isSumable(matriz)){

            // Si es restable, resta
            for(int r = 0; r < rows; ++r) {
                for(int c = 0; c < cols; ++c) {
                    resultM.contenido[r, c] = contenido[r, c] - matriz.contenido[r, c];
                }
            }
        
        } else {
            Console.WriteLine("No es restable");

            // El resultado tiene un tamaño de 0x0 (inválido)
            resultM.setSize(0, 0);
        }
    
        return resultM;
    }
    public Matriz multiplicar(Matriz matriz){
           /*
        La matriz resultante tendrá el número de filas de la primera
        y el número de columnas de la segunda
        */
        Matriz resultM = new Matriz(rows, matriz.cols);

        if(isMultiplicable(matriz)) {

            // Guardará el resultado de la suma de multiplicaciones
            double resul_mult;

            // Si es multiplicable, multiplica
            for(int r = 0; r < rows; ++r) {
                for(int c = 0; c < matriz.cols; ++c) {
                    
                    resul_mult = 0;
                    // Suma el proucto de filas por columa
                    for(int i = 0; i < cols; ++i) {
                        resul_mult += contenido[r, i] * matriz.contenido[i, c];
                    }

                    // Añade resultado a matriz resultante
                    resultM.contenido[r,c] = resul_mult;
                }
            }    

        } else {
            Console.WriteLine("No es multiplicable");
            
            // El resultado tiene un tamaño de 0x0 (inválido)
            resultM.setSize(0, 0);
        }

        return resultM;


    }

    public bool isMultiplicable(Matriz matriz){
        return (cols == matriz.rows);
    }
    public bool isSumable(Matriz matriz){
        return ((rows == matriz.rows) && (cols == matriz.cols) );
    }
    public void imprimir(){
        for(int r = 0; r < rows; ++r){
            for(int c = 0; c < cols; ++c) {
                Console.Write("[" +  contenido[r, c] + "] ");
            }
            Console.WriteLine("");
        }
    }
    public void llenarMatriz(){
        for(int r = 0; r < rows; ++r){
            for(int c = 0; c < cols; ++c) {
                Console.WriteLine("Elemento [" + r + "][" + c + "]: ");
                contenido[r, c] = Convert.ToDouble(Console.ReadLine());
            }
        }
    }

    public void setSize(int rows, int cols){
        this.rows = rows;
        this.cols = cols;

    }
    public int getRows(){
        return this.rows;
    }
    public int getCols(){
        return this.cols;
    }
    
    
}
