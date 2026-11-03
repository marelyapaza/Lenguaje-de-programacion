#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
 
int main() {
    
    int i, j;
    double ventas[4][7];
    double totalVendedor, totalDia, totalSemana;
    string dias[7] = {"Lunes", "Martes", "Miercoles", "Jueves",
                      "Viernes", "Sabado", "Domingo"};
    totalSemana = 0;
 
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 7; j++) {
            do {
                cout << "Vendedor " << i + 1 << " - " << dias[j] << " (S/): ";
                cin >> ventas[i][j];
                if (ventas[i][j] < 0) {
                    cout << "El monto no puede ser negativo." << endl;
                }
            } while (ventas[i][j] < 0);
        }
    }
 
    cout << fixed << setprecision(2);
 
    cout << endl << "--- Total por vendedor ---" << endl;
    for (i = 0; i < 4; i++) {
        totalVendedor = 0;
        for (j = 0; j < 7; j++) {
            totalVendedor = totalVendedor + ventas[i][j];
        }
        cout << "Vendedor " << i + 1 << ": S/ " << totalVendedor << endl;
        totalSemana = totalSemana + totalVendedor;
    }
 
    cout << endl << "--- Total por dia ---" << endl;
    for (j = 0; j < 7; j++) {
        totalDia = 0;
        for (i = 0; i < 4; i++) {
            totalDia = totalDia + ventas[i][j];
        }
        cout << dias[j] << ": S/ " << totalDia << endl;
    }
 
    cout << endl << "Total acumulado de la semana: S/ " << totalSemana << endl;
 
    return 0;
}

