#include <iostream>
using namespace std;

// Variable global
int n;

// Prototipo de la funcion
void mostrarTabla(int);

int main () {
	cout << "Ingrese un numero (1 a 9): ";
	cin >> n;
	cout << "\n Tabla de multiplicar del " << n << "\n" ;
	mostrarTabla(n);
	return 0;
}

// Funcion que muestra la tabla de multiplicar
void mostrarTabla(int n) {
	int i; // Variable local
	for (i=1; i<=10; i++) {
		cout << n << " x " << i << " : " << n * i << endl;
	}
}
