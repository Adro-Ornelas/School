// pr3_p2_22300918
#include <iostream>
using namespace std;
int main() {

	int option = 0;
	int day = 0, month = 0, year = 0;
	int today = 0, tomonth = 0, toyear = 0;
	int day_month=0;

	do {
		cout << "[1] Signo zodiacal con validaci" <<char(162)<< "n\n"
			 <<	"[2] Edad en a" <<char(164)<< "os, meses y d" <<char(161)<< "as\n"
			 <<	"[3] Salir\n"
			 <<	"Selecciona una opci" <<char(162)<< "n: ";
		cin >> option;

		switch (option) {
			case 1:

				// Validación de mes
				do{
					cout << "Introduce tu mes de nacimiento (1-12): ";
					cin >> month;
					if(month < 1 || month > 12){
						cout << "Mes inv"<<char(160)<<"lido" << endl;
					}
				} while(month < 1 || month > 12);


				// Los meses 4, 6, 9 y 11 son de 30 días

				if(4 == month || 6 == month || 9 == month || 11 == month){
					day_month = 30;
				} else if(2 == month){
					day_month = 28;
				} else {			
					day_month = 31;
				}

				// Validación de días		
				do{
					cout << "Introduce tu d" << char(161) << "a de nacimiento: ";
					cin >> day;
					if(day < 1 || day > day_month){
						cout << "D"<<char(161)<<"a inv"<<char(160)<<"lido" << endl;
					}
				} while(day < 1 || day > day_month);


				cout << endl;
				cout << "Tu signo zodiacal es: ";

				if (month == 1) {

					if (day <= 20) {
						cout << "Capricornio";
					} else {
						cout << "Acuario";
					}
				}
				else if (month == 2) {

					if (day <= 19 ) {
						cout << "Acuario";
					} else {
						cout << "Piscis";
					}
				}
				else if (month == 3) {

					if (day <= 20 ) {
						cout << "Piscis";
					} else {
						cout << "Aries";
					}
				}
				else if (month == 4) {

					if (day <= 20 ) {
						cout << "Aries";
					} else {
						cout << "Tauro";
					}
				}
				else if (month == 5) {

					if (day <= 20 ) {
						cout << "Tauro";
					} else {
						cout << "G" << char(130) << "minis";
					}
				}
				else if (month == 6) {

					if (day <= 21 ) {
						cout << "G" << char(130) << "minis";
					} else{
						cout << "C" << char(160) << "ncer";
					}
				}
				else if (month == 7) {

					if (day <= 22 ) {
						cout << "C" << char(160) << "ncer";
					} else{
						cout << "Leo";
					}
				}
				else if (month == 8) {

					if (day <= 23 ) {
						cout << "Leo";
					} else{
						cout << "Virgo";
					}
				}
				else if (month == 9) {

					if (day <= 22 ) {
						cout << "Virgo";
					} else{
						cout << "Libra";
					}
				}
				else if (month == 10) {

					if (day <= 22 ) {
						cout << "Libra";
					} else{
						cout << "Escorpio";
					}
				}
				else if (month == 11) {

					if (day <= 22 ) {
						cout << "Escorpio";
					} else{
						cout << "Sagitario";
					}
				}
				else if (month == 12) {

					if (day <= 21 ) {
						cout << "Sagitario";
					} else{
						cout << "Capricornio";
					}
				}
				cout << endl << endl;

				break;

			case 2:
				// Validación de año actual
				do {
					cout << "Introduce el a" << char(164) << "o actual: ";
					cin >> toyear;

					if (toyear < 0){
						cout << "A" << char(164) << "o inv" << char(160) << "lido" << endl;
					}
				} while (toyear < 0);

				// Validación de mes actual
				do {
					cout << "Introduce el mes actual: ";
					cin >> tomonth;
					if (tomonth < 1 || tomonth > 12){
						cout << "Mes inv"<<char(160)<<"lido" << endl;
					}
				} while (tomonth < 1 || tomonth > 12);


				// Los meses 4, 6, 9 y 11 son de 30 días
				if(4 == tomonth || 6 == tomonth || 9 == tomonth || 11 == tomonth){
					day_month = 30;
				} else if(2 == month){
					day_month = 28;
				} else {			
					day_month = 31;
				}

				// Validación de día actual			
				do{
					cout << "Introduce el d" << char(161) << "a actual: ";
					cin >> today;

					if(today < 1 || today > day_month){
						cout << "D"<<char(161)<<"a inv"<<char(160)<<"lido" << endl;
					}
				} while(today < 1 || today > day_month);

				// Validación del año de nacimiento
				do {
					cout << "Introduce tu a" << char(164) << "o de nacimiento: ";
					cin >> year;
					if (year < 0 || year > toyear){
						cout << "A" << char(164)<<"o inv" << char(160)<<"lido" << endl;
					}
				} while (year < 0 || year > toyear);

				//	Validación del mes de nacimiento
				if(year != toyear){	// Cuando el año es distinto al actual
					do {
						cout << "Introduce tu mes de nacimiento: ";
						cin >> month;
						if(month < 1 || month > 12)
							cout << "Mes inv"<<char(160)<<"lido" << endl;

					} while (month < 1 || month > 12);


				} else {
					
					do {
						cout << "Introduce tu mes de nacimiento: ";
						cin >> month;
						if(month < 1 || month > 12 || month > tomonth){
							cout << "Mes inv"<<char(160)<<"lido" << endl;
						}
					} while (month < 1 || month > 12 || month > tomonth);
		
				}

				// Los meses 4, 6, 9 y 11 son de 30 días
				if(4 == month || 6 == month || 9 == month || 11 == month){
					day_month = 30;
				} else if(2 == month){
					day_month = 28;
				} else {			
					day_month = 31;
				}
	
				// Validación de días
				if(year == toyear && month == tomonth){
					do{
						cout << "Introduce tu d" << char(161) << "a de nacimiento: ";
						cin >> day;

						if(day < 1 || day > day_month || day > today){
							cout << "D"<<char(161)<<"a inv"<<char(160)<<"lido" << endl;
						}
					} while(day < 1 || day > day_month || day > today);

				} else {
					do{
						cout << "Introduce tu d" << char(161) << "a de nacimiento: ";
						cin >> day;

						if(day < 1 || day > day_month){
							cout << "D"<<char(161)<<"a inv"<<char(160)<<"lido" << endl;
						}
					} while(day < 1 || day > day_month);
				}

				// Calcular años, meses y días:
				today -= day;
				tomonth -= month;
				toyear -= year;

				if(tomonth < 0 || today < 0 && tomonth == 0){
					tomonth += 12;
					--toyear;
				}
				if(today < 0){
					if( 4 == tomonth || 6 == tomonth || 9 == tomonth || 11 == tomonth){
						today += 30;
					}else if(2 == tomonth){
						today += 28;
					}else{
						today += 31;
					}
					--tomonth;
				}

				cout << "\nHas vivido: \n"
					<< toyear << " a"<<char(164)<<"os, "
					<< tomonth << " meses y "
					<< today << " d"<<char(161)<<"as.\n" << endl;
				break;

			case 3:
				break;

			default:
				cout << "Opci" << char(162) << "n inv" << char(160) << "lida" << endl;
		}
		
	} while (option != 3);
}