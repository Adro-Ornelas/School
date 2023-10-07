#include <iostream>
using namespace std;
int main() {

	int option = 0;
	int day = 0, month = 0;

	do {
		cout << "[1] Signo zodiacal\n"
				"[2] Salir\n"
				"Selecciona una opci" << char(162) << "n: ";
		cin >> option;

		switch (option) {
			case 1:
				cout << "Introduce tu d"<< char(161) <<"a de nacimiento: ";
				cin >> day;
				cout << "Introduce tu mes de nacimiento (1-12): ";
				cin >> month;

				cout << endl;
				if(month == 1){

					if(day <= 20 && day >= 1){
						cout << "Tu signo zodiacal es: Capricornio";
					} else if(day >= 21 && day <= 31){
						cout << "Tu signo zodiacal es: Acuario";
					} else {
						cout << "El d"<< char(161) <<"a seleccionado no es v"<<char(160)<<"lido";
					}

				}else if(month == 2){

					if(day <= 19 && day >= 1){
						cout << "Tu signo zodiacal es: Acuario";
					} else if(day >= 20 && day <= 29){
						cout << "Tu signo zodiacal es: Piscis";
					} else {
						cout << "El d"<< char(161) <<"a seleccionado no es v"<<char(160)<<"lido";
					}	

				}else if(month == 3){
					
					if(day <= 20 && day >= 1){
						cout << "Tu signo zodiacal es: Piscis";
					} else if(day >= 21 && day <= 31){
						cout << "Tu signo zodiacal es: Aries";
					} else {
						cout << "El d"<< char(161) <<"a seleccionado no es v"<<char(160)<<"lido";
					}
				
				}else if(month == 4){
					
					if(day <= 20 && day >= 1){
						cout << "Tu signo zodiacal es: Aries";
					} else if(day >= 21 && day <= 30){
						cout << "Tu signo zodiacal es: Tauro";
					} else {
						cout << "El d"<< char(161) <<"a seleccionado no es v"<<char(160)<<"lido";
					}
				
				}else if(month == 5){
					
					if(day <= 20 && day >= 1){
						cout << "Tu signo zodiacal es: Tauro";
					} else if(day >= 21 && day <= 31){
						cout << "Tu signo zodiacal es: G"<<char(130)<<"minis";
					} else {
						cout << "El d"<< char(161) <<"a seleccionado no es v"<<char(160)<<"lido";
					}
				
				}else if(month == 6){
					
					if(day <= 21 && day >= 1){
						cout << "Tu signo zodiacal es: G"<<char(130)<<"minis";
					} else if(day >= 22 && day <= 30){
						cout << "Tu signo zodiacal es: C"<<char(160)<<"ncer";
					} else {
						cout << "El d"<< char(161) <<"a seleccionado no es v"<<char(160)<<"lido";
					}
				
				}else if(month == 7){
					
					if(day <= 22 && day >= 1){
						cout << "Tu signo zodiacal es: C"<<char(160)<<"ncer";
					} else if(day >= 23 && day <= 31){
						cout << "Tu signo zodiacal es: Leo";
					} else {
						cout << "El d"<< char(161) <<"a seleccionado no es v"<<char(160)<<"lido";
					}
				
				}else if(month == 8){
					
					if(day <= 23 && day >= 1){
						cout << "Tu signo zodiacal es: Leo";
					} else if(day >= 24 && day <= 31){
						cout << "Tu signo zodiacal es: Virgo";
					} else {
						cout << "El d"<< char(161) <<"a seleccionado no es v"<<char(160)<<"lido";
					}
				
				}else if(month == 9){
					
					if(day <= 22 && day >= 1){
						cout << "Tu signo zodiacal es: Virgo";
					} else if(day >= 23 && day <= 30){
						cout << "Tu signo zodiacal es: Libra";
					} else {
						cout << "El d"<<char(161)<<"a seleccionado no es v"<<char(160)<<"lido";
					}
				
				}else if(month == 10){
					
					if(day <= 22 && day >= 1){
						cout << "Tu signo zodiacal es: Libra";
					} else if(day >= 23 && day <= 31){
						cout << "Tu signo zodiacal es: Escorpio";
					} else {
						cout << "El d"<< char(161) <<"a seleccionado no es v"<<char(160)<<"lido";
					}
				
				}else if(month == 11){
					
					if(day <= 22 && day >= 1){
						cout << "Tu signo zodiacal es: Escorpio";
					} else if(day >= 23 && day <= 30){
						cout << "Tu signo zodiacal es: Sagitario";
					} else {
						cout << "El d"<< char(161) <<"a seleccionado no es v"<<char(160)<<"lido";
					}
				
				}else if(month == 12){
					
					if(day <= 21 && day >= 1){
						cout << "Tu signo zodiacal es: Sagitario";
					} else if(day >= 22 && day <= 31){
						cout << "Tu signo zodiacal es: Capricornio";
					} else {
						cout << "El d"<< char(161) <<"a seleccionado no es v"<<char(160)<<"lido";
					}
				
				} else {
					cout << "El mes seleccionado no es v"<<char(160)<<"lido";
				}

				cout << endl;
				
			break;
			case 2:
				break;

			default:
				cout << "Opci" << char(162) << "n inv"<<char(160)<<"lida" << endl;

		}
		cout << endl;
	} while (option != 2);
}

