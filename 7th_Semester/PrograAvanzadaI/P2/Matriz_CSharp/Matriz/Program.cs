// See https://aka.ms/new-console-template for more information

using System;

namespace HelloWorld {

	class Program {

		static void Main(string[] args) {
			
			int rows, cols;
			char oper;

			Console.Write("Tamaño de matriz 1 (filas columnas):");
			rows = Convert.ToInt32(Console.ReadLine());
			cols = Convert.ToInt32(Console.ReadLine());
			Matriz m1 = new Matriz(rows, cols);
			m1.llenarMatriz();

			Console.Write("Operación (+, -, *): ");
			oper = Convert.ToChar(Console.ReadLine());


			Console.Write("Tamaño de matriz 2 (filas columnas):");
			rows = Convert.ToInt32(Console.ReadLine());
			cols = Convert.ToInt32(Console.ReadLine());

			Matriz m2 = new Matriz(rows, cols);
			m2.llenarMatriz();

			// Inicializa matriz de resultado con tamaño de matriz2
			Matriz m3 = new Matriz();


			switch (oper) {
			case '*':
				m3 = m1.multiplicar(m2);
				break;

			case '+':
				m3 = m1.sumar(m2);
				break;

			case '-':
				m3 = m1.restar(m2);
				break;

			default:

				Console.Write("Operación no admitida");
            	break;

            }


			// Si fue un resultado váido, imprime
			if(m3.getRows() > 0) {
				Console.WriteLine("");
				m1.imprimir();
				Console.WriteLine("\n"+oper+"\n");
				m2.imprimir();
				Console.WriteLine("\n=\n");
				m3.imprimir();

			}
		}
	}
}

