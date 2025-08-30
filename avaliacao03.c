#include <stdio.h>
#include <stdlib.h>

void exibir_equacao_geral_da_reta(double x1, double y1, double x2, double y2) {
    double a = y1 - y2;
    double b = x2 - x1;
    double c = (x1 * y2) - (x2 * y1);
    printf("\nEquacao geral da reta: %.2fx + %.2fy + %.2f = 0\n", a, b, c);
}

void exibir_funcao_da_reta(double x1, double y1, double x2, double y2) {
    double a = y1 - y2;
    double b = x2 - x1;
    double c = (x1 * y2) - (x2 * y1);
    double m = (0 - a) / b;
    double n = (0 - c) / b;
    if(b != 0) {
        printf("\nf(x) = y = %.2fx + %.2f\n", m, n);
    } else {
        printf("\nA reta e vertical (x = %.2f) e nao define uma funcao y = f(x).\n", x1);
    }
}
double y(double x1, double y1, double x2, double y2, double x) {
    double a = y1 - y2;
    double b = x2 - x1;
    double c = (x1 * y2) - (x2 * y1);
    double m = (0 - a) / b;
    double n = (0 - c) / b;
    if(b == 0) exit(1);
    printf("\nf(%.2f) = y = %.2fx + %.2f = %.2f\n", x, m, n, m * x + n);
}


int main() {
    double x1, y1, x2, y2, x;
    printf("Digite x1 e y1 do primeiro ponto, separados por um espaco: ");
    scanf("%lf %lf", &x1, &y1);
    getchar();
    printf("\nDigite x2 e y2 do segundo ponto, separados por um espaco: ");
    scanf("%lf %lf", &x2, &y2);
    getchar();
    exibir_equacao_geral_da_reta(x1, y1, x2, y2);
    exibir_funcao_da_reta(x1, y1, x2, y2);

    printf("\nDigite um valor qualquer de x: ");
    scanf("%lf", &x);
    getchar();
    y(x1, y1, x2, y2, x);

    return 0;
}