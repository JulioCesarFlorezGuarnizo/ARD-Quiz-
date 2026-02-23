import sys

def es_digito(c):
    return '0' <= c <= '9'

def ard(cadena):
    estado = "q0"

    for c in cadena:
        if estado == "q0":
            if c == 'I':
                estado = "q1"
            elif c == 'a':
                estado = "q2"
            elif c == '+':
                estado = "q5"
            elif es_digito(c):
                estado = "q7"
            else:
                estado = "q_dead"

        elif estado == "q2":
            if c == '-':
                estado = "q3"
            else:
                estado = "q_dead"

        elif estado == "q3":
            if c == 'b':
                estado = "q4"
            else:
                estado = "q_dead"

        elif estado == "q5":
            if c == '+':
                estado = "q6"
            else:
                estado = "q_dead"

        else:
            estado = "q_dead"

    return estado in ["q1", "q4", "q5", "q6", "q7"]


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Uso: python3 ard.py archivo.txt")
        sys.exit(1)

    with open(sys.argv[1], "r") as f:
        cadena = f.read().strip()

    if ard(cadena):
        print("ACEPTA")
    else:
        print("NO ACEPTA")
