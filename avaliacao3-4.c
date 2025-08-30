#include <stdio.h>
char tela[60][20] = {}; // tela sem caractere.
void limpar_tela() {
    for (int i = 0; r < 60*20; i++)
    *(tela[0]+i) = ' ';
}
// Desenha a reta ligando A(x1,y1) a B(x2,y2)
void desenhar_reta(int x1, int y1, int x2, int y2) {
// implemente
}
// Desenha o triângulo ligando A-B, B-C e C-A
void desenhar_triangulo(int x1, int y1, int x2, int y2, int x3, int y3) {
// implemente
}

int main() {
    limpar_tela();
    desenhar_reta(<coloque os valores dos parâmetros dos pontos>);
    desenhar_triangulo(<coloque os valores dos parâmetros dos pontos>);
    return 0;
}