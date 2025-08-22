#include <stdio.h>

double volume_esfera(double raio) {
    return 3.1415*raio*raio*raio*4.0/3.0;
}

int main() {
    printf("Volume da esfera: %f\n", volume_esfera(2));
    return 0;
}