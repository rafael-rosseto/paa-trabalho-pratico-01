#include <cstdlib>
#include <iostream>
#include "vetor.h"
#include "ordenacao.h"

using namespace std;

int vetorA[30], vetorB[5000], vetorC[25000];

int main()
{
    gerarVetor(vetorA, false, COUNT_OF(vetorA));
    cout << "Vetor desordenado:" << endl;
    imprimirVetor(vetorA, COUNT_OF(vetorA));
    mergeSort(vetorA, COUNT_OF(vetorA));
    cout << "Vetor ordenado:" << endl;
    imprimirVetor(vetorA, COUNT_OF(vetorA));

    return 0;
}