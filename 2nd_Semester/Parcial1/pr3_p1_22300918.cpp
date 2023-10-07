#include<iostream>
#include<iomanip>
using namespace std;
int main(){

    int option=0, n=0, i=0, j=0;
    double r=0;

    do{
    cout << "\n"
            "[1]\tSerie\n"
            "[2]\tTablas de multiplicar\n"
            "[3]\tSalir\n" << endl;
    cout << "Selecciona una opcion: ";
    cin >> option;

     cout << endl;
        switch(option){
            case 1:
                cout << "\tSerie\n"
                        "Proporciona el tope de la serie: ";
                        cin >> n;
                        cout << endl;
                        r=0;
                        if(n >= 2){
                            r = 1.0 / 2;
                            cout << "         1 / 2   =  " << r << endl;
                        }
                        for(i = 4, j=2; i <= n; i+=2, ++j){
                            cout << left
                                 << setw(5) << r << " + "
                                 << right
                                 << setw(2) << j << " / "
                                 << left << setw(3) << i << " =  ";
                            r += static_cast<double>(j) / i;
                            cout << r << endl;
                        }
                        cout << "Resultado final: " << r << endl;

                break;
            case 2: 
                cout << "\t\tTablas de multiplicar\n"
                     << " Tabla del 5\t\t Tabla del 3\t\t Tabla del 1" << endl;
                for(i = 10; i >= 1; i-=2){
                    for(j = 5; j >= 1; j-=2){
                        r = j*i;
                        cout << right
                             << setw(2) << j << " * "
                             << left 
                             << setw(2) << i << " = " << r << "\t\t";
                    }
                    cout << endl;
                }
                break;
            case 3:
                break;
            default:
                cout << "Opción Inválida" << endl;
        }
    } while(option != 3);

    return 0;
}