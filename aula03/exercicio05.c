#include <stdio.h>

int fatorial(int num) {
    int resultado = 1;
    for(int i = num; i >= 2; i--) {
        resultado *= i;
    }
    return resultado;
}

int main() {
    int numero = 6;
    if(numero >= 0) {
        printf("Fatorial de %i: %d\n", numero, fatorial(numero));
    }

    return 0;
}