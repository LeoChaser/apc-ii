#include <stdio.h>
void preenche_vetor(int *n, int vetor[*n], int vetor_quantidade[2]) {
    printf("Preencha o vetor com %i numeros inteiros: \n", *n);
    for(int i = 0; i < *n; i++) {
        printf("\nNumero %i: ", i+1);
        scanf("%i", &vetor[i]);
        if(vetor[i] %2 == 0) {
            vetor_quantidade[0]++;
        } else {
            vetor_quantidade[1]++;
        }
    }
}
void zera(int *n, int vetor[*n]) {
    for(int i = 0; i < *n; i++) {
        if(vetor[i] % 2 != 0) vetor[i] = 0;
    }
}
void busca_string(char palavra[0], char busca, char subs) {
    int n = 0;
    while(palavra[n] != '\0') {
        n++;
    }
    for(int i = 0; i < n; i++) {
        if(palavra[i] == busca) palavra[i] = subs;
    }
}

int main() {
    int n = 0;
    printf("Digite a quantidade de números inteiros do vetor:\n", n);
    scanf("%i", &n);
    int vetor[n];
    int vetor_quantidade[2];
    preenche_vetor(&n, vetor, vetor_quantidade);

    printf("\nVetores:");
    for(int i = 0; i < n; i++) {
        printf("\nvetor[%i] = %i", i, vetor[i]);
    }
    printf("\nQuantidade de pares: %i", vetor_quantidade[0]);
    printf("\nQuantidade de impares: %i", vetor_quantidade[1]);
    zera(&n, vetor);
    printf("\nVetores zerados:");
    for(int i = 0; i < n; i++) {
        printf("\nvetor[%i] = %i", i, vetor[i]);
    }
    char palavra[0], busca, subs;
    printf("\nDigite uma palavra: ");
    
    scanf("%s", palavra);
    getchar();
    printf("\nDigite um caractere para buscar: ");
    scanf("%c", &busca);
    getchar();
    printf("\nDigite um caractere para substituir: ");
    scanf("%c", &subs);
    getchar();

    busca_string(palavra, busca, subs);

    printf("\n A palavra apos substituicao: %s", palavra);
    printf("\n");
    return 0;
}