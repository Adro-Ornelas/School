#include<iostream>

using namespace std;

int main(){
	char option = 0;
	int valor1 = 0, valor2 = 0, valor3 = 0;
    int mayor = 0, medio = 0, menor = 0;
	
	do{
		cout << "\n"
				"[A]\tMayor-Menor-Medio\n"
				"\t\t if-else\n"
				"[B]\tMayor-Menor-Medio\n"
				"\t\t if-else-if\n"
				"[S]\tSalir" << endl;

				cout << "Selecciona una opcion: ";
				cin >> option;

				switch(option){
					case 'A':
						cout << "Proporciona tres valores: ";
						cin >> valor1 >> valor2 >> valor3;
						
						if(valor1 > valor2){
							mayor = valor1;
							medio = valor2;
						} else {
							mayor = valor2;
							medio = valor1;
						}
						if(valor3 > mayor){
							menor = medio;
							medio = mayor;
							mayor = valor3;
						}
						if(valor3 <= mayor){
							if(valor3 > medio){
									menor = medio;
									medio = valor3;
								} else {
									menor = valor3;
								}
						}
						
						cout << "Mayor: " << mayor
							 << "\tMedio: " << medio
							 << "\tMenor: " << menor << endl;

						break;

					case 'B':
						cout << "Proporciona tres valores: ";
						cin >> valor1 >> valor2 >> valor3;
						
						if(valor1 >= valor2 && valor1 >= valor3){
							mayor = valor1;
							if(valor2 > valor3){
								medio = valor2;
								menor = valor3;	
							} else {
								medio = valor3;
								menor = valor2;
							}
							
						} else if(valor2 >= valor1 && valor2 >= valor3){
							mayor = valor2;
							if(valor1 > valor3){
								medio = valor1;
								menor = valor3;
							} else {
								medio = valor3;
								menor = valor1;
							}
						
						} else {
							mayor = valor3;
							if(valor1 > valor2){
								medio = valor1;
								menor = valor2;
							} else {
								medio = valor2;
								menor = valor1;
							}
						
						}

						cout << "Mayor: " << mayor
							 << "\tMedio: " << medio
							 << "\tMenor: " << menor << endl;
				
						break;

				}
			cout << endl;
	}while(option != 'S');
	
	return 0;
}

