#include <stdio.h>

int main() {
    int a=8, b=7, v[4] = {1,2,3,4};
    int *p = v;

    for(int i = -5; i < 8; i++) {
        printf("Endereço: %p\tValor: %d\n", (p + i), *(p + i));
    }
    printf("");
    return 0;
}