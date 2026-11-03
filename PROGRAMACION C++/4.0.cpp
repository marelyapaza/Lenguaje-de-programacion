#include <iostream>
using namespace std;

int mostrarTabla(int n);

int main()
{
	cout << "Hello World" << endl;
	int total = calcularSuma(10);
	cout << "La suma total del 1 al 10 es b: " << total << endl;
	
	return 0;
}

int calcularSuma (int n) {
	int suma = 0;
	for (int i=1; i<=n;i++) {
		cout << i<< endl; 
	    suma +=i;
	    }
	return suma;
}
