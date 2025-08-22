#include <stdio.h>

int mod6(int num) {
    return num % 6;
}

int main() {
    int numero = 12;
    if(mod6(numero) == 0) {
        printf("O numero %i e divisivel por 6!\n", numero);
        return 1;
    } else {
        printf("O numero %i nao e divisivel por 6!\n", numero);
        return 0;
    }
}