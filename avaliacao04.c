#include <stdio.h>

void modulo(double *x) {
    double original = *x;
    if(*x < 0) *x = *x * -1;
    printf("O modulo de %.2f e %.2f!\n", original, *x);
}

void min_max(int n, int vet[n], int *min_idx, int *max_idx) {
    int ref_min = 0, ref_max = 0;
    for(int i = 0; i < n; i++) {
        if(vet[i] > ref_max) {
            *max_idx = i + 1;
            ref_max = vet[i];
        } else if(vet[i] < ref_min) {
            *min_idx = i + 1;
            ref_min = vet[i];
        }
    }
    printf("Indice do menor valor: %d\nMenor valor: %d\nIndice do maior valor: %d\nMaior valor: %d\n", *min_idx, ref_min, *max_idx, ref_max);
}

void transposta(int m, int n, int A[m][n], int T[n][m]) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            T[j][i] = A[i][j];
        }
    }

    int j = 0;
    for(int i = 0; i < n; i++) {
        printf("%d %d\n", T[i][j], T[i][j+1]);
    }
}

int main() {
    double endereco = -1;
    modulo(&endereco);

    int n = 6;
    int vet[6] = { 9, -307, 0, 88,-25, 999 };
    int min_idx, max_idx;
    min_max(n, vet, &min_idx, &max_idx);
    int A[2][3] = { 9, 5, -6,
                    0, -2, 1};
    int T[3][2];
    transposta(2, 3, A, T);
    return 0;
}