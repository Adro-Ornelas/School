#include <iostream>
#include <windows.h>

using namespace std;

void gotoXY(int x, int y) {
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);    
}
int main() {
	char option = 0;
	int i = 0, j = 0;

	do {
		system("cls");
		cout << "\n"
			"[A]\tFilas\n"
			"[B]\tSnake\n"
			"[S]\tSalir" << endl;

		cout << "Selecciona una opcion: ";
		cin >> option;
		option = toupper(option);

		switch (option) {
		case 'A':
			system("cls");

			for (i = 0; i < 20; ++i) {
				for (j = 0; j < 75; ++j) {
					gotoXY(j, i);
					cout << 'O';
					Sleep(10);
					gotoXY(j, i);
					cout << ' ';
				}
			}
			cout << endl;
			system("pause");

			break;

		case 'B':
			system("cls");
			for(i = 0; i < 20; ++i){
				for (j = 0; j <= 75; ++j) {
					gotoXY(j, i);
					cout << 'O';
					Sleep(10);
					gotoXY(j, i);
					cout << ' ';
				}
				++i;
				for (j = 75; j >= 0; --j) {
					gotoXY(j, i);
					cout << 'O';
					Sleep(10);
					gotoXY(j, i);
					cout << ' ';
				}
			}
			cout << endl;
			system("pause");
			break;

		case 'S':
			break;
		default:
			cout << "Opcion Invalida" << endl;
			system("pause");
			break;
		}
	} while (option != 'S');

	return 0;
}