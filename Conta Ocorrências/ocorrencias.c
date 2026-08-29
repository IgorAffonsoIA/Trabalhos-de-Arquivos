#include <stdio.h>

int main(int argc, char *argv[]){
    FILE *arquivo;
    int caractere;
    int ocorrencias[256] = {0};
    
    if(argc != 2){
        printf("Uso: %s <arquivo>\n", argv[0]);
        return 1;
    }

    arquivo = fopen(argv[1], "rb");

    if(arquivo == NULL){
        printf("Erro ao abrir arquivo\n");
        return 1;
    }

    while((caractere = fgetc(arquivo)) != EOF){
        ocorrencias[caractere]++;
    }
    fclose(arquivo);

    for (int i = 0; i < 256; i++){
        if ((i >= 'A' && i <= 'Z') || (i >= 'a' && i <= 'z')){
            if(ocorrencias[i] > 0){
                printf("%c: %d\n", i, ocorrencias[i]);
            }
        }
    } return 0;
}
