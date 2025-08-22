#include <stdio.h>

int converte_em_segundos(int h, int m, int s) {
    return h * 60 * 60 + m * 60 + s;
}

int main() {
    printf("Seguntos totais: %d\n", converte_em_segundos(1, 2, 30));
    return 0;
}