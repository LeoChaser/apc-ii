#include <stdio.h>
#include <stdlib.h>

// 1. Alocar n inteiros, onde n deve ser > 0.
int *criar_array_v1(int n) {
    if(n <= 0) return NULL;
    return malloc(sizeof(int)*n);
}
int *criar_array_v2(int n) {
    if(n <= 0) return NULL;
    return calloc(n, sizeof(int));
}

// 2. Preencher array de n elementos positivos.
void preencher_array(int n, int vet[n]) {
    for(int i = 0; i < n; i++)
        do {
            printf("\nIntroduza o elemento %d: ", i);
            scanf("%d", &vet[i]);
        } while(vet[i] <= 0);
}

// 3. Exibir array.
void exibir_array(int n, int vet[n]) {
    for(int i = 0; i < n; i++) printf("[%d]", vet[i]);
    printf("\n");
}


int main() {
    int *dynamic_num = NULL;
    int *dynamic_vet = NULL;
    int local_num = 5;

    dynamic_num = malloc(sizeof(int));
    dynamic_vet = malloc(sizeof(int));
    dynamic_vet = criar_array_v1(5);
    preencher_array(5, dynamic_vet);
    exibir_array(5, dynamic_vet);

    return 0;
}