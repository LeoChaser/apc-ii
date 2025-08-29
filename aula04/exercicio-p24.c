#include <stdio.h>

void zerar_diagonais(int m, int n, int matriz[m][n]) {
    for(int i = 0; i < m; i++) {
        if(i < n) {
            matriz[i][i] = 0;
        }
        int j = n - 1 - i;
        if (j >= 0 && j < n) {
            matriz[i][j] = 0;
        }
    }
}
void imprimir_matriz(int m, int n, int matriz[m][n]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%i\t", matriz[i][j]);
        }
        printf("\n");
    }
}
void zerar_bordas(int m, int n, int matriz[m][n]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                matriz[i][j] = 0;
            }
        }
    }
}

int main() {
    int m = 4, n = 4;
    int matriz[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9,10,11,12},
        {13,14,15,16}
    };

    printf("Matriz original:\n");
    imprimir_matriz(m, n, matriz);

    zerar_diagonais(m, n, matriz);

    printf("\nMatriz com diagonais zeradas:\n");
    imprimir_matriz(m, n, matriz);
    int matriz_b[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9,10,11,12},
        {13,14,15,16}
    };
    zerar_bordas(m, n, matriz_b);

    printf("\nMatriz com bordas zeradas:\n");
    imprimir_matriz(m, n, matriz_b);

    return 0;
}