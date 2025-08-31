#include <stdio.h>
char tela[60][20] = {}; // tela sem caractere.
void limpar_tela() {
    for(int i = 0; i < 60*20; i++)
        *(tela[0]+i) = ' ';
}
// Desenha a reta ligando A(x1,y1) a B(x2,y2)
void desenhar_reta(int x1, int y1, int x2, int y2) {
    if(x1 == x2) for(int i = 0; i < 60; i++) for(int j = 0; j < 20; j++) tela[i][x1] = '@';
    if(y1 == y2) for(int i = 0; i < 60; i++) for(int j = 0; j < 20; j++) tela[y1][j] = '@';
    double a = y1 - y2;
    double b = x2 - x1;
    double c = (x1 * y2) - (x2 * y1);
    double m = (0 - a) / b;
    double n = (0 - c) / b;
    int convertido;
    if(x2 > x1 && y2 > y1) {
        for(int i = y1; i < y2; i++) {
            for(double j = x1; j < x2; j += 0.25) {
                if((m * j + n) - (int)(m * j + n) < 0.5) {
                    convertido = (int)(m * j + n);
                } else {
                    convertido = (int)(m * j + n + 0.5);
                }
                tela[convertido][(int)j] = '@';
            }
        }
    } else if(x1 > x2 && y1 > y2) {
        for(int i = y2; i < y1; i++) {
            for(double j = x2; j < x1; j += 0.25) {
                if((m * j + n) - (int)(m * j + n) < 0.5) {
                    convertido = (int)(m * j + n);
                } else {
                    convertido = (int)(m * j + n + 0.5);
                }
                tela[convertido][(int)j] = '@';
            }
        }
    } else if(x1 > x2 && y2 > y1) {
        for(int i = y1; i < y2; i++) {
            for(double j = x2; j < x1; j += 0.25) {
                if((m * j + n) - (int)(m * j + n) < 0.5) {
                    convertido = (int)(m * j + n);
                } else {
                    convertido = (int)(m * j + n + 0.5);
                }
                tela[convertido][(int)j] = '@';
            }
        }
    } else {
        for(int i = y1; i < y2; i++) {
            for(double j = x1; j < x2; j += 0.25) {
                if((m * j + n) - (int)(m * j + n) < 0.5) {
                    convertido = (int)(m * j + n);
                } else {
                    convertido = (int)(m * j + n + 0.5);
                }
                tela[convertido][(int)j] = '@';
            }
        }
    }
    for(int i = 0; i < 60; i++) {
        for(int j = 0; j < 20; j++) {
            printf("%c", tela[i][j]);
            if(j == 19) printf("\n");
        }
    }
}
// Desenha o triângulo ligando A-B, B-C e C-A
void desenhar_triangulo(int x1, int y1, int x2, int y2, int x3, int y3) {
    int area = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
    if(area == 0) return;
    limpar_tela();
    desenhar_reta(x1, y1, x2, y2);
    desenhar_reta(x2, y2, x3, y3);
    desenhar_reta(x3, y3, x1, y1);
}

int main() {
    limpar_tela();
    int x1, y1, x2, y2, x3, y3;
    printf("Digite x1 e y1 do primeiro ponto, separados por um espaco: ");
    scanf("%d %d", &x1, &y1);
    getchar();
    printf("\nDigite x2 e y2 do segundo ponto, separados por um espaco: ");
    scanf("%d %d", &x2, &y2);
    getchar();
    desenhar_reta(x1, y1, x2, y2);
    printf("\nDigite x3 e y3 do terceiro ponto, separados por um espaco: ");
    scanf("%d %d", &x3, &y3);
    getchar();
    desenhar_triangulo(x1, y1, x2, y2, x3, y3);
    return 0;
}