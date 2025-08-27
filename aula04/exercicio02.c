#include <stdio.h>

int divisao(int *p, int *q, float *d) {
    if(*q != 0) {
        *d = *p * 1.0 / *q;
    } else {
        printf("Não divida por 0!\n");
    }
}

int main() {
    int m = 5, n = 0;
    float o = 0;
    divisao(&m, &n, &o);
    if(n != 0) {
        printf("Divisao de %i por %i = %f \n", m, n, o);
    }
    return 0;
}