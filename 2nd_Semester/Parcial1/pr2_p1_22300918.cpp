#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
	bool primo=false;
	char option = 0;
	int n=0, valor1=0, suma=0;
	long int factorial = 1;
	do {
		cout << "\n"
			"[A]\tSerie\n"
			"[B]\tFactorial\n"
			"[S]\tSalir" << endl;
		cout << "Selecciona una opcion: ";
		cin >> option;
		option = toupper(option);

		switch (option) {


		case 'A':
			cout << "Introduce el numero de valores a evaluar: ";
			cin >> n;

			suma = 0;

			while (n > 0) {
				cout << "Introduce un valor: ";
				cin >> valor1;

				int i = 2;
				primo = true;

				while (i < valor1) {
					if (valor1 % i == 0) {
						primo = false;
						break;
					}
					++i;
				}

				if (valor1 <= 1) primo = false;
				if (primo == true) suma += valor1;

				--n;
			}
			cout << "\nLos numeros primos sumados: " << suma << endl;
			break;

		case 'B':
			cout << "Escribe un numero a calcular su factorial: ";
			cin >> n;
			factorial = 1;
			cout << endl;
			for (int i = n; i > 1; i--) {
				factorial *= i;
				cout << setw(18) << right << factorial << " * " << setw(3) << i - 1 << " = " << factorial * (i - 1) << endl;
			}
			cout << setw(18) << n << "! = " << factorial << endl;
			break;

		case 'S':
			break;

			default:
				cout << "Opcion Invalida" << endl;

		}


	} while (option != 'S');
	return 0;
}
