// pr5_p2_22300918
#include <iostream>
using namespace std;
int main() {
	char option = 0, letra = 0;
	int i = 0, conso = 0;
	char word[40];

	do {
		cout << "[1] Consonantes\n"
			 << "[2] Simbolos especiales\n"
			 << "[S] Salir\n"
			 << "Selecciona una opcion: ";
		cin >> option;
		fflush(stdin);

		option = toupper(option);

		switch (option) {
		case '1':
			cout << "Limite: 40 caracteres\nIntroduce una cadena: ";
			gets_s(word, 40);
			gets_s(word, 40);
			fflush(stdin);

			conso = 0;
			for (i = 0; word[i] != '\x0'; ++i) {		// Recorre la cadena

				if (word[i] >= 66 && word[i] <= 90) {	// Revisa mayúsuculas ASCII 66-90, B-Z

					if (word[i] != 69 && word[i] != 73 &&
						word[i] != 79 && word[i] != 85) { // Verifica que no sea E, I, O U
						++conso;
					}
				}
				else if (word[i] >= 98 && word[i] <= 122) { // Revisa minúsuculas ASCII 98-122, b-Z

					if (word[i] != 101 && word[i] != 105 &&
						word[i] != 111 && word[i] != 117) { // Verifica que no sea e, i, o u
						++conso;
					}
				}
			}
			cout << "\nLa cadena \'" << word << "\' tiene " << conso << " consonantes." << endl;
			break;

		case '2':
			cout << "Limite: 40 caracteres\nIntroduce una cadena: ";
			gets_s(word, 40);
			gets_s(word, 40);
			fflush(stdin);

			conso = 0;
			for (i = 0; word[i] != '\x0'; ++i) {

				if( word[i] >= 33 && word[i] <= 47 ||
				    word[i] >= 58 && word[i] <= 64 ||
				    word[i] >= 91 && word[i] <= 96 ||
				    word[i] >= 123 && word[i] <= 126 ||
					word[i] == 168){
				   
					word[i] = '#';
					++conso;
				}
				
			}

			cout << "\nResultado de la cadena: " << word << "\ntiene " << conso << " caracteres especiales." << endl;

			break;

		case 'S':
			break;
		}

		cout << endl;
	} while (option != 'S');

	return 0;
}