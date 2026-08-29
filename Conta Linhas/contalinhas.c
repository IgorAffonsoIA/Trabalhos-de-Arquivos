#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *arquivo;
    int caractere;
    int linhas = 0;

    if (argc != 2) {
        printf("Uso: %s <arquivo>\n", argv[0]);
        return 1;
    }

    arquivo = fopen(argv[1], "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    while ((caractere = fgetc(arquivo)) != EOF) {
        if (caractere == '\n') {
            linhas++;
        }
    }

    fclose(arquivo);

    printf("Quantidade de linhas: %d\n", linhas);

    return 0;
}
