#include <cstdlib>
#include <iostream>
#include "vetor.h"
#include "ordenacao.h"

int vetorOrdenadoA[1000], vetorOrdenadoB[5000], vetorOrdenadoC[25000];
int vetorAleatorioA[1000], vetorAleatorioB[5000], vetorAleatorioC[25000];

int main()
{
    gerarVetorOrdenado(vetorOrdenadoA, COUNT_OF(vetorOrdenadoA));
    imprimirVetor(vetorOrdenadoA, COUNT_OF(vetorOrdenadoA));

    return 0;
}