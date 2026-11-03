#include <iostream>

using namespace std;

int calcularFibonacci(int n);

int main() {
    int n;
    cout << "Ingresa la cantidad de terminos de Fibonacci: ";
    cin >> n;
    
    calcularFibonacci(n);
    
    return 0;
}

int calcularFibonacci(int n) {
    int a = 0, b = 1, siguiente;
    
    cout << "Serie de Fibonacci: " << endl;
    for (int i = 1; i <= n; i++) {
        cout << a << endl;
        siguiente = a + b;
        a = b;
        b = siguiente;
    }
    
    return 0;
}
