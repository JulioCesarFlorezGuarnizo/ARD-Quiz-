#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int es_digito(char c) {
    return c >= '0' && c <= '9';
}

int ard(char *cadena) {

    int estado = 0;

    for (int i = 0; i < strlen(cadena); i++) {
        char c = cadena[i];

        switch (estado) {

            case 0:
                if (c == 'I')
                    estado = 1;
                else if (c == 'a')
                    estado = 2;
                else if (c == '+')
                    estado = 5;
                else if (es_digito(c))
                    estado = 7;
                else
                    estado = 8;
                break;

            case 2:
                if (c == '-')
                    estado = 3;
                else
                    estado = 8;
                break;

            case 3:
                if (c == 'b')
                    estado = 4;
                else
                    estado = 8;
                break;

            case 5:
                if (c == '+')
                    estado = 6;
                else
                    estado = 8;
                break;

            default:
                estado = 8;
        }
    }

    if (estado == 1 || estado == 4 || estado == 5 || estado == 6 || estado == 7)
        return 1;

    return 0;
}

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Uso: ./ard archivo.txt\n");
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (!f) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    char cadena[100];
    fgets(cadena, sizeof(cadena), f);
    fclose(f);

    cadena[strcspn(cadena, "\n")] = 0;

    if (ard(cadena))
        printf("ACEPTA\n");
    else
        printf("NO ACEPTA\n");

    return 0;
}
