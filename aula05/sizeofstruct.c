#include <stdio.h>

int main() {
    struct pessoa {
        char nome[100];
        int idade;
        char genero;
    };
    printf("%d\n", sizeof(struct pessoa));
    return 0;
}