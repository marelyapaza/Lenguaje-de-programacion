#include <iostream>
using namespace std;
 
int main() {
    int n, i, total, posMayor, posMenor, limite, bajoLimite;
    int stock[20];
 
    total = 0;
    posMayor = 0;
    posMenor = 0;
    bajoLimite = 0;
 
    do {
        cout << "Ingrese el numero de productos (1-20): ";
        cin >> n;
    } while (n < 1 || n > 20);
 
    for (i = 0; i < n; i++) {
        do {
            cout << "Unidades del producto " << i << ": ";
            cin >> stock[i];
            if (stock[i] < 0) {
                cout << "La cantidad no puede ser negativa." << endl;
            }
        } while (stock[i] < 0);
    }
 
    for (i = 0; i < n; i++) {
        total = total + stock[i];
        if (stock[i] > stock[posMayor]) {
            posMayor = i;
        }
        if (stock[i] < stock[posMenor]) {
            posMenor = i;
        }
    }
 
    cout << endl << "Total de productos en existencia: " << total << endl;
    cout << "Mayor stock: producto " << posMayor << " con " << stock[posMayor] << " unidades" << endl;
    cout << "Menor stock: producto " << posMenor << " con " << stock[posMenor] << " unidades" << endl;
 
    cout << endl << "Ingrese el limite minimo de stock (L): ";
    cin >> limite;
 
    for (i = 0; i < n; i++) {
        if (stock[i] < limite) {
            bajoLimite++;
        }
    }
 
    cout << "Productos por debajo del limite: " << bajoLimite << endl;
    if (bajoLimite > 0) {
        cout << "Se requiere reabastecimiento." << endl;
    } else {
        cout << "Stock suficiente en todos los productos." << endl;
    }
 
    return 0;
} 

