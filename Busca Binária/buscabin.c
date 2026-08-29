#include <stdio.h>
#include <string.h>

typedef struct {
    char logradouro[72];
    char bairro[72];
    char cidade[72];
    char estado[72];
    char sigla[2];
    char cep[8];
    char lixo[2];
} Endereco;

int main() {

    FILE *arquivo;
    Endereco endereco;

    char cepProcurado[9];

    long inicio;
    long fim;
    long meio;
    long quantidade;

    arquivo = fopen("cep_ordenado.dat", "rb");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    printf("Digite o CEP que deseja procurar: ");
    scanf("%8s", cepProcurado);

    fseek(arquivo, 0, SEEK_END);

    quantidade = ftell(arquivo) / sizeof(Endereco);

    inicio = 0;
    fim = quantidade - 1;

    while (inicio <= fim) {

        meio = (inicio + fim) / 2;

        fseek(arquivo, meio * sizeof(Endereco), SEEK_SET);

        fread(&endereco, sizeof(Endereco), 1, arquivo);

        int comparacao = strncmp(cepProcurado, endereco.cep, 8);

        if (comparacao == 0) {

            printf("\nCEP: %.8s\n", endereco.cep);
            printf("Logradouro: %.72s\n", endereco.logradouro);
            printf("Bairro: %.72s\n", endereco.bairro);
            printf("Cidade: %.72s\n", endereco.cidade);
            printf("Estado: %.72s\n", endereco.estado);
            printf("UF: %.2s\n", endereco.sigla);

            fclose(arquivo);
            return 0;
        }

        if (comparacao < 0) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }

    printf("CEP nao encontrado.\n");

    fclose(arquivo);

    return 0;
}
