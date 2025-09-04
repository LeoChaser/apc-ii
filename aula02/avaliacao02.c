#include <stdio.h>
int main() {

    char string[] = "Hello World";
    char *p = string;

    while(*p != '\0') {

        p++;

    }
    printf("\nstring tem %d caracteres: \n", &p - &string);

    return 0;

}