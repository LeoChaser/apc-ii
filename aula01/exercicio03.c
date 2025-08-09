#include <stdio.h>
int main(void) {
    int n1 = 3, n2 = 5;
    int n3, *m, *n, *p;
    m = &n1;
    n = &n2;
    p = &n3;
    *p = *m;
    *m = *n;
    *n = *p;

    printf("n1: %d, n2: %d\n", n1, n2);
    return 0;
}