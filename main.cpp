#include <cstdlib>
#include <iostream>
#include "vetor.h"
#include "ordenacao.h"

using namespace std;

#define COUNT_OF(x) ((sizeof(x) / sizeof(0 [x])) / ((size_t)(!(sizeof(x) % sizeof(0 [x])))))

int vetorA[30], vetorB[5000], vetorC[25000];

int main()
{
    gerarVetor(vetorA, false, COUNT_OF(vetorA));
    cout << "Vetor desordenado:" << endl;
    imprimirVetor(vetorA, COUNT_OF(vetorA));
    selectionSort(vetorA, COUNT_OF(vetorA));
    cout << "Vetor ordenado:" << endl;
    imprimirVetor(vetorA, COUNT_OF(vetorA));

    return 0;
}