#include <stdio.h>

typedef struct canais Canais;
typedef union pixel Pixel;

struct canais {
    #if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
        unsigned char r, g, b, a;
    #else // Little-endian
        unsigned char a, b, g, r;
    #endif
};

union pixel {
    int cor;
    Canais canais;
};

void limpar_tela() {
    printf("\033[2J"); // Limpa a tela
    printf("\033[H"); // Move cursor para a posição inicial
}

void desenha_pixel_em_xy(int x, int y, Pixel *pixel) {
    // Move cursor para (x, y)
    printf("\033[%d;%dH", y + 1, x * 2 + 1);

    // Define a cor de fundo com os valores de cor RGB.
    printf("\033[48;2;%d;%d;%dm  \033[0;00m", pixel->canais.r, pixel->canais.g, pixel->canais.b);
}

void desenha_imagem(int x, int y, int n, Pixel imagem[n][n]) {
    for(int l = 0; l < n; l++) {
        for (int c = 0; c < n; c++) {
            desenha_pixel_em_xy(x+c, y+l, &imagem[l][c]);
        }
    }
}

void copiar_imagem(int n, int origem[n][n], Pixel destino[n][n]) {
    for(int l = 0; l < n; l++)
        for (int c = 0; c < n; c++)
            destino[l][c].cor=origem[l][c];
}

int imagem[10][10] = {
    {0xFF0000FF, 0xE61919FF, 0xCC3333FF, 0xB34C4CFF, 0x996666FF, 0x808080FF, 0x669999FF, 0x4CB3B3FF, 0x33CCCCFF, 0x19E6E6FF},
    {0xFF1900FF, 0xE63319FF, 0xCC4C33FF, 0xB3664CFF, 0x998066FF, 0x809980FF, 0x66B399FF, 0x4CCCB3FF, 0x33E6CCFF, 0x19FFE6FF},
    {0xFF3300FF, 0xE64C19FF, 0xCC6633FF, 0xB3804CFF, 0x999966FF, 0x80B380FF, 0x66CC99FF, 0x4CE6B3FF, 0x33FFCCFF, 0x19FFE6FF},
    {0xFF4C00FF, 0xE66619FF, 0xCC8033FF, 0xB3994CFF, 0x99B366FF, 0x80CC80FF, 0x66E699FF, 0x4CFFB3FF, 0x33FFCCFF, 0x19FFE6FF},
    {0xFF6600FF, 0xE68019FF, 0xCC9933FF, 0xB3B34CFF, 0x99CC66FF, 0x80E680FF, 0x66FF99FF, 0x4CFFB3FF, 0x33FFCCFF, 0x19FFE6FF},
    {0xFF8000FF, 0xE69919FF, 0xCCB333FF, 0xB3CC4CFF, 0x99E666FF, 0x80FF80FF, 0x66FF99FF, 0x4CFFB3FF, 0x33FFCCFF, 0x19FFE6FF},
    {0xFF9900FF, 0xE6B319FF, 0xCCCC33FF, 0xB3E64CFF, 0x99FF66FF, 0x80FF80FF, 0x66FF99FF, 0x4CFFB3FF, 0x33FFCCFF, 0x19FFE6FF},
    {0xFFB300FF, 0xE6CC19FF, 0xCCE633FF, 0xB3FF4CFF, 0x99FF66FF, 0x80FF80FF, 0x66FF99FF, 0x4CFFB3FF, 0x33FFCCFF, 0x19FFE6FF},
    {0xFFCC00FF, 0xE6E619FF, 0xCCFF33FF, 0xB3FF4CFF, 0x99FF66FF, 0x80FF80FF, 0x66FF99FF, 0x4CFFB3FF, 0x33FFCCFF, 0x19FFE6FF},
    {0xFFE600FF, 0xE6FF19FF, 0xCCFF33FF, 0xB3FF4CFF, 0x99FF66FF, 0x80FF80FF, 0x66FF99FF, 0x4CFFB3FF, 0x33FFCCFF, 0x19FFE6FF}
};

int main() {
    limpar_tela();
    desenha_imagem(5, 5, 10, (Pixel (*)[10])imagem);
    Pixel imagem2[10][10];
    copiar_imagem(10, imagem, imagem2);
    for(int l = 0; l < 10; l++)
        for (int c = 0; c < 10; c++)
            imagem2[l][c].canais.r = 0;
    desenha_imagem(20, 5, 10, imagem2);
    Pixel imagem3[10][10];
    unsigned char cinza;
    copiar_imagem(10, imagem, imagem3);
    for(int l = 0; l < 10; l++)
        for (int c = 0; c < 10; c++) {
            cinza = (float)(imagem3[l][c].canais.r + imagem3[l][c].canais.g + imagem3[l][c].canais.b)/3 + 0.5;
            imagem3[l][c].canais.r = cinza;
            imagem3[l][c].canais.g = cinza;
            imagem3[l][c].canais.b = cinza;
        }
    desenha_imagem(35, 5, 10, imagem3);
    printf("\n\n");

    return 0;
}