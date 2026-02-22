#include <stdio.h>
#include <stdlib.h>

typedef struct pet Pet;

struct pet {
    char nome[50];
    char tipo[50];
    int idade;
    char sexo;
};

// Solicitar ao usuário a introdução de n pets,
// que serão armazenados em uma região de memória dinâmica
// retornada ao usuário.

Pet *pets;

Pet *obterPets(int n) {
    if(n <= 0) {
        fprintf(stderr, "Digite uma opção válida!\n");
        return NULL;
    }
    pets = malloc(n*sizeof(Pet));
    if(pets == NULL) { // !pets
        fprintf(stderr, "Falha na alocação!\n");
        return NULL;
    }
    char quebra = '\n';
    for(int i = 0; i < n; i++) {
        do {
            printf("Digite o nome do animal %d: ", i+1);
            scanf("%[^\n]%*c", pets[i].nome, &quebra);
        } while(quebra != '\n');
        do {
            printf("Digite o tipo do animal %d: ", i+1);
            scanf("%[^\n]%*c", pets[i].tipo, &quebra);
        } while(quebra != '\n');
        do {
            printf("Digite a idade do animal %d: ", i+1);
            scanf("%d%*c", &pets[i].idade, &quebra);
        } while(quebra != '\n' || pets[i].idade < 0);
        do {
            printf("Digite o sexo do animal %d: ", i+1);
            scanf("%c%*c", &pets[i].sexo, &quebra);
        } while(quebra != '\n' || pets[i].sexo != 'M' || pets[i].sexo != 'F' || pets[i].sexo != 'm' || pets[i].sexo != 'f');
    }
    return pets;
}

void listarPets(Pet *pets, int quant) {
    for(int i = 0; i < quant; i++) {
        printf("Animal número %d\n", i+1);
        printf("Nome: %s\n", pets[i].nome);
        printf("Tipo: %s\n", pets[i].tipo);
        printf("Idade: %d\n", pets[i].idade);
        printf("Sexo: %c\n\n", pets[i].sexo);
    }
}

int main() {
    int quantidade_pets = 2;

    listarPets(obterPets(quantidade_pets), quantidade_pets);
    free(pets);
    return 0;
}