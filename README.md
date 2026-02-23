# ARD – Autómata Reconocedor Determinista

Implementación de un **Autómata Reconocedor Determinista (ARD)** en **Python y C** que determina si una cadena leída desde un archivo `.txt` es aceptada o no según un conjunto de tokens definidos.

---

## 📌 Descripción

El programa reconoce exactamente una cadena completa que pertenezca a uno de los siguientes lenguajes:

| Token        | Descripción              | Expresión formal |
|--------------|--------------------------|------------------|
| `I`          | Identificador simple     | `I`              |
| `a-b`        | Identificador compuesto  | `a-b`            |
| `+`          | Operador suma            | `+`              |
| `++`         | Operador incremento      | `++`             |
| `[0-9]`      | Entero de un dígito      | 0–9              |

El autómata es determinista y acepta únicamente coincidencias exactas.

---

## 🧠 Funcionamiento del ARD

El programa:

1. Lee una cadena desde un archivo `.txt`
2. Procesa carácter por carácter
3. Cambia de estado según la función de transición
4. Si termina en un estado de aceptación → imprime `ACEPTA`
5. En cualquier otro caso → imprime `NO ACEPTA`

Estados de aceptación:

- `I`
- `a-b`
- `+`
- `++`
- Un solo dígito

---

# 🐍 Versión en Python

## Requisitos

- macOS
- Python 3 instalado

Verificar instalación:

```bash
python3 --version
```

---

## Estructura de archivos

```
ARD/
 ├── ard.py
 └── entrada.txt
```

---

## Ejecución

Desde la carpeta del proyecto:

```bash
python3 ard.py entrada.txt
```

Salida:

```
ACEPTA
```

o

```
NO ACEPTA
```

---

# ⚙️ Versión en C

## Requisitos

- macOS
- GCC (incluido en Xcode Command Line Tools)

Si no lo tienes instalado:

```bash
xcode-select --install
```

---

## Compilación

```bash
gcc ard.c -o ard
```

---

## Ejecución

```bash
./ard entrada.txt
```

Salida:

```
ACEPTA
```

o

```
NO ACEPTA
```

---

# 🧪 Ejemplos de prueba

Contenido válido en `entrada.txt`:

```
I
```

```
a-b
```

```
+
```

```
++
```

```
7
```

Contenido inválido:

```
12
a
a-bc
+++
Ib
```

---

# 📚 Características técnicas

- Autómata determinista
- Procesamiento secuencial
- Estado trampa implícito
- Coincidencia total de cadena (no parcial)
- Lectura desde archivo externo

---

# 👨‍💻 Autor

Proyecto académico – Lenguajes y Autómatas  
Implementación en Python y C para entorno macOS.
