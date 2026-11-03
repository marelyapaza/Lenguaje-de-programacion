#include <iostream>

using namespace std;
void cajero_automatico() {
    double saldo = 2000.0;
    int opcion = 0;
    
    do {
        cout << "\n--- PREGUNTA 2: CAJERO AUTOMATICO ---" << endl;
        cout << "[1] Consultar saldo" << endl;
        cout << "[2] Retirar dinero" << endl;
        cout << "[3] Regresar al menu principal" << endl;
        cout << "Elija una opcion: ";
        cin >> opcion;
        
        if (opcion == 1) {
            cout << "Su saldo actual es: S/ " << saldo << endl;
        } else if (opcion == 2) {
            double retiro;
            cout << "Ingrese el monto a retirar: S/ ";
            cin >> retiro;
            
            if (retiro <= 0) {
                cout << "Error: El monto a retirar debe ser mayor a 0." << endl;
            } else if (retiro > saldo) {
                cout << "Error: Saldo insuficiente. Su saldo actual es S/ " << saldo << endl;
            } else {
                saldo -= retiro;
                cout << "Retiro exitoso. Ha retirado S/ " << retiro << endl;
                cout << "Su nuevo saldo es: S/ " << saldo << endl;
            }
        } else if (opcion == 3) {
            cout << "Saliendo del cajero..." << endl;
        } else {
            cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 3);
}
int main() {
   
    cajero_automatico();
    return 0;
}

