/* 
[Intergrantes]
Gustavo Palmeira Zaia							191252158
Rafael Bassi Rosseto							191251968
Vinicius Polachini Mayer Freitas de Jesus		191251852
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>
#include "vetor.h"
#include "ordenacao.h"

using namespace std;
using namespace std::chrono;

#define N_AMOSTRAS 10

/*
 * i = algoritmo de ordenação
 * 
 * 0 - Bubble Sort Simples
 * 1 - Bubble Sort Melhor
 * 2 - Insertion Sort
 * 3 - Shell Sort
 * 4 - Selection Sort
 * 5 - Heap Sort
 * 6 - Merge Sort
 * 7 - Quick Sort
 * 
 * 
 * j = vetor utilizado
 * 
 * 0 = vetorA[2000]
 * 1 = vetorB[10000]
 * 2 = vetorC[20000]
 * 
 */

int main()
{
    int vetorA[5000], vetorB[10000], vetorC[20000];
    int tamanho;
    int resultadosMedia[8][3];
    int resultadosMaior[8][3];
    int resultadosMenor[8][3];
    int resultadoCrescente[8][3];
    int resultadoDecrescente[8][3];

    for (int i = 0; i < 8; i++) // inicializando as matrizes de resultado
    {
        for (int j = 0; j < 3; j++)
        {
            resultadosMedia[i][j] = 0;
            resultadosMaior[i][j] = 0;
            resultadosMenor[i][j] = 0xFFFFFF;
            resultadoCrescente[i][j] = 0;
            resultadoDecrescente[i][j] = 0;
        }
    }

    std::cout << "Ordenando varios vetores, isto pode demorar um pouco..." << endl;

    ofstream file;
    file.open("analize.txt");
    for (int amostra = 0; amostra < N_AMOSTRAS; amostra++)
    {
        for (int i = 0; i < 8; i++)
        {

            tamanho = COUNT_OF(vetorA);
            gerarVetor(vetorA, false, tamanho);
            switch (i)
            {
            case (0):
            {
                auto time0 = high_resolution_clock::now();
                bubbleSortSimples(vetorA, tamanho);
                auto time1 = high_resolution_clock::now();
                auto time = duration_cast<microseconds>(time1 - time0);
                if (time.count() < resultadosMenor[i][0])
                    resultadosMenor[i][0] = time.count();
                if (time.count() > resultadosMaior[i][0])
                    resultadosMaior[i][0] = time.count();
                resultadosMedia[i][0] += time.count();
                break;
            }
            case (1):
            {
                auto time0 = high_resolution_clock::now();
                bubbleSortMelhor(vetorA, tamanho);
                auto time1 = high_resolution_clock::now();
                auto time = duration_cast<microseconds>(time1 - time0);
                if (time.count() < resultadosMenor[i][0])
                    resultadosMenor[i][0] = time.count();
                if (time.count() > resultadosMaior[i][0])
                    resultadosMaior[i][0] = time.count();
                resultadosMedia[i][0] += time.count();
                break;
            }
            case (2):
            {
                auto time0 = high_resolution_clock::now();
                insertionSort(vetorA, tamanho);
                auto time1 = high_resolution_clock::now();
                auto time = duration_cast<microseconds>(time1 - time0);
                if (time.count() < resultadosMenor[i][0])
                    resultadosMenor[i][0] = time.count();
                if (time.count() > resultadosMaior[i][0])
                    resultadosMaior[i][0] = time.count();
                resultadosMedia[i][0] += time.count();
                break;
            }
            case (3):
            {
                auto time0 = high_resolution_clock::now();
                shellSort(vetorA, tamanho);
                auto time1 = high_resolution_clock::now();
                auto time = duration_cast<microseconds>(time1 - time0);
                if (time.count() < resultadosMenor[i][0])
                    resultadosMenor[i][0] = time.count();
                if (time.count() > resultadosMaior[i][0])
                    resultadosMaior[i][0] = time.count();
                resultadosMedia[i][0] += time.count();
                break;
            }
            case (4):
            {
                auto time0 = high_resolution_clock::now();
                selectionSort(vetorA, tamanho);
                auto time1 = high_resolution_clock::now();
                auto time = duration_cast<microseconds>(time1 - time0);
                if (time.count() < resultadosMenor[i][0])
                    resultadosMenor[i][0] = time.count();
                if (time.count() > resultadosMaior[i][0])
                    resultadosMaior[i][0] = time.count();
                resultadosMedia[i][0] += time.count();
                break;
            }
            case (5):
            {
                auto time0 = high_resolution_clock::now();
                heapSort(vetorA, tamanho);
                auto time1 = high_resolution_clock::now();
                auto time = duration_cast<microseconds>(time1 - time0);
                if (time.count() < resultadosMenor[i][0])
                    resultadosMenor[i][0] = time.count();
                if (time.count() > resultadosMaior[i][0])
                    resultadosMaior[i][0] = time.count();
                resultadosMedia[i][0] += time.count();
                break;
            }
            case (6):
            {
                auto time0 = high_resolution_clock::now();
                mergeSort(vetorA, tamanho);
                auto time1 = high_resolution_clock::now();
                auto time = duration_cast<microseconds>(time1 - time0);
                if (time.count() < resultadosMenor[i][0])
                    resultadosMenor[i][0] = time.count();
                if (time.count() > resultadosMaior[i][0])
                    resultadosMaior[i][0] = time.count();
                resultadosMedia[i][0] += time.count();
                break;
            }
            case (7):
            {
                auto time0 = high_resolution_clock::now();
                quickSort(vetorA, 0, tamanho, true);
                auto time1 = high_resolution_clock::now();
                auto time = duration_cast<microseconds>(time1 - time0);
                if (time.count() < resultadosMenor[i][0])
                    resultadosMenor[i][0] = time.count();
                if (time.count() > resultadosMaior[i][0])
                    resultadosMaior[i][0] = time.count();
                resultadosMedia[i][0] += time.count();
                break;
            }
            default:
                break;
            }

            tamanho = COUNT_OF(vetorB);
            gerarVetor(vetorB, false, tamanho);
            switch (i)
            {
            case (0):
            {
                auto time0 = high_resolution_clock::now();
                bubbleSortSimples(vetorB, tamanho);
                auto time1 = high_resolution_clock::now();
                auto time = duration_cast<microseconds>(time1 - time0);
                if (time.count() < resultadosMenor[i][1])
                    resultadosMenor[i][1] = time.count();
                if (time.count() > resultadosMaior[i][1])
                    resultadosMaior[i][1] = time.count();
                resultadosMedia[i][1] += time.count();
                break;
            }
            case (1):
            {
                auto time0 = high_resolution_clock::now();
                bubbleSortMelhor(vetorB, tamanho);
                auto time1 = high_resolution_clock::now();
                auto time = duration_cast<microseconds>(time1 - time0);
                if (time.count() < resultadosMenor[i][1])
                    resultadosMenor[i][1] = time.count();
                if (time.count() > resultadosMaior[i][1])
                    resultadosMaior[i][1] = time.count();
                resultadosMedia[i][1] += time.count();
                break;
            }
            case (2):
            {
                auto time0 = high_resolution_clock::now();
                insertionSort(vetorB, tamanho);
                auto time1 = high_resolution_clock::now();
                auto time = duration_cast<microseconds>(time1 - time0);
                if (time.count() < resultadosMenor[i][1])
                    resultadosMenor[i][1] = time.count();
                if (time.count() > resultadosMaior[i][1])
                    resultadosMaior[i][1] = time.count();
                resultadosMedia[i][1] += time.count();
                break;
            }
            case (3):
            {
                auto time0 = high_resolution_clock::now();
                shellSort(vetorB, tamanho);
                auto time1 = high_resolution_clock::now();
                auto time = duration_cast<microseconds>(time1 - time0);
                if (time.count() < resultadosMenor[i][1])
                    resultadosMenor[i][1] = time.count();
                if (time.count() > resultadosMaior[i][1])
                    resultadosMaior[i][1] = time.count();
                resultadosMedia[i][1] += time.count();
                break;
            }
            case (4):
            {
                auto time0 = high_resolution_clock::now();
                selectionSort(vetorB, tamanho);
                auto time1 = high_resolution_clock::now();
                auto time = duration_cast<microseconds>(time1 - time0);
                if (time.count() < resultadosMenor[i][1])
                    resultadosMenor[i][1] = time.count();
                if (time.count() > resultadosMaior[i][1])
                    resultadosMaior[i][1] = time.count();
                resultadosMedia[i][1] += time.count();
                break;
            }
            case (5):
            {
                auto time0 = high_resolution_clock::now();
                heapSort(vetorB, tamanho);
                auto time1 = high_resolution_clock::now();
                auto time = duration_cast<microseconds>(time1 - time0);
                if (time.count() < resultadosMenor[i][1])
                    resultadosMenor[i][1] = time.count();
                if (time.count() > resultadosMaior[i][1])
                    resultadosMaior[i][1] = time.count();
                resultadosMedia[i][1] += time.count();
                break;
            }
            case (6):
            {
                auto time0 = high_resolution_clock::now();
                mergeSort(vetorB, tamanho);
                auto time1 = high_resolution_clock::now();
                auto time = duration_cast<microseconds>(time1 - time0);
                if (time.count() < resultadosMenor[i][1])
                    resultadosMenor[i][1] = time.count();
                if (time.count() > resultadosMaior[i][1])
                    resultadosMaior[i][1] = time.count();
                resultadosMedia[i][1] += time.count();
                break;
            }
            case (7):
            {
                auto time0 = high_resolution_clock::now();
                quickSort(vetorB, 0, tamanho, true);
                auto time1 = high_resolution_clock::now();
                auto time = duration_cast<microseconds>(time1 - time0);
                if (time.count() < resultadosMenor[i][1])
                    resultadosMenor[i][1] = time.count();
                if (time.count() > resultadosMaior[i][1])
                    resultadosMaior[i][1] = time.count();
                resultadosMedia[i][1] += time.count();
                break;
            }
            default:
                break;
            }

            tamanho = COUNT_OF(vetorC);
            gerarVetor(vetorC, false, tamanho);
            switch (i)
            {
            case (0):
            {
                auto time0 = high_resolution_clock::now();
                bubbleSortSimples(vetorC, tamanho);
                auto time1 = high_resolution_clock::now();
                auto time = duration_cast<microseconds>(time1 - time0);
                if (time.count() < resultadosMenor[i][2])
                    resultadosMenor[i][2] = time.count();
                if (time.count() > resultadosMaior[i][2])
                    resultadosMaior[i][2] = time.count();
                resultadosMedia[i][2] += time.count();
                break;
            }
            case (1):
            {
                auto time0 = high_resolution_clock::now();
                bubbleSortMelhor(vetorC, tamanho);
                auto time1 = high_resolution_clock::now();
                auto time = duration_cast<microseconds>(time1 - time0);
                if (time.count() < resultadosMenor[i][2])
                    resultadosMenor[i][2] = time.count();
                if (time.count() > resultadosMaior[i][2])
                    resultadosMaior[i][2] = time.count();
                resultadosMedia[i][2] += time.count();
                break;
            }
            case (2):
            {
                auto time0 = high_resolution_clock::now();
                insertionSort(vetorC, tamanho);
                auto time1 = high_resolution_clock::now();
                auto time = duration_cast<microseconds>(time1 - time0);
                if (time.count() < resultadosMenor[i][2])
                    resultadosMenor[i][2] = time.count();
                if (time.count() > resultadosMaior[i][2])
                    resultadosMaior[i][2] = time.count();
                resultadosMedia[i][2] += time.count();
                break;
            }
            case (3):
            {
                auto time0 = high_resolution_clock::now();
                shellSort(vetorC, tamanho);
                auto time1 = high_resolution_clock::now();
                auto time = duration_cast<microseconds>(time1 - time0);
                if (time.count() < resultadosMenor[i][2])
                    resultadosMenor[i][2] = time.count();
                if (time.count() > resultadosMaior[i][2])
                    resultadosMaior[i][2] = time.count();
                resultadosMedia[i][2] += time.count();
                break;
            }
            case (4):
            {
                auto time0 = high_resolution_clock::now();
                selectionSort(vetorC, tamanho);
                auto time1 = high_resolution_clock::now();
                auto time = duration_cast<microseconds>(time1 - time0);
                if (time.count() < resultadosMenor[i][2])
                    resultadosMenor[i][2] = time.count();
                if (time.count() > resultadosMaior[i][2])
                    resultadosMaior[i][2] = time.count();
                resultadosMedia[i][2] += time.count();
                break;
            }
            case (5):
            {
                auto time0 = high_resolution_clock::now();
                heapSort(vetorC, tamanho);
                auto time1 = high_resolution_clock::now();
                auto time = duration_cast<microseconds>(time1 - time0);
                if (time.count() < resultadosMenor[i][2])
                    resultadosMenor[i][2] = time.count();
                if (time.count() > resultadosMaior[i][2])
                    resultadosMaior[i][2] = time.count();
                resultadosMedia[i][2] += time.count();
                break;
            }
            case (6):
            {
                auto time0 = high_resolution_clock::now();
                mergeSort(vetorC, tamanho);
                auto time1 = high_resolution_clock::now();
                auto time = duration_cast<microseconds>(time1 - time0);
                if (time.count() < resultadosMenor[i][2])
                    resultadosMenor[i][2] = time.count();
                if (time.count() > resultadosMaior[i][2])
                    resultadosMaior[i][2] = time.count();
                resultadosMedia[i][2] += time.count();
                break;
            }
            case (7):
            {
                auto time0 = high_resolution_clock::now();
                quickSort(vetorC, 0, tamanho, true);
                auto time1 = high_resolution_clock::now();
                auto time = duration_cast<microseconds>(time1 - time0);
                if (time.count() < resultadosMenor[i][2])
                    resultadosMenor[i][2] = time.count();
                if (time.count() > resultadosMaior[i][2])
                    resultadosMaior[i][2] = time.count();
                resultadosMedia[i][2] += time.count();
                break;
            }
            default:
                break;
            }
            tamanho = COUNT_OF(vetorA);
            gerarVetor(vetorA, true, tamanho);
            tamanho = COUNT_OF(vetorB);
            gerarVetor(vetorB, true, tamanho);
            tamanho = COUNT_OF(vetorC);
            gerarVetor(vetorC, true, tamanho);
            switch(i){
                case (0):
            {
                tamanho = COUNT_OF(vetorA);
                auto time0 = high_resolution_clock::now();
                bubbleSortSimples(vetorA, tamanho);
                auto time1 = high_resolution_clock::now();
                auto time = duration_cast<microseconds>(time1 - time0);
                resultadoCrescente[i][0]=time.count();
                tamanho = COUNT_OF(vetorB);
                time0 = high_resolution_clock::now();
                bubbleSortSimples(vetorB, tamanho);
                time1 = high_resolution_clock::now();
                time = duration_cast<microseconds>(time1 - time0);
                resultadoCrescente[i][1]=time.count();
                tamanho = COUNT_OF(vetorC);
                time0 = high_resolution_clock::now();
                bubbleSortSimples(vetorC, tamanho);
                time1 = high_resolution_clock::now();
                time = duration_cast<microseconds>(time1 - time0);
                resultadoCrescente[i][2]=time.count();
                break;
            }
            case (1):
            {
                tamanho = COUNT_OF(vetorA);
                auto time0 = high_resolution_clock::now();
                bubbleSortMelhor(vetorA, tamanho);
                auto time1 = high_resolution_clock::now();
                auto time = duration_cast<microseconds>(time1 - time0);
                resultadoCrescente[i][0]=time.count();
                tamanho = COUNT_OF(vetorB);
                time0 = high_resolution_clock::now();
                bubbleSortMelhor(vetorB, tamanho);
                time1 = high_resolution_clock::now();
                time = duration_cast<microseconds>(time1 - time0);
                resultadoCrescente[i][1]=time.count();
                tamanho = COUNT_OF(vetorC);
                time0 = high_resolution_clock::now();
                bubbleSortMelhor(vetorC, tamanho);
                time1 = high_resolution_clock::now();
                time = duration_cast<microseconds>(time1 - time0);
                resultadoCrescente[i][2]=time.count();
                break;
            }
            case (2):
            {
                tamanho = COUNT_OF(vetorA);
                auto time0 = high_resolution_clock::now();
                insertionSort(vetorA, tamanho);
                auto time1 = high_resolution_clock::now();
                auto time = duration_cast<microseconds>(time1 - time0);
                resultadoCrescente[i][0]=time.count();
                tamanho = COUNT_OF(vetorB);
                time0 = high_resolution_clock::now();
                insertionSort(vetorB, tamanho);
                time1 = high_resolution_clock::now();
                time = duration_cast<microseconds>(time1 - time0);
                resultadoCrescente[i][1]=time.count();
                tamanho = COUNT_OF(vetorC);
                time0 = high_resolution_clock::now();
                insertionSort(vetorC, tamanho);
                time1 = high_resolution_clock::now();
                time = duration_cast<microseconds>(time1 - time0);
                resultadoCrescente[i][2]=time.count();
                break;
            }
            case (3):
            {
                 tamanho = COUNT_OF(vetorA);
                auto time0 = high_resolution_clock::now();
                shellSort(vetorA, tamanho);
                auto time1 = high_resolution_clock::now();
                auto time = duration_cast<microseconds>(time1 - time0);
                resultadoCrescente[i][0]=time.count();
                tamanho = COUNT_OF(vetorB);
                time0 = high_resolution_clock::now();
                shellSort(vetorB, tamanho);
                time1 = high_resolution_clock::now();
                time = duration_cast<microseconds>(time1 - time0);
                resultadoCrescente[i][1]=time.count();
                tamanho = COUNT_OF(vetorC);
                time0 = high_resolution_clock::now();
                shellSort(vetorC, tamanho);
                time1 = high_resolution_clock::now();
                time = duration_cast<microseconds>(time1 - time0);
                resultadoCrescente[i][2]=time.count();
                break;
            }
            case (4):
            {
                tamanho = COUNT_OF(vetorA);
                auto time0 = high_resolution_clock::now();
                selectionSort(vetorA, tamanho);
                auto time1 = high_resolution_clock::now();
                auto time = duration_cast<microseconds>(time1 - time0);
                resultadoCrescente[i][0]=time.count();
                tamanho = COUNT_OF(vetorB);
                time0 = high_resolution_clock::now();
                selectionSort(vetorB, tamanho);
                time1 = high_resolution_clock::now();
                time = duration_cast<microseconds>(time1 - time0);
                resultadoCrescente[i][1]=time.count();
                tamanho = COUNT_OF(vetorC);
                time0 = high_resolution_clock::now();
                selectionSort(vetorC, tamanho);
                time1 = high_resolution_clock::now();
                time = duration_cast<microseconds>(time1 - time0);
                resultadoCrescente[i][2]=time.count();
                break;
            }
            case (5):
            {
                tamanho = COUNT_OF(vetorA);
                auto time0 = high_resolution_clock::now();
                heapSort(vetorA, tamanho);
                auto time1 = high_resolution_clock::now();
                auto time = duration_cast<microseconds>(time1 - time0);
                resultadoCrescente[i][0]=time.count();
                tamanho = COUNT_OF(vetorB);
                time0 = high_resolution_clock::now();
                heapSort(vetorB, tamanho);
                time1 = high_resolution_clock::now();
                time = duration_cast<microseconds>(time1 - time0);
                resultadoCrescente[i][1]=time.count();
                tamanho = COUNT_OF(vetorC);
                time0 = high_resolution_clock::now();
                heapSort(vetorC, tamanho);
                time1 = high_resolution_clock::now();
                time = duration_cast<microseconds>(time1 - time0);
                resultadoCrescente[i][2]=time.count();
                break;
            }
            case (6):
            {
                tamanho = COUNT_OF(vetorA);
                auto time0 = high_resolution_clock::now();
                mergeSort(vetorA, tamanho);
                auto time1 = high_resolution_clock::now();
                auto time = duration_cast<microseconds>(time1 - time0);
                resultadoCrescente[i][0]=time.count();
                tamanho = COUNT_OF(vetorB);
                time0 = high_resolution_clock::now();
                mergeSort(vetorB, tamanho);
                time1 = high_resolution_clock::now();
                time = duration_cast<microseconds>(time1 - time0);
                resultadoCrescente[i][1]=time.count();
                tamanho = COUNT_OF(vetorC);
                time0 = high_resolution_clock::now();
                mergeSort(vetorC, tamanho);
                time1 = high_resolution_clock::now();
                time = duration_cast<microseconds>(time1 - time0);
                resultadoCrescente[i][2]=time.count();
                break;
            }
            case (7):
            {
                tamanho = COUNT_OF(vetorA);
                auto time0 = high_resolution_clock::now();
                quickSort(vetorA, 0, tamanho, true);
                auto time1 = high_resolution_clock::now();
                auto time = duration_cast<microseconds>(time1 - time0);
                resultadoCrescente[i][0]=time.count();
                tamanho = COUNT_OF(vetorB);
                time0 = high_resolution_clock::now();
                quickSort(vetorB, 0, tamanho, true);
                time1 = high_resolution_clock::now();
                time = duration_cast<microseconds>(time1 - time0);
                resultadoCrescente[i][1]=time.count();
                tamanho = COUNT_OF(vetorC);
                time0 = high_resolution_clock::now();
                quickSort(vetorC, 0, tamanho, true);
                time1 = high_resolution_clock::now();
                time = duration_cast<microseconds>(time1 - time0);
                resultadoCrescente[i][2]=time.count();
                break;
            }
            default:
                break;
            }
            tamanho = COUNT_OF(vetorA);
            inverte(vetorA, tamanho);
            tamanho = COUNT_OF(vetorB);
            inverte(vetorB, tamanho);
            tamanho = COUNT_OF(vetorC);
            inverte(vetorC, tamanho);
            switch(i){
                case (0):
            {
                tamanho = COUNT_OF(vetorA);
                auto time0 = high_resolution_clock::now();
                bubbleSortSimples(vetorA, tamanho);
                auto time1 = high_resolution_clock::now();
                auto time = duration_cast<microseconds>(time1 - time0);
                resultadoDecrescente[i][0]=time.count();
                tamanho = COUNT_OF(vetorB);
                time0 = high_resolution_clock::now();
                bubbleSortSimples(vetorB, tamanho);
                time1 = high_resolution_clock::now();
                time = duration_cast<microseconds>(time1 - time0);
                resultadoDecrescente[i][1]=time.count();
                tamanho = COUNT_OF(vetorC);
                time0 = high_resolution_clock::now();
                bubbleSortSimples(vetorC, tamanho);
                time1 = high_resolution_clock::now();
                time = duration_cast<microseconds>(time1 - time0);
                resultadoDecrescente[i][2]=time.count();
                break;
            }
            case (1):
            {
                tamanho = COUNT_OF(vetorA);
                auto time0 = high_resolution_clock::now();
                bubbleSortMelhor(vetorA, tamanho);
                auto time1 = high_resolution_clock::now();
                auto time = duration_cast<microseconds>(time1 - time0);
                resultadoDecrescente[i][0]=time.count();
                tamanho = COUNT_OF(vetorB);
                time0 = high_resolution_clock::now();
                bubbleSortMelhor(vetorB, tamanho);
                time1 = high_resolution_clock::now();
                time = duration_cast<microseconds>(time1 - time0);
                resultadoDecrescente[i][1]=time.count();
                tamanho = COUNT_OF(vetorC);
                time0 = high_resolution_clock::now();
                bubbleSortMelhor(vetorC, tamanho);
                time1 = high_resolution_clock::now();
                time = duration_cast<microseconds>(time1 - time0);
                resultadoDecrescente[i][2]=time.count();
                break;
            }
            case (2):
            {
                tamanho = COUNT_OF(vetorA);
                auto time0 = high_resolution_clock::now();
                insertionSort(vetorA, tamanho);
                auto time1 = high_resolution_clock::now();
                auto time = duration_cast<microseconds>(time1 - time0);
                resultadoDecrescente[i][0]=time.count();
                tamanho = COUNT_OF(vetorB);
                time0 = high_resolution_clock::now();
                insertionSort(vetorB, tamanho);
                time1 = high_resolution_clock::now();
                time = duration_cast<microseconds>(time1 - time0);
                resultadoDecrescente[i][1]=time.count();
                tamanho = COUNT_OF(vetorC);
                time0 = high_resolution_clock::now();
                insertionSort(vetorC, tamanho);
                time1 = high_resolution_clock::now();
                time = duration_cast<microseconds>(time1 - time0);
                resultadoDecrescente[i][2]=time.count();
                break;
            }
            case (3):
            {
                 tamanho = COUNT_OF(vetorA);
                auto time0 = high_resolution_clock::now();
                shellSort(vetorA, tamanho);
                auto time1 = high_resolution_clock::now();
                auto time = duration_cast<microseconds>(time1 - time0);
                resultadoDecrescente[i][0]=time.count();
                tamanho = COUNT_OF(vetorB);
                time0 = high_resolution_clock::now();
                shellSort(vetorB, tamanho);
                time1 = high_resolution_clock::now();
                time = duration_cast<microseconds>(time1 - time0);
                resultadoDecrescente[i][1]=time.count();
                tamanho = COUNT_OF(vetorC);
                time0 = high_resolution_clock::now();
                shellSort(vetorC, tamanho);
                time1 = high_resolution_clock::now();
                time = duration_cast<microseconds>(time1 - time0);
                resultadoDecrescente[i][2]=time.count();
                break;
            }
            case (4):
            {
                tamanho = COUNT_OF(vetorA);
                auto time0 = high_resolution_clock::now();
                selectionSort(vetorA, tamanho);
                auto time1 = high_resolution_clock::now();
                auto time = duration_cast<microseconds>(time1 - time0);
                resultadoDecrescente[i][0]=time.count();
                tamanho = COUNT_OF(vetorB);
                time0 = high_resolution_clock::now();
                selectionSort(vetorB, tamanho);
                time1 = high_resolution_clock::now();
                time = duration_cast<microseconds>(time1 - time0);
                resultadoDecrescente[i][1]=time.count();
                tamanho = COUNT_OF(vetorC);
                time0 = high_resolution_clock::now();
                selectionSort(vetorC, tamanho);
                time1 = high_resolution_clock::now();
                time = duration_cast<microseconds>(time1 - time0);
                resultadoDecrescente[i][2]=time.count();
                break;
            }
            case (5):
            {
                tamanho = COUNT_OF(vetorA);
                auto time0 = high_resolution_clock::now();
                heapSort(vetorA, tamanho);
                auto time1 = high_resolution_clock::now();
                auto time = duration_cast<microseconds>(time1 - time0);
                resultadoDecrescente[i][0]=time.count();
                tamanho = COUNT_OF(vetorB);
                time0 = high_resolution_clock::now();
                heapSort(vetorB, tamanho);
                time1 = high_resolution_clock::now();
                time = duration_cast<microseconds>(time1 - time0);
                resultadoDecrescente[i][1]=time.count();
                tamanho = COUNT_OF(vetorC);
                time0 = high_resolution_clock::now();
                heapSort(vetorC, tamanho);
                time1 = high_resolution_clock::now();
                time = duration_cast<microseconds>(time1 - time0);
                resultadoDecrescente[i][2]=time.count();
                break;
            }
            case (6):
            {
                tamanho = COUNT_OF(vetorA);
                auto time0 = high_resolution_clock::now();
                mergeSort(vetorA, tamanho);
                auto time1 = high_resolution_clock::now();
                auto time = duration_cast<microseconds>(time1 - time0);
                resultadoDecrescente[i][0]=time.count();
                tamanho = COUNT_OF(vetorB);
                time0 = high_resolution_clock::now();
                mergeSort(vetorB, tamanho);
                time1 = high_resolution_clock::now();
                time = duration_cast<microseconds>(time1 - time0);
                resultadoDecrescente[i][1]=time.count();
                tamanho = COUNT_OF(vetorC);
                time0 = high_resolution_clock::now();
                mergeSort(vetorC, tamanho);
                time1 = high_resolution_clock::now();
                time = duration_cast<microseconds>(time1 - time0);
                resultadoDecrescente[i][2]=time.count();
                break;
            }
            case (7):
            {
                tamanho = COUNT_OF(vetorA);
                auto time0 = high_resolution_clock::now();
                quickSort(vetorA, 0, tamanho, true);
                auto time1 = high_resolution_clock::now();
                auto time = duration_cast<microseconds>(time1 - time0);
                resultadoDecrescente[i][0]=time.count();
                tamanho = COUNT_OF(vetorB);
                time0 = high_resolution_clock::now();
                quickSort(vetorB, 0, tamanho, true);
                time1 = high_resolution_clock::now();
                time = duration_cast<microseconds>(time1 - time0);
                resultadoDecrescente[i][1]=time.count();
                tamanho = COUNT_OF(vetorC);
                time0 = high_resolution_clock::now();
                quickSort(vetorC, 0, tamanho, true);
                time1 = high_resolution_clock::now();
                time = duration_cast<microseconds>(time1 - time0);
                resultadoDecrescente[i][2]=time.count();
                break;
            }
            default:
                break;
            }
        }
    }
    file << "0 - Bubble Sort Simples" << endl
         << "1 - Bubble Sort Melhor" << endl
         << "2 - Insertion Sort" << endl
         << "3 - Shell Sort" << endl
         << "4 - Selection Sort" << endl
         << "5 - Heap Sort" << endl
         << "6 - Merge Sort" << endl
         << "7 - Quick Sort" << endl
         << endl;
    file << endl
         << "Tempo de dez execuções em microsegundos:" << endl;
    file << "      VetorA    VetorB    VetorC" << endl;
    for (int i = 0; i < 8; i++)
    {
        file << i << " -";
        for (int j = 0; j < 3; j++)
        {
            file.width(9);
            file << resultadosMedia[i][j] << " ";
            if (j == 2)
            {
                file << endl;
            }
        }
    }

    for (int i = 0; i < 8; i++) // Calcular média
    {
        for (int j = 0; j < 3; j++)
        {
            resultadosMedia[i][j] /= N_AMOSTRAS;
        }
    }

    file << endl << "média de tempo em microsegundos:" << endl;
    file << "      VetorA    VetorB    VetorC" << endl;
    for (int i = 0; i < 8; i++)
    {
        file << i << " -";
        for (int j = 0; j < 3; j++)
        {
            file.width(9);
            file << resultadosMedia[i][j] << " ";
            if (j == 2)
            {
                file << endl;
            }
        }
    }

    file << endl
         << "maior tempo em microsegundos:" << endl;
    file << "      VetorA    VetorB    VetorC" << endl;
    for (int i = 0; i < 8; i++)
    {
        file << i << " -";
        for (int j = 0; j < 3; j++)
        {
            file.width(9);
            file << resultadosMaior[i][j] << " ";
            if (j == 2)
            {
                file << endl;
            }
        }
    }

    file << endl
         << "menor tempo em microsegundos:" << endl;
    file << "      VetorA    VetorB    VetorC" << endl;
    for (int i = 0; i < 8; i++)
    {
        file << i << " -";
        for (int j = 0; j < 3; j++)
        {
            file.width(9);
            file << resultadosMenor[i][j] << " ";
            if (j == 2)
            {
                file << endl;
            }
        }
    }
     file << endl
         << "Tempo Ordenação vetor em ordem crescente:" << endl;
    file << "      VetorA    VetorB    VetorC" << endl;
    for (int i = 0; i < 8; i++)
    {
        file << i << " -";
        for (int j = 0; j < 3; j++)
        {
            file.width(9);
            file << resultadoCrescente[i][j] << " ";
            if (j == 2)
            {
                file << endl;
            }
        }
    }
     file << endl
         << "Tempo Ordenação vetor em ordem decrescente:" << endl;
    file << "      VetorA    VetorB    VetorC" << endl;
    for (int i = 0; i < 8; i++)
    {
        file << i << " -";
        for (int j = 0; j < 3; j++)
        {
            file.width(9);
            file << resultadoDecrescente[i][j] << " ";
            if (j == 2)
            {
                file << endl;
            }
        }
    }
    

    file.close();
    std::cout << "Execução concluída." << endl;
    return 0;
}
