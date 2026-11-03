#include <iostream>
#include <iomanip>
using namespace std;
 
int main() {

    int n, i, aprobados, desaprobados;
    double notas[30], suma, mayor, menor;
 
    aprobados = 0;
    desaprobados = 0;
    suma = 0;
 
    do {
        cout << "Ingrese el numero de estudiantes (1-30): ";
        cin >> n;
    } while (n < 1 || n > 30);
 
    for (i = 0; i < n; i++) {
        do {
            cout << "Nota del estudiante " << i + 1 << " (0-20): ";
            cin >> notas[i];
        } while (notas[i] < 0 || notas[i] > 20);
    }
 
    mayor = notas[0];
    menor = notas[0];
 
    for (i = 0; i < n; i++) {
        suma = suma + notas[i];
        if (notas[i] > mayor) {
            mayor = notas[i];
        }
        if (notas[i] < menor) {
            menor = notas[i];
        }
        if (notas[i] >= 10.5) {
            aprobados++;
        } else {
            desaprobados++;
        }
    }
 
    cout << fixed << setprecision(2);
    cout << "Promedio general : " << suma/n << endl;
    cout << "Nota mas alta    : " << mayor << endl;
    cout << "Nota mas baja    : " << menor << endl;
    cout << "Aprobados        : " << aprobados << endl;
    cout << "Desaprobados     : " << desaprobados << endl;
 
    return 0; 
}

