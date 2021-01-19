#include <cstdlib>
#include <iostream>
#include "vetor.h"
#include "ordenacao.h"

#define COUNT_OF(x) ((sizeof(x) / sizeof(0 [x])) / ((size_t)(!(sizeof(x) % sizeof(0 [x])))))

int vetorA[1000], vetorB[5000], vetorC[25000];

int main()
{
    gerarVetor(vetorA, 1, COUNT_OF(vetorA));
    imprimirVetor(vetorA, COUNT_OF(vetorA));

    return 0;
}