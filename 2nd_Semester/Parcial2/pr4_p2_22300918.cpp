// pr4_p2_22300918
#include <iostream>
using namespace std;
int main() {

	char option = 0;
	int i = 0, numbers = 0;
	char word[20];

	do {
		cout << "[A] Mayusculas a minusculas\n"
			<< "[B] Numeros\n"
			<< "[S] Salir\n"
			<< "Selecciona una opcion: ";
		cin >> option;
		option = toupper(option);

		switch (option) {
		case 'A':
			cout << "Limite: 20 caracteres\nEscribe una palabra: ";
			cin >> word;
			fflush(stdin);

			i = 0;
			while (word[i] != '\x0') {
				if (word[i] >= 65 && word[i] <= 90) {
					word[i] = word[i] + 32;
				}
				++i;
			}

			cout << "Resultado:\n" << word << endl;

			break;

		case 'B':

			cout << "Limite: 20 caracteres\nIntroduce una cadena: ";
			cin >> word;
			fflush(stdin);

			numbers = 0;
			for (i = 0; word[i] != '\x0'; ++i) {
				if (word[i] >= 48 && word[i] <= 57)
					++numbers;
			}

			cout << "La cadena \'" << word << "\' tiene " << numbers << " numeros";
			break;

		case 'S':
			break;
		default:
			cout << "Opcion invalida" << endl;
		}
		cout << endl;

	} while (option != 'S');
}
