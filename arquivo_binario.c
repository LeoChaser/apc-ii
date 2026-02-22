#include <stdio.h>

int numeros[10] = {3, 6, 1, 8, 2, 9, 0, 5, 7, 4};
// typedef struct pessoa Pessoa;

// struct pessoa {
//     char nome[100];
//     int idade;
// };

int salvar_numeros_bin(char *nome_arquivo, int n, int vet[n]) {
    FILE *fp = fopen(nome_arquivo, "wb");
    if(!fp) { // !(NULL)
        fprintf(stderr, "Erro ao abrir o arquivo!\n");
        return 0;
    }
    //operacoes de escrita
    // fwrite(&numeros[4], sizeof(int), 1, fp);
    // fwrite(&numeros[0], sizeof(int), 1, fp);
    fwrite(numeros, sizeof(int), 10, fp);
    fclose(fp);
    return 1;
}
void exibir_numeros_bin(char *nome_arquivo){
    //leitura
    FILE *fp = fopen(nome_arquivo, "rb");
    if(!fp) { // !(NULL)
        fprintf(stderr, "Erro ao abrir o arquivo!\n");
        return;
    }
    //operacoes de leitura
    int num;
    while(fread(&num, sizeof(int), 1, fp) == 1){
        printf("num: %d\n", num);
    }

    fclose(fp);
}

int main() {
    if(!salvar_numeros_bin("./numeros.dat", 10, numeros)) return 1;
    exibir_numeros_bin("./numeros.dat");
    return 0;
}