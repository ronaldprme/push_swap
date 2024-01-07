#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Inicialize a semente para a função rand() usando o tempo atual
    srand(time(NULL));

    // Gere números inteiros aleatórios e imprima-os
    for (int i = 0; i < 500; i++) {
        int numeroAleatorio = rand();
        printf("%d\n", numeroAleatorio);
    }

    return 0;
}