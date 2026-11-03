import tkinter as tk
from tkinter import messagebox

def calcular_tabla():
    try:
        # Obtener y validar el número ingresado
        n = int(entry_numero.get())
        
        # Limpiar el área de texto antes de mostrar la nueva tabla
        text_resultado.config(state=tk.NORMAL)
        text_resultado.delete("1.0", tk.END)
        
        # Generar la tabla de multiplicar del 1 al 10
        resultado_texto = f"--- Tabla del {n} ---\n\n"
        for i in range(1, 11):
            resultado_texto += f"{n} x {i} = {n * i}\n"
            
        # Mostrar el resultado en el widget de texto
        text_resultado.insert(tk.END, resultado_texto)
        text_resultado.config(state=tk.DISABLED) # Bloquear edición manual
        
        # Limpiar la entrada y poner el foco nuevamente
        entry_numero.delete(0, tk.END)
        entry_numero.focus()
        
    except ValueError:
        messagebox.showerror("Error", "Por favor, introduce un número entero válido.")
        entry_numero.delete(0, tk.END)
        entry_numero.focus()

# Configuración de la ventana principal
root = tk.Tk()
root.title("Tabla de Multiplicar")
root.geometry("320x430")
root.resizable(False, False)
root.config(bg="#FFF0F5") # Fondo general rosa muy claro (LavenderBlush)

# Título
label_titulo = tk.Label(root, text="✨ Tabla de Multiplicar ✨", font=("Arial", 14, "bold"), bg="#FFF0F5", fg="#D81B60")
label_titulo.pack(pady=15)

# Marco para la entrada
frame_entrada = tk.Frame(root, bg="#FFF0F5")
frame_entrada.pack(pady=5)

label_instruccion = tk.Label(frame_entrada, text="Número entero (n):", font=("Arial", 10), bg="#FFF0F5", fg="#555555")
label_instruccion.pack(side=tk.LEFT, padx=5)

entry_numero = tk.Entry(frame_entrada, font=("Arial", 11), width=8, justify="center", bg="#FFFFFF", fg="#333333", relief="solid", bd=1)
entry_numero.pack(side=tk.LEFT, padx=5)
entry_numero.focus() # Poner el cursor aquí al iniciar

# Permitir calcular presionando la tecla Enter
entry_numero.bind("<Return>", lambda event: calcular_tabla())

# Botón de calcular en tono rosa oscuro/fucsia suave
btn_calcular = tk.Button(root, text="Calcular Tabla", font=("Arial", 10, "bold"), bg="#EC407A", fg="white", activebackground="#D81B60", activeforeground="white", relief="flat", padx=10, pady=5, command=calcular_tabla)
btn_calcular.pack(pady=12)

# Área de texto con diseño claro para los resultados
text_resultado = tk.Text(root, font=("Courier New", 11), width=26, height=12, state=tk.DISABLED, bg="#FFFFFF", fg="#333333", relief="solid", bd=1)
text_resultado.pack(pady=5)

# Iniciar la aplicación
root.mainloop()
