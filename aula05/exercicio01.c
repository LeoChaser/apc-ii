#include <stdio.h>

typedef unsigned int uint;

typedef struct pessoa Pessoa;

struct pessoa {
    char nome[100];
    int idade;
};

void define_pessoas(uint n, Pessoa pessoas[n]) {
    int i = 0;
    while(i < n) {
        printf("Digite o nome:\n");
        scanf("%99[^\n]%*c", pessoas[i].nome);
        printf("Digite a idade:\n");
        scanf("%d%*c", &pessoas[i].idade);
        i++;
    }
    
}
void exibe_pessoas(uint n, Pessoa pessoas[n]) {
    for(int j = 0; j < n; j++) {
        printf("Pessoa %d\nNome: %s\tIdade: %d\n", j + 1, pessoas[j].nome, pessoas[j].idade);
    }
}
int main() {
    int n;
    printf("Informe o numero de pessoas: ");
    scanf("%d%*c", &n);
    Pessoa pessoas[n];
    define_pessoas(n, pessoas);
    exibe_pessoas(n, pessoas);

    return 0;
}