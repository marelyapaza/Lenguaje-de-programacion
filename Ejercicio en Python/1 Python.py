def mostrar_tabla_multiplicar(n):
    print(f"\n--- Tabla de multiplicar del {n} ---")
    for i in range(1, 11):
        resultado = n * i
        print(f"{n} x {i} = {resultado}")

# Solicitar el número al usuario
try:
    n = int(input("Introduce un número entero: "))
    mostrar_tabla_multiplicar(n)
except ValueError:
    print("Error: Por favor, introduce un número entero válido.")
