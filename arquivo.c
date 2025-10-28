#include <stdio.h>

// void codigo_base_arquivo() {
//     FILE *fp = fopen("arquivo.txt", "modo_leitura");
//     if(fp == NULL) {
//         fprintf(stderr, "Erro ao abrir arquivo.\n");
//         return;
//     }
//     fclose(fp);
// }

// 1. Para cada numero imprima em uma linha
void imprimir_txt(char *nome_arquivo, int n, int vet[n]) {
    FILE *fp = fopen(nome_arquivo, "w");
    if(fp == NULL) {
        fprintf(stderr, "Erro ao abrir arquivo.\n");
        return;
    }
    for(int i = 0; i < n; i++) {
        fprintf(fp, "%d\n", vet[i]);
    }
    fclose(fp);
}

void exibir_txt(char *nome_arquivo) {
    FILE *fp = fopen(nome_arquivo, "r");
    if(fp == NULL) {
        fprintf(stderr, "Erro ao abrir arquivo.\n");
        return;
    }
    int numero;
    long posicao = ftell(fp);
    // fseek(fp, 3, SEEK_SET); // Pula para a posicao 3
    printf("Posicao inicial: %ld\n", posicao);
    while(fscanf(fp, "%d", &numero) != EOF) {
        posicao = ftell(fp);
        printf("%d (posicao: %ld)\n", numero, posicao);
    }
    while(1) {
        int leitura = fscanf(fp, "%d", &numero);
        if(leitura == EOF) break;
        // if(feof(fp)) break;
        posicao = ftell(fp);
        printf("%d (posicao: %ld)\n", numero, posicao);
    }
    fclose(fp);
}

int main() {
    char *nome_arquivo = "./arquivo.txt";
    int vetor[5];
    int numero;
    // for(int i = 0; i < 5; i++) numero = scanf("%d", &vetor[i]);
    // imprimir_txt(nome_arquivo, 5, vetor);
    exibir_txt(nome_arquivo);
    return 0;
}