#include <cstdlib>
#include <iostream>
#include <chrono>
#include "vetor.h"
#include "ordenacao.h"

using namespace std;
using namespace std::chrono;

#define bubbleSimples(x) bubbleSortSimples(x, COUNT_OF(x))
#define bubbleMelhor(x) bubbleSortMelhor(x, COUNT_OF(x))
#define quick(x) quickSort(x, 0, COUNT_OF(x), true)
#define insertion(x) insertionSort(x, COUNT_OF(x))
#define shell(x) shellSort(x, COUNT_OF(x))
#define selection(x) selectionSort(x, COUNT_OF(x))
#define heap(x) heapSort(x, COUNT_OF(x))
#define merge(x) mergeSort(x, COUNT_OF(x))

int main()
{
    gerarVetor(vetorB, false, COUNT_OF(vetorB));

    // Imprimir vetor:
    /* 
    cout << "Vetor desordenado:" << endl;
    imprimirVetor(vetorB, COUNT_OF(vetorB));
    */

    auto time0 = high_resolution_clock::now();
    bubbleSimples(vetorB);
    auto time1 = high_resolution_clock::now();
    auto time = duration_cast<microseconds>(time1 - time0);

    // Imprimir Vetor:
    /*  
    cout << "Vetor ordenado:" << endl;
    imprimirVetor(vetorB, COUNT_OF(vetorB));
    */

    cout << "Tempo de ordenação: " << time.count() << " microsegundos." << endl;

    return 0;
}