#include <iostream>

using namespace std;
void gestionar_notas() {
    int n;
    cout << "\n--- PREGUNTA 3: GESTION DE NOTAS ---" << endl;
    cout << "Ingrese la cantidad de estudiantes (entre 1 y 30): ";
    cin >> n;
        
    double notas[30]; 
    double suma = 0.0;
    
    // Bucle directo para registrar las notas
    for (int i = 0; i < n; i++) {
        cout << "Ingrese la nota del estudiante " << (i + 1) << " (0 - 20): ";
        cin >> notas[i];
        suma += notas[i];
    }
            
    double promedio = suma / n;
    double nota_alta = notas[0];
    double nota_baja = notas[0];
    int aprobados = 0;
    
    for (int i = 0; i < n; i++) {
        if (notas[i] > nota_alta) nota_alta = notas[i];
        if (notas[i] < nota_baja) nota_baja = notas[i];
        if (notas[i] >= 10.5) aprobados++;
    }
    int desaprobados = n - aprobados;
    
    cout << "\n--- REPORTE DE NOTAS ---" << endl;
    cout << "Promedio general del grupo: " << promedio << endl;
    cout << "Nota mas alta: " << nota_alta << endl;
    cout << "Nota mas baja: " << nota_baja << endl;
    cout << "Cantidad de aprobados (>= 10.5): " << aprobados << endl;
    cout << "Cantidad de desaprobados: " << desaprobados << endl;
}
int main() {
   
    gestionar_notas();
    return 0;
}

