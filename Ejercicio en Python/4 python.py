import tkinter as tk
from tkinter import messagebox

class CalculadoraLilaApp:
    def __init__(self, root):
        self.root = root
        self.root.title("✨ Calculadora Lila Aesthetic ✨")
        self.root.geometry("340x530")
        self.root.resizable(False, False)
        self.root.config(bg="#F3E8FF") # Fondo general lila muy suave

        # Variable para controlar en cuál entrada se escribirá el número ('num1' o 'num2')
        self.campo_activo = "num1"

        # --- TÍTULO ---
        label_titulo = tk.Label(root, text="💜 Calculadora Aesthetic 💜", font=("Arial", 14, "bold"), bg="#F3E8FF", fg="#581C87")
        label_titulo.pack(pady=10)

        # --- CAMPOS DE ENTRADA ---
        frame_inputs = tk.Frame(root, bg="#F3E8FF")
        frame_inputs.pack(pady=5)

        # Número 1
        tk.Label(frame_inputs, text="Número 1:", font=("Arial", 10, "bold"), bg="#F3E8FF", fg="#581C87").grid(row=0, column=0, padx=5, sticky="e")
        self.entry_num1 = tk.Entry(frame_inputs, font=("Arial", 11), width=12, justify="center", bg="#FFFFFF", fg="#581C87", relief="solid", bd=1)
        self.entry_num1.grid(row=0, column=1, padx=5)
        self.entry_num1.bind("<FocusIn>", lambda e: setattr(self, 'campo_activo', 'num1'))

        # Número 2
        tk.Label(frame_inputs, text="Número 2:", font=("Arial", 10, "bold"), bg="#F3E8FF", fg="#581C87").grid(row=1, column=0, padx=5, pady=5, sticky="e")
        self.entry_num2 = tk.Entry(frame_inputs, font=("Arial", 11), width=12, justify="center", bg="#FFFFFF", fg="#581C87", relief="solid", bd=1)
        self.entry_num2.grid(row=1, column=1, padx=5, pady=5)
        self.entry_num2.bind("<FocusIn>", lambda e: setattr(self, 'campo_activo', 'num2'))

        # --- BOTONES DE OPERACIONES ---
        frame_ops = tk.Frame(root, bg="#F3E8FF")
        frame_ops.pack(pady=10)

        btn_style = {
            "font": ("Arial", 10, "bold"), 
            "bg": "#C084FC", 
            "fg": "white", 
            "activebackground": "#9333EA", 
            "activeforeground": "white", 
            "relief": "flat", 
            "width": 6, 
            "pady": 4
        }
        
        tk.Button(frame_ops, text="Suma (+)", command=lambda: self.calcular("suma"), **btn_style).grid(row=0, column=0, padx=4)
        tk.Button(frame_ops, text="Resta (-)", command=lambda: self.calcular("resta"), **btn_style).grid(row=0, column=1, padx=4)
        tk.Button(frame_ops, text="Multi (×)", command=lambda: self.calcular("multi"), **btn_style).grid(row=0, column=2, padx=4)
        tk.Button(frame_ops, text="Div (÷)", command=lambda: self.calcular("div"), **btn_style).grid(row=0, column=3, padx=4)

        # --- TECLADO NUMÉRICO ---
        frame_teclado = tk.Frame(root, bg="#E9D5FF", relief="solid", bd=1)
        frame_teclado.pack(pady=5, padx=10, fill="x")

        tk.Label(frame_teclado, text="Haz clic para escribir en el campo seleccionado:", font=("Arial", 8, "italic"), bg="#E9D5FF", fg="#581C87").pack(pady=3)

        grid_teclas = tk.Frame(frame_teclado, bg="#E9D5FF")
        grid_teclas.pack(pady=5)

        teclas = [
            ('7', 0, 0), ('8', 0, 1), ('9', 0, 2),
            ('4', 1, 0), ('5', 1, 1), ('6', 1, 2),
            ('1', 2, 0), ('2', 2, 1), ('3', 2, 2),
            ('0', 3, 1), ('.', 3, 0), ('C', 3, 2)
        ]

        for (texto, fila, col) in teclas:
            if texto == 'C':
                cmd = self.borrar_ultimo
                bg_color = "#9333EA"
                fg_color = "white"
            else:
                cmd = lambda t=texto: self.insertar_digito(t)
                bg_color = "#FFFFFF"
                fg_color = "#581C87"

            btn = tk.Button(grid_teclas, text=texto, font=("Arial", 10, "bold"), bg=bg_color, fg=fg_color, width=5, height=1, relief="solid", bd=1, command=cmd)
            btn.grid(row=fila, column=col, padx=3, pady=3)

        # --- ÁREA DE RESULTADOS ---
        self.text_resultado = tk.Text(root, font=("Courier New", 10), width=36, height=7, state=tk.DISABLED, bg="#FFFFFF", fg="#581C87", relief="solid", bd=1)
        self.text_resultado.pack(pady=10)

        # Establecer el foco inicial en el Número 1
        self.entry_num1.focus()

    def insertar_digito(self, digito):
        entry_activo = self.entry_num1 if self.campo_activo == "num1" else self.entry_num2
        entry_activo.insert(tk.END, digito)

    def borrar_ultimo(self):
        entry_activo = self.entry_num1 if self.campo_activo == "num1" else self.entry_num2
        texto_actual = entry_activo.get()
        if texto_actual:
            entry_activo.delete(len(texto_actual)-1, tk.END)

    def calcular(self, operacion):
        try:
            val1 = float(self.entry_num1.get())
            val2 = float(self.entry_num2.get())

            if operacion == "suma":
                res = val1 + val2
                simbolo = "+"
            elif operacion == "resta":
                res = val1 - val2
                simbolo = "-"
            elif operacion == "multi":
                res = val1 * val2
                simbolo = "×"
            elif operacion == "div":
                if val2 == 0:
                    messagebox.showerror("Error de división", "No se puede dividir entre cero.")
                    return
                res = val1 / val2
                simbolo = "÷"

            # Mostrar resultados organizados
            resultado_str = f"--- Resultados ---\n"
            resultado_str += f" {val1} {simbolo} {val2} = {res}\n\n"
            resultado_str += f" Suma:          {val1 + val2}\n"
            resultado_str += f" Resta:         {val1 - val2}\n"
            resultado_str += f" Multiplicación:{val1 * val2}\n"
            if val2 != 0:
                resultado_str += f" División:      {val1 / val2:.2f}\n"
            else:
                resultado_str += f" División:      Error (Div/0)\n"

            self.text_resultado.config(state=tk.NORMAL)
            self.text_resultado.delete("1.0", tk.END)
            self.text_resultado.insert(tk.END, resultado_str)
            self.text_resultado.config(state=tk.DISABLED)

        except ValueError:
            messagebox.showerror("Error", "Por favor, introduce números válidos en ambos campos.")

if __name__ == "__main__":
    root = tk.Tk()
    app = CalculadoraLilaApp(root)
    root.mainloop()
