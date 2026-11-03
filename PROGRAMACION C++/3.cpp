#include <iostream>
using namespace std;

// Prototipos de las funciones modulares
void sumar(int a, int b);
void restar(int a, int b);
void multiplicar(int a, int b);
void dividir(int a, int b);

int main() {
    int a, b;

    cout << "Ingrese el valor de a: ";
    cin >> a;
    cout << "Ingrese el valor de b: ";
    cin >> b;

    cout << "\n--- RESULTADOS ---" << endl;
    
    // Llamada a cada módulo (función)
    sumar(a, b);
    restar(a, b);
    multiplicar(a, b);
    dividir(a, b);

    return 0;
}

// Módulo de suma
void sumar(int a, int b) {
    cout << "Suma: " << a + b << endl;
}

// Módulo de resta
void restar(int a, int b) {
    cout << "Resta: " << a - b << endl;
}

// Módulo de multiplicación
void multiplicar(int a, int b) {
    cout << "Multiplicacion: " << a * b << endl;
}

// Módulo de división
void dividir(int a, int b) {
    if (b != 0) {
        cout << "Division: " << (float)a / b << endl;
    } else {
        cout << "Division: No se puede dividir entre cero." << endl;
    }
}
