#include <iostream>
#include <iomanip>
using namespace std;
 
int main() 
{
	double saldo, monto;
    int opcion;
 
    saldo = 2000;
    cout << fixed << setprecision(2);
 
    do {
    	cout << endl;
    	cout << "[1] Consultar saldo" << endl;
    	cout << "[2] Retirar dinero" << endl;
    	cout << "[3] Salir " << endl;
    	cout << "Elejir opcion: ";
    	cin >> opcion ;
    	
    	switch (opcion) {
    		
    		case 1: 
    		 cout << "Su saldo actual es: S/  " << saldo << endl;
    		 break;
    		 
    		case 2:
    		    cout << "Ingrese el monto a retirar: S/ ";
    		    cin >> monto;
    		    if (monto <= 0) {
			        cout << "Error: El monto debe ser mayor a 0 " << endl;
			    } else if (monto > saldo ) {
			    	cout << "Error: Saldo insuficinete " << endl;
			    } else {
			    	saldo = saldo - monto;
			    	cout << "Retiro exitoso: El saldo actual es: S/" << saldo << endl;
			    }
				break;
			default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
            }
    } while (opcion != 3);
        
    return 0;
}
				 
					
			    	
				 
    		 	
    			
    	
