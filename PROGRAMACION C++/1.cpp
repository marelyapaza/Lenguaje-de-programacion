#include <iostream>
#include <iomanip>
using namespace std;
 
int main()
{
    double sueldo, bono, sueldoNeto;
    int anios, porcentaje;
 
    cout << "Ingrese el sueldo base (S/): ";
    cin >> sueldo;
    cout << "Ingrese los anios de antiguedad: ";
    cin >> anios;
 
    if (anios >= 10) {
        porcentaje = 15;
    } else if (anios >= 5) {
        porcentaje = 10;
    } else if (anios >= 1) {
        porcentaje = 5;
    } else {
        porcentaje = 0;
    }
 
    bono = sueldo * porcentaje / 100;
    sueldoNeto = sueldo + bono;
 
    cout << fixed << setprecision(2);
    cout << "Sueldo base : S/ " << sueldo << endl;
    cout << "Bono (" << porcentaje << "%)    : S/ " << bono << endl;
    cout << "Sueldo neto : S/ " << sueldoNeto << endl;
 
    return 0;
}

