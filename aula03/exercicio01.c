#include <stdio.h>

void imprime_data(int dia, int mes, int ano) {
    printf("%i", dia);
    switch (mes) {
        case 1:
            printf(" de janeiro de ");
            break;
        case 2:
            printf(" de fevereiro de ");
            break;
        case 3:
            printf(" de março de ");
            break;
        case 4:
            printf(" de abril de ");
            break;
        case 5:
            printf(" de maio de ");
            break;
        case 6:
            printf(" de junho de ");
            break;
        case 7:
            printf(" de julho de ");
            break;
        case 8:
            printf(" de agosto de ");
            break;
        case 9:
            printf(" de setembro de ");
            break;
        case 10:
            printf(" de outubro de ");
            break;
        case 11:
            printf(" de novembro de ");
            break;
        case 12:
            printf(" de dezembro de ");
            break;
    }
    printf("%i", ano);
}


int main() {
    imprime_data(20, 12, 2029);
    return 0;
}