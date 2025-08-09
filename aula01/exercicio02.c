#include <stdio.h>
int main(void) {
    int numero, *n;
    n = &numero;
    *n = 5;

    printf("Valor de numero = %d\n", numero);

    return 0;
}