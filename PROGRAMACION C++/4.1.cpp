#include <iostream>
using namespace std;

void control_inventario();

int main() {
    control_inventario();
    return 0;
}

void control_inventario() {
    int n;
    cout << "CONTROL DE INVENTARIO" << endl;
    cout << "Ingrese la cantidad de productos (entre 1 y 20): ";
    cin >> n;
        
    int stock[20]; 
    int total_existencia = 0;
    
    for (int i = 0; i < n; i++) {
        cout << "Ingrese las unidades disponibles para el producto " << (i + 1) << ": ";
        cin >> stock[i];
        total_existencia += stock[i]; 
    }
            
    int max_stock = stock[0];
    int min_stock = stock[0];
    int idx_max = 0; 
    int idx_min = 0; 
    
    for (int i = 0; i < n; i++) {
        if (stock[i] > max_stock) {
            max_stock = stock[i];
            idx_max = i;
        }
        if (stock[i] < min_stock) {
            min_stock = stock[i];
            idx_min = i; 
        }
    }
    
    int limite;
    cout << "\nIngrese el limite minimo de stock (L) para la alerta: ";
    cin >> limite;
    
    int alerta_count = 0;
    for (int i = 0; i < n; i++) {
        if (stock[i] < limite) {
            alerta_count++;
        }
    }
    
    cout << "\n--- REPORTE DE INVENTARIO ---" << endl;
    cout << "Total de productos en existencia: " << total_existencia << endl;
    cout << "Mayor stock: producto " << (idx_max + 1) << " con " << max_stock << " unidades." << endl;
    cout << "Menor stock: producto " << (idx_min + 1) << " con " << min_stock << " unidades." << endl;
    cout << "Productos por debajo del limite: " << alerta_count << endl;
    
    if (alerta_count > 0) {
        cout << "ALERTA! Se requiere reabastecimiento." << endl;
    }
}
