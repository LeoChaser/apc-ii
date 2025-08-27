#include <stdio.h>

int troca(int *p, int *q) {
    int a = *p;
    *p = *q;
    *q = a;
}

int main() {
    int m = 5, n = 3;
    troca(&m, &n);
    printf("Agora o valor de m: %i e n: %i trocaram\n", m, n);
    return 0;
}