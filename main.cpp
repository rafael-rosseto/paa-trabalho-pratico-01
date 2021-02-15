#include <cstdlib>
#include <iostream>
#include <fstream>
#include <chrono>
#include "vetor.h"
#include "ordenacao.h"

using namespace std;
using namespace std::chrono;

#define N_amostras 10

int main()
{
    int tamanho, maior, menor, media;
    ofstream logfile;
    logfile.open("analize.txt");
    cout << "Executando cada algoritmo de ordenação " << N_amostras << " vezes, a analize será salva no arquivo análize.txt" << endl;

    /*
     *  Bubble Sort simples
     */
    logfile << "Bubble Sort Simples:" << endl;
    // Vetor A
    maior = 0;
    menor = 0xFFFFFF;
    media = 0;
    tamanho = COUNT_OF(vetorA);

    for (int i = 0; i < N_amostras; i++)
    {
        gerarVetor(vetorA, false, tamanho);
        auto time0 = high_resolution_clock::now();
        bubbleSortSimples(vetorA, tamanho);
        auto time1 = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(time1 - time0);

        if (time.count() < menor)
            menor = time.count();
        if (time.count() > maior)
            maior = time.count();
        media += time.count();
    }
    media /= N_amostras;
    logfile << "VetorA:" << endl;
    logfile << "menor tempo: " << menor << endl;
    logfile << "maior tempo: " << maior << endl;
    logfile << "media: " << media << endl
            << endl;

    //Vetor B
    maior = 0;
    menor = 0xFFFFFF;
    media = 0;
    tamanho = COUNT_OF(vetorB);

    for (int i = 0; i < N_amostras; i++)
    {
        gerarVetor(vetorB, false, tamanho);
        auto time0 = high_resolution_clock::now();
        bubbleSortSimples(vetorB, tamanho);
        auto time1 = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(time1 - time0);

        if (time.count() < menor)
            menor = time.count();
        if (time.count() > maior)
            maior = time.count();
        media += time.count();
    }
    media /= N_amostras;
    logfile << "VetorB:" << endl;
    logfile << "menor tempo: " << menor << endl;
    logfile << "maior tempo: " << maior << endl;
    logfile << "media: " << media << endl
            << endl;

    //Vetor C
    maior = 0;
    menor = 0xFFFFFF;
    media = 0;
    tamanho = COUNT_OF(vetorC);

    for (int i = 0; i < N_amostras; i++)
    {
        gerarVetor(vetorC, false, tamanho);
        auto time0 = high_resolution_clock::now();
        bubbleSortSimples(vetorC, tamanho);
        auto time1 = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(time1 - time0);

        if (time.count() < menor)
            menor = time.count();
        if (time.count() > maior)
            maior = time.count();
        media += time.count();
    }
    media /= N_amostras;
    logfile << "VetorC:" << endl;
    logfile << "menor tempo: " << menor << endl;
    logfile << "maior tempo: " << maior << endl;
    logfile << "media: " << media << endl
            << endl;

    /*
     *  Bubble Sort melhor
     */
    logfile << "Bubble Sort Melhor:" << endl;
    // Vetor A
    maior = 0;
    menor = 0xFFFFFF;
    media = 0;
    tamanho = COUNT_OF(vetorA);

    for (int i = 0; i < N_amostras; i++)
    {
        gerarVetor(vetorA, false, tamanho);
        auto time0 = high_resolution_clock::now();
        bubbleSortMelhor(vetorA, tamanho);
        auto time1 = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(time1 - time0);

        if (time.count() < menor)
            menor = time.count();
        if (time.count() > maior)
            maior = time.count();
        media += time.count();
    }
    media /= N_amostras;
    logfile << "VetorA:" << endl;
    logfile << "menor tempo: " << menor << endl;
    logfile << "maior tempo: " << maior << endl;
    logfile << "media: " << media << endl
            << endl;

    //Vetor B
    maior = 0;
    menor = 0xFFFFFF;
    media = 0;
    tamanho = COUNT_OF(vetorB);

    for (int i = 0; i < N_amostras; i++)
    {
        gerarVetor(vetorB, false, tamanho);
        auto time0 = high_resolution_clock::now();
        bubbleSortMelhor(vetorB, tamanho);
        auto time1 = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(time1 - time0);

        if (time.count() < menor)
            menor = time.count();
        if (time.count() > maior)
            maior = time.count();
        media += time.count();
    }
    media /= N_amostras;
    logfile << "VetorB:" << endl;
    logfile << "menor tempo: " << menor << endl;
    logfile << "maior tempo: " << maior << endl;
    logfile << "media: " << media << endl
            << endl;

    //Vetor C
    maior = 0;
    menor = 0xFFFFFF;
    media = 0;
    tamanho = COUNT_OF(vetorC);

    for (int i = 0; i < N_amostras; i++)
    {
        gerarVetor(vetorC, false, tamanho);
        auto time0 = high_resolution_clock::now();
        bubbleSortMelhor(vetorC, tamanho);
        auto time1 = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(time1 - time0);

        if (time.count() < menor)
            menor = time.count();
        if (time.count() > maior)
            maior = time.count();
        media += time.count();
    }
    media /= N_amostras;
    logfile << "VetorC:" << endl;
    logfile << "menor tempo: " << menor << endl;
    logfile << "maior tempo: " << maior << endl;
    logfile << "media: " << media << endl
            << endl;

    /*
     *  Quick Sort
     */
    logfile << "Quick Sort:" << endl;
    // Vetor A
    maior = 0;
    menor = 0xFFFFFF;
    media = 0;
    tamanho = COUNT_OF(vetorA);

    for (int i = 0; i < N_amostras; i++)
    {
        gerarVetor(vetorA, false, tamanho);
        auto time0 = high_resolution_clock::now();
        quickSort(vetorA, 0, tamanho, true);
        auto time1 = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(time1 - time0);

        if (time.count() < menor)
            menor = time.count();
        if (time.count() > maior)
            maior = time.count();
        media += time.count();
    }
    media /= N_amostras;
    logfile << "VetorA:" << endl;
    logfile << "menor tempo: " << menor << endl;
    logfile << "maior tempo: " << maior << endl;
    logfile << "media: " << media << endl
            << endl;

    //Vetor B
    maior = 0;
    menor = 0xFFFFFF;
    media = 0;
    tamanho = COUNT_OF(vetorB);

    for (int i = 0; i < N_amostras; i++)
    {
        gerarVetor(vetorB, false, tamanho);
        auto time0 = high_resolution_clock::now();
        quickSort(vetorB, 0, tamanho, true);
        auto time1 = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(time1 - time0);

        if (time.count() < menor)
            menor = time.count();
        if (time.count() > maior)
            maior = time.count();
        media += time.count();
    }
    media /= N_amostras;
    logfile << "VetorB:" << endl;
    logfile << "menor tempo: " << menor << endl;
    logfile << "maior tempo: " << maior << endl;
    logfile << "media: " << media << endl
            << endl;

    //Vetor C
    maior = 0;
    menor = 0xFFFFFF;
    media = 0;
    tamanho = COUNT_OF(vetorC);

    for (int i = 0; i < N_amostras; i++)
    {
        gerarVetor(vetorC, false, tamanho);
        auto time0 = high_resolution_clock::now();
        quickSort(vetorC, 0, tamanho, true);
        auto time1 = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(time1 - time0);

        if (time.count() < menor)
            menor = time.count();
        if (time.count() > maior)
            maior = time.count();
        media += time.count();
    }
    media /= N_amostras;
    logfile << "VetorC:" << endl;
    logfile << "menor tempo: " << menor << endl;
    logfile << "maior tempo: " << maior << endl;
    logfile << "media: " << media << endl
            << endl;

    /*
     *  Insertion Sort
     */
    logfile << "Insertion Sort:" << endl;
    // Vetor A
    maior = 0;
    menor = 0xFFFFFF;
    media = 0;
    tamanho = COUNT_OF(vetorA);

    for (int i = 0; i < N_amostras; i++)
    {
        gerarVetor(vetorA, false, tamanho);
        auto time0 = high_resolution_clock::now();
        insertionSort(vetorA, tamanho);
        auto time1 = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(time1 - time0);

        if (time.count() < menor)
            menor = time.count();
        if (time.count() > maior)
            maior = time.count();
        media += time.count();
    }
    media /= N_amostras;
    logfile << "VetorA:" << endl;
    logfile << "menor tempo: " << menor << endl;
    logfile << "maior tempo: " << maior << endl;
    logfile << "media: " << media << endl
            << endl;

    //Vetor B
    maior = 0;
    menor = 0xFFFFFF;
    media = 0;
    tamanho = COUNT_OF(vetorB);

    for (int i = 0; i < N_amostras; i++)
    {
        gerarVetor(vetorB, false, tamanho);
        auto time0 = high_resolution_clock::now();
        insertionSort(vetorB, tamanho);
        auto time1 = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(time1 - time0);

        if (time.count() < menor)
            menor = time.count();
        if (time.count() > maior)
            maior = time.count();
        media += time.count();
    }
    media /= N_amostras;
    logfile << "VetorB:" << endl;
    logfile << "menor tempo: " << menor << endl;
    logfile << "maior tempo: " << maior << endl;
    logfile << "media: " << media << endl
            << endl;

    //Vetor C
    maior = 0;
    menor = 0xFFFFFF;
    media = 0;
    tamanho = COUNT_OF(vetorC);

    for (int i = 0; i < N_amostras; i++)
    {
        gerarVetor(vetorC, false, tamanho);
        auto time0 = high_resolution_clock::now();
        insertionSort(vetorC, tamanho);
        auto time1 = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(time1 - time0);

        if (time.count() < menor)
            menor = time.count();
        if (time.count() > maior)
            maior = time.count();
        media += time.count();
    }
    media /= N_amostras;
    logfile << "VetorC:" << endl;
    logfile << "menor tempo: " << menor << endl;
    logfile << "maior tempo: " << maior << endl;
    logfile << "media: " << media << endl
            << endl;

    /*
     *  Shell Sort
     */
    logfile << "Shell Sort:" << endl;
    // Vetor A
    maior = 0;
    menor = 0xFFFFFF;
    media = 0;
    tamanho = COUNT_OF(vetorA);

    for (int i = 0; i < N_amostras; i++)
    {
        gerarVetor(vetorA, false, tamanho);
        auto time0 = high_resolution_clock::now();
        shellSort(vetorA, tamanho);
        auto time1 = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(time1 - time0);

        if (time.count() < menor)
            menor = time.count();
        if (time.count() > maior)
            maior = time.count();
        media += time.count();
    }
    media /= N_amostras;
    logfile << "VetorA:" << endl;
    logfile << "menor tempo: " << menor << endl;
    logfile << "maior tempo: " << maior << endl;
    logfile << "media: " << media << endl
            << endl;

    //Vetor B
    maior = 0;
    menor = 0xFFFFFF;
    media = 0;
    tamanho = COUNT_OF(vetorB);

    for (int i = 0; i < N_amostras; i++)
    {
        gerarVetor(vetorB, false, tamanho);
        auto time0 = high_resolution_clock::now();
        shellSort(vetorB, tamanho);
        auto time1 = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(time1 - time0);

        if (time.count() < menor)
            menor = time.count();
        if (time.count() > maior)
            maior = time.count();
        media += time.count();
    }
    media /= N_amostras;
    logfile << "VetorB:" << endl;
    logfile << "menor tempo: " << menor << endl;
    logfile << "maior tempo: " << maior << endl;
    logfile << "media: " << media << endl
            << endl;

    //Vetor C
    maior = 0;
    menor = 0xFFFFFF;
    media = 0;
    tamanho = COUNT_OF(vetorC);

    for (int i = 0; i < N_amostras; i++)
    {
        gerarVetor(vetorC, false, tamanho);
        auto time0 = high_resolution_clock::now();
        shellSort(vetorC, tamanho);
        auto time1 = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(time1 - time0);

        if (time.count() < menor)
            menor = time.count();
        if (time.count() > maior)
            maior = time.count();
        media += time.count();
    }
    media /= N_amostras;
    logfile << "VetorC:" << endl;
    logfile << "menor tempo: " << menor << endl;
    logfile << "maior tempo: " << maior << endl;
    logfile << "media: " << media << endl
            << endl;

    /*
     *  Selection Sort
     */
    logfile << "Selection Sort:" << endl;
    // Vetor A
    maior = 0;
    menor = 0xFFFFFF;
    media = 0;
    tamanho = COUNT_OF(vetorA);

    for (int i = 0; i < N_amostras; i++)
    {
        gerarVetor(vetorA, false, tamanho);
        auto time0 = high_resolution_clock::now();
        selectionSort(vetorA, tamanho);
        auto time1 = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(time1 - time0);

        if (time.count() < menor)
            menor = time.count();
        if (time.count() > maior)
            maior = time.count();
        media += time.count();
    }
    media /= N_amostras;
    logfile << "VetorA:" << endl;
    logfile << "menor tempo: " << menor << endl;
    logfile << "maior tempo: " << maior << endl;
    logfile << "media: " << media << endl
            << endl;

    //Vetor B
    maior = 0;
    menor = 0xFFFFFF;
    media = 0;
    tamanho = COUNT_OF(vetorB);

    for (int i = 0; i < N_amostras; i++)
    {
        gerarVetor(vetorB, false, tamanho);
        auto time0 = high_resolution_clock::now();
        selectionSort(vetorB, tamanho);
        auto time1 = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(time1 - time0);

        if (time.count() < menor)
            menor = time.count();
        if (time.count() > maior)
            maior = time.count();
        media += time.count();
    }
    media /= N_amostras;
    logfile << "VetorB:" << endl;
    logfile << "menor tempo: " << menor << endl;
    logfile << "maior tempo: " << maior << endl;
    logfile << "media: " << media << endl
            << endl;

    //Vetor C
    maior = 0;
    menor = 0xFFFFFF;
    media = 0;
    tamanho = COUNT_OF(vetorC);

    for (int i = 0; i < N_amostras; i++)
    {
        gerarVetor(vetorC, false, tamanho);
        auto time0 = high_resolution_clock::now();
        selectionSort(vetorC, tamanho);
        auto time1 = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(time1 - time0);

        if (time.count() < menor)
            menor = time.count();
        if (time.count() > maior)
            maior = time.count();
        media += time.count();
    }
    media /= N_amostras;
    logfile << "VetorC:" << endl;
    logfile << "menor tempo: " << menor << endl;
    logfile << "maior tempo: " << maior << endl;
    logfile << "media: " << media << endl
            << endl;

    /*
     *  Merge Sort
     */
    logfile << "Merge Sort:" << endl;
    // Vetor A
    maior = 0;
    menor = 0xFFFFFF;
    media = 0;
    tamanho = COUNT_OF(vetorA);

    for (int i = 0; i < N_amostras; i++)
    {
        gerarVetor(vetorA, false, tamanho);
        auto time0 = high_resolution_clock::now();
        mergeSort(vetorA, tamanho);
        auto time1 = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(time1 - time0);

        if (time.count() < menor)
            menor = time.count();
        if (time.count() > maior)
            maior = time.count();
        media += time.count();
    }
    media /= N_amostras;
    logfile << "VetorA:" << endl;
    logfile << "menor tempo: " << menor << endl;
    logfile << "maior tempo: " << maior << endl;
    logfile << "media: " << media << endl
            << endl;

    //Vetor B
    maior = 0;
    menor = 0xFFFFFF;
    media = 0;
    tamanho = COUNT_OF(vetorB);

    for (int i = 0; i < N_amostras; i++)
    {
        gerarVetor(vetorB, false, tamanho);
        auto time0 = high_resolution_clock::now();
        mergeSort(vetorB, tamanho);
        auto time1 = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(time1 - time0);

        if (time.count() < menor)
            menor = time.count();
        if (time.count() > maior)
            maior = time.count();
        media += time.count();
    }
    media /= N_amostras;
    logfile << "VetorB:" << endl;
    logfile << "menor tempo: " << menor << endl;
    logfile << "maior tempo: " << maior << endl;
    logfile << "media: " << media << endl
            << endl;

    //Vetor C
    maior = 0;
    menor = 0xFFFFFF;
    media = 0;
    tamanho = COUNT_OF(vetorC);

    for (int i = 0; i < N_amostras; i++)
    {
        gerarVetor(vetorC, false, tamanho);
        auto time0 = high_resolution_clock::now();
        mergeSort(vetorC, tamanho);
        auto time1 = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(time1 - time0);

        if (time.count() < menor)
            menor = time.count();
        if (time.count() > maior)
            maior = time.count();
        media += time.count();
    }
    media /= N_amostras;
    logfile << "VetorC:" << endl;
    logfile << "menor tempo: " << menor << endl;
    logfile << "maior tempo: " << maior << endl;
    logfile << "media: " << media << endl
            << endl;

    /*
     *  Heap Sort
     */
    logfile << "Heap Sort:" << endl;
    // Vetor A
    maior = 0;
    menor = 0xFFFFFF;
    media = 0;
    tamanho = COUNT_OF(vetorA);

    for (int i = 0; i < N_amostras; i++)
    {
        gerarVetor(vetorA, false, tamanho);
        auto time0 = high_resolution_clock::now();
        heapSort(vetorA, tamanho);
        auto time1 = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(time1 - time0);

        if (time.count() < menor)
            menor = time.count();
        if (time.count() > maior)
            maior = time.count();
        media += time.count();
    }
    media /= N_amostras;
    logfile << "VetorA:" << endl;
    logfile << "menor tempo: " << menor << endl;
    logfile << "maior tempo: " << maior << endl;
    logfile << "media: " << media << endl
            << endl;

    //Vetor B
    maior = 0;
    menor = 0xFFFFFF;
    media = 0;
    tamanho = COUNT_OF(vetorB);

    for (int i = 0; i < N_amostras; i++)
    {
        gerarVetor(vetorB, false, tamanho);
        auto time0 = high_resolution_clock::now();
        heapSort(vetorB, tamanho);
        auto time1 = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(time1 - time0);

        if (time.count() < menor)
            menor = time.count();
        if (time.count() > maior)
            maior = time.count();
        media += time.count();
    }
    media /= N_amostras;
    logfile << "VetorB:" << endl;
    logfile << "menor tempo: " << menor << endl;
    logfile << "maior tempo: " << maior << endl;
    logfile << "media: " << media << endl
            << endl;

    //Vetor C
    maior = 0;
    menor = 0xFFFFFF;
    media = 0;
    tamanho = COUNT_OF(vetorC);

    for (int i = 0; i < N_amostras; i++)
    {
        gerarVetor(vetorC, false, COUNT_OF(vetorC));
        auto time0 = high_resolution_clock::now();
        heapSort(vetorC, tamanho);
        auto time1 = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(time1 - time0);

        if (time.count() < menor)
            menor = time.count();
        if (time.count() > maior)
            maior = time.count();
        media += time.count();
    }
    media /= N_amostras;
    logfile << "VetorC:" << endl;
    logfile << "menor tempo: " << menor << endl;
    logfile << "maior tempo: " << maior << endl;
    logfile << "media: " << media << endl
            << endl;

    logfile.close();
    cout << "Execução concluída." << endl;
    return 0;
}