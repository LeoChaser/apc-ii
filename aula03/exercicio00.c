#include <stdio.h>

void imprime(int x, char c) {
    for(int i = 1; i <= x; i++) {
        printf("%c", c);
    }
    printf("\n");
}

int main() {
    imprime(1, 'A');
    imprime(2, 'V');
    imprime(3, 'K');
    imprime(10, '*');
    return 0;
}