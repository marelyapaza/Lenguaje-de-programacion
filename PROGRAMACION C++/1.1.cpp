#include <iostream>

using namespace std;

void calcular_bonificacion() 
{
    double sueldo_base, antiguedad;
    
    cout << "\n--- PREGUNTA 1: BONIFICACIONES ---" << endl;
    cout << "Ingrese el sueldo base del empleado: ";
    cin >> sueldo_base;
    cout << "Ingrese los anos de antiguedad del empleado: ";
    cin >> antiguedad;
    
    double porcentaje_bono = 0.0;
    
    if (antiguedad >= 10) {
        porcentaje_bono = 0.15;
    } else if (antiguedad >= 5) {
        porcentaje_bono = 0.10;
    } else if (antiguedad >= 1) {
        porcentaje_bono = 0.05;
    } else {
        porcentaje_bono = 0.0;
    }
        
    double monto_bono = sueldo_base * porcentaje_bono;
    double sueldo_neto = sueldo_base + monto_bono;
    
    cout << "\n--- RESUMEN DE PAGO ---" << endl;
    cout << "Sueldo Base: S/ " << sueldo_base << endl;
    cout << "Monto del Bono (" << (int)(porcentaje_bono * 100) << "%): S/ " << monto_bono << endl;
    cout << "Sueldo Neto a Cobrar: S/ " << sueldo_neto << endl;
}

int main() {
   
    calcular_bonificacion();
    return 0;
}

