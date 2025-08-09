#include <stdio.h>
int main() {
    int i = 5;
    int *p;
    p = &i;

    printf("&p: %p\n", &p);
    printf("p (&i - endereco de i): %p\n", p);
    printf("*p (i - valor de i): %d\n", *p);

    *p = 99;
    printf("&p: %p\n", &p);
    printf("p (&i - endereco de i): %p\n", p);
    printf("*p (i - valor de i): %d\n", *p);

    printf("Digite o novo valor de p:\n");
    scanf("%d", p);
    printf("p (&i - endereco de i): %p\n", p);
    printf("*p (i - valor de i): %d\n", *p);

    return 0;
}