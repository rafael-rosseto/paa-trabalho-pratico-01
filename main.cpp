#include <cstdlib>
#include <iostream>
#include <fstream>
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
#define N_amostras 10

int main()
{
    int maior, menor, media;
    ofstream logfile;
    logfile.open("analize.txt");

    // Bubble sort simples
    logfile << "Bubble Sort Simples:" << endl;
    // Vetor A
    maior = 0;
    menor = 0xFFFFFF;
    media = 0;

    for (int i = 0; i < N_amostras; i++)
    {
        gerarVetor(vetorA, false, COUNT_OF(vetorA));
        auto time0 = high_resolution_clock::now();
        bubbleSimples(vetorA);
        auto time1 = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(time1 - time0);

        if (time.count() < menor)
            menor = time.count();
        if (time.count() > maior)
            maior = time.count();
        media += time.count();

        //logfile << "Tempo de ordenação: " << time.count() << " microsegundos." << endl;
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

    for (int i = 0; i < N_amostras; i++)
    {
        gerarVetor(vetorB, false, COUNT_OF(vetorB));
        auto time0 = high_resolution_clock::now();
        bubbleSimples(vetorB);
        auto time1 = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(time1 - time0);

        if (time.count() < menor)
            menor = time.count();
        if (time.count() > maior)
            maior = time.count();
        media += time.count();

        //logfile << "Tempo de ordenação: " << time.count() << " microsegundos." << endl;
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

    for (int i = 0; i < N_amostras; i++)
    {
        gerarVetor(vetorC, false, COUNT_OF(vetorC));
        auto time0 = high_resolution_clock::now();
        bubbleSimples(vetorC);
        auto time1 = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(time1 - time0);

        if (time.count() < menor)
            menor = time.count();
        if (time.count() > maior)
            maior = time.count();
        media += time.count();

        //logfile << "Tempo de ordenação: " << time.count() << " microsegundos." << endl;
    }
    media /= N_amostras;
    logfile << "VetorC:" << endl;
    logfile << "menor tempo: " << menor << endl;
    logfile << "maior tempo: " << maior << endl;
    logfile << "media: " << media << endl
            << endl;

    // Bubble sort melhor
    logfile << "Bubble Sort Melhor:" << endl;
    // Vetor A
    maior = 0;
    menor = 0xFFFFFF;
    media = 0;

    for (int i = 0; i < N_amostras; i++)
    {
        gerarVetor(vetorA, false, COUNT_OF(vetorA));
        auto time0 = high_resolution_clock::now();
        bubbleMelhor(vetorA);
        auto time1 = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(time1 - time0);

        if (time.count() < menor)
            menor = time.count();
        if (time.count() > maior)
            maior = time.count();
        media += time.count();

        //logfile << "Tempo de ordenação: " << time.count() << " microsegundos." << endl;
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

    for (int i = 0; i < N_amostras; i++)
    {
        gerarVetor(vetorB, false, COUNT_OF(vetorB));
        auto time0 = high_resolution_clock::now();
        bubbleMelhor(vetorB);
        auto time1 = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(time1 - time0);

        if (time.count() < menor)
            menor = time.count();
        if (time.count() > maior)
            maior = time.count();
        media += time.count();

        //logfile << "Tempo de ordenação: " << time.count() << " microsegundos." << endl;
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

    for (int i = 0; i < N_amostras; i++)
    {
        gerarVetor(vetorC, false, COUNT_OF(vetorC));
        auto time0 = high_resolution_clock::now();
        bubbleMelhor(vetorC);
        auto time1 = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(time1 - time0);

        if (time.count() < menor)
            menor = time.count();
        if (time.count() > maior)
            maior = time.count();
        media += time.count();

        //logfile << "Tempo de ordenação: " << time.count() << " microsegundos." << endl;
    }
    media /= N_amostras;
    logfile << "VetorC:" << endl;
    logfile << "menor tempo: " << menor << endl;
    logfile << "maior tempo: " << maior << endl;
    logfile << "media: " << media << endl
            << endl;

    // Quick Sort
    logfile << "Quick Sort:" << endl;
    // Vetor A
    maior = 0;
    menor = 0xFFFFFF;
    media = 0;

    for (int i = 0; i < N_amostras; i++)
    {
        gerarVetor(vetorA, false, COUNT_OF(vetorA));
        auto time0 = high_resolution_clock::now();
        quick(vetorA);
        auto time1 = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(time1 - time0);

        if (time.count() < menor)
            menor = time.count();
        if (time.count() > maior)
            maior = time.count();
        media += time.count();

        //logfile << "Tempo de ordenação: " << time.count() << " microsegundos." << endl;
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

    for (int i = 0; i < N_amostras; i++)
    {
        gerarVetor(vetorB, false, COUNT_OF(vetorB));
        auto time0 = high_resolution_clock::now();
        quick(vetorB);
        auto time1 = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(time1 - time0);

        if (time.count() < menor)
            menor = time.count();
        if (time.count() > maior)
            maior = time.count();
        media += time.count();

        //logfile << "Tempo de ordenação: " << time.count() << " microsegundos." << endl;
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

    for (int i = 0; i < N_amostras; i++)
    {
        gerarVetor(vetorC, false, COUNT_OF(vetorC));
        auto time0 = high_resolution_clock::now();
        quick(vetorC);
        auto time1 = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(time1 - time0);

        if (time.count() < menor)
            menor = time.count();
        if (time.count() > maior)
            maior = time.count();
        media += time.count();

        //logfile << "Tempo de ordenação: " << time.count() << " microsegundos." << endl;
    }
    media /= N_amostras;
    logfile << "VetorC:" << endl;
    logfile << "menor tempo: " << menor << endl;
    logfile << "maior tempo: " << maior << endl;
    logfile << "media: " << media << endl
            << endl;

    // Insertion Sort
    logfile << "Insertion Sort:" << endl;
    // Vetor A
    maior = 0;
    menor = 0xFFFFFF;
    media = 0;

    for (int i = 0; i < N_amostras; i++)
    {
        gerarVetor(vetorA, false, COUNT_OF(vetorA));
        auto time0 = high_resolution_clock::now();
        insertion(vetorA);
        auto time1 = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(time1 - time0);

        if (time.count() < menor)
            menor = time.count();
        if (time.count() > maior)
            maior = time.count();
        media += time.count();

        //logfile << "Tempo de ordenação: " << time.count() << " microsegundos." << endl;
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

    for (int i = 0; i < N_amostras; i++)
    {
        gerarVetor(vetorB, false, COUNT_OF(vetorB));
        auto time0 = high_resolution_clock::now();
        insertion(vetorB);
        auto time1 = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(time1 - time0);

        if (time.count() < menor)
            menor = time.count();
        if (time.count() > maior)
            maior = time.count();
        media += time.count();

        //logfile << "Tempo de ordenação: " << time.count() << " microsegundos." << endl;
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

    for (int i = 0; i < N_amostras; i++)
    {
        gerarVetor(vetorC, false, COUNT_OF(vetorC));
        auto time0 = high_resolution_clock::now();
        insertion(vetorC);
        auto time1 = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(time1 - time0);

        if (time.count() < menor)
            menor = time.count();
        if (time.count() > maior)
            maior = time.count();
        media += time.count();

        //logfile << "Tempo de ordenação: " << time.count() << " microsegundos." << endl;
    }
    media /= N_amostras;
    logfile << "VetorC:" << endl;
    logfile << "menor tempo: " << menor << endl;
    logfile << "maior tempo: " << maior << endl;
    logfile << "media: " << media << endl
            << endl;

    // Shell Sort
    logfile << "Shell Sort:" << endl;
    // Vetor A
    maior = 0;
    menor = 0xFFFFFF;
    media = 0;

    for (int i = 0; i < N_amostras; i++)
    {
        gerarVetor(vetorA, false, COUNT_OF(vetorA));
        auto time0 = high_resolution_clock::now();
        shell(vetorA);
        auto time1 = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(time1 - time0);

        if (time.count() < menor)
            menor = time.count();
        if (time.count() > maior)
            maior = time.count();
        media += time.count();

        //logfile << "Tempo de ordenação: " << time.count() << " microsegundos." << endl;
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

    for (int i = 0; i < N_amostras; i++)
    {
        gerarVetor(vetorB, false, COUNT_OF(vetorB));
        auto time0 = high_resolution_clock::now();
        shell(vetorB);
        auto time1 = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(time1 - time0);

        if (time.count() < menor)
            menor = time.count();
        if (time.count() > maior)
            maior = time.count();
        media += time.count();

        //logfile << "Tempo de ordenação: " << time.count() << " microsegundos." << endl;
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

    for (int i = 0; i < N_amostras; i++)
    {
        gerarVetor(vetorC, false, COUNT_OF(vetorC));
        auto time0 = high_resolution_clock::now();
        shell(vetorC);
        auto time1 = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(time1 - time0);

        if (time.count() < menor)
            menor = time.count();
        if (time.count() > maior)
            maior = time.count();
        media += time.count();

        //logfile << "Tempo de ordenação: " << time.count() << " microsegundos." << endl;
    }
    media /= N_amostras;
    logfile << "VetorC:" << endl;
    logfile << "menor tempo: " << menor << endl;
    logfile << "maior tempo: " << maior << endl;
    logfile << "media: " << media << endl
            << endl;

    // Selection Sort
    logfile << "Selection Sort:" << endl;
    // Vetor A
    maior = 0;
    menor = 0xFFFFFF;
    media = 0;

    for (int i = 0; i < N_amostras; i++)
    {
        gerarVetor(vetorA, false, COUNT_OF(vetorA));
        auto time0 = high_resolution_clock::now();
        selection(vetorA);
        auto time1 = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(time1 - time0);

        if (time.count() < menor)
            menor = time.count();
        if (time.count() > maior)
            maior = time.count();
        media += time.count();

        //logfile << "Tempo de ordenação: " << time.count() << " microsegundos." << endl;
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

    for (int i = 0; i < N_amostras; i++)
    {
        gerarVetor(vetorB, false, COUNT_OF(vetorB));
        auto time0 = high_resolution_clock::now();
        selection(vetorB);
        auto time1 = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(time1 - time0);

        if (time.count() < menor)
            menor = time.count();
        if (time.count() > maior)
            maior = time.count();
        media += time.count();

        //logfile << "Tempo de ordenação: " << time.count() << " microsegundos." << endl;
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

    for (int i = 0; i < N_amostras; i++)
    {
        gerarVetor(vetorC, false, COUNT_OF(vetorC));
        auto time0 = high_resolution_clock::now();
        selection(vetorC);
        auto time1 = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(time1 - time0);

        if (time.count() < menor)
            menor = time.count();
        if (time.count() > maior)
            maior = time.count();
        media += time.count();

        //logfile << "Tempo de ordenação: " << time.count() << " microsegundos." << endl;
    }
    media /= N_amostras;
    logfile << "VetorC:" << endl;
    logfile << "menor tempo: " << menor << endl;
    logfile << "maior tempo: " << maior << endl;
    logfile << "media: " << media << endl
            << endl;

    // Merge Sort
    logfile << "Merge Sort:" << endl;
    // Vetor A
    maior = 0;
    menor = 0xFFFFFF;
    media = 0;

    for (int i = 0; i < N_amostras; i++)
    {
        gerarVetor(vetorA, false, COUNT_OF(vetorA));
        auto time0 = high_resolution_clock::now();
        merge(vetorA);
        auto time1 = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(time1 - time0);

        if (time.count() < menor)
            menor = time.count();
        if (time.count() > maior)
            maior = time.count();
        media += time.count();

        //logfile << "Tempo de ordenação: " << time.count() << " microsegundos." << endl;
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

    for (int i = 0; i < N_amostras; i++)
    {
        gerarVetor(vetorB, false, COUNT_OF(vetorB));
        auto time0 = high_resolution_clock::now();
        merge(vetorB);
        auto time1 = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(time1 - time0);

        if (time.count() < menor)
            menor = time.count();
        if (time.count() > maior)
            maior = time.count();
        media += time.count();

        //logfile << "Tempo de ordenação: " << time.count() << " microsegundos." << endl;
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

    for (int i = 0; i < N_amostras; i++)
    {
        gerarVetor(vetorC, false, COUNT_OF(vetorC));
        auto time0 = high_resolution_clock::now();
        merge(vetorC);
        auto time1 = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(time1 - time0);

        if (time.count() < menor)
            menor = time.count();
        if (time.count() > maior)
            maior = time.count();
        media += time.count();

        //logfile << "Tempo de ordenação: " << time.count() << " microsegundos." << endl;
    }
    media /= N_amostras;
    logfile << "VetorC:" << endl;
    logfile << "menor tempo: " << menor << endl;
    logfile << "maior tempo: " << maior << endl;
    logfile << "media: " << media << endl
            << endl;

    // Heap Sort
    logfile << "Heap Sort:" << endl;
    // Vetor A
    maior = 0;
    menor = 0xFFFFFF;
    media = 0;

    for (int i = 0; i < N_amostras; i++)
    {
        gerarVetor(vetorA, false, COUNT_OF(vetorA));
        auto time0 = high_resolution_clock::now();
        heap(vetorA);
        auto time1 = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(time1 - time0);

        if (time.count() < menor)
            menor = time.count();
        if (time.count() > maior)
            maior = time.count();
        media += time.count();

        //logfile << "Tempo de ordenação: " << time.count() << " microsegundos." << endl;
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

    for (int i = 0; i < N_amostras; i++)
    {
        gerarVetor(vetorB, false, COUNT_OF(vetorB));
        auto time0 = high_resolution_clock::now();
        heap(vetorB);
        auto time1 = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(time1 - time0);

        if (time.count() < menor)
            menor = time.count();
        if (time.count() > maior)
            maior = time.count();
        media += time.count();

        //logfile << "Tempo de ordenação: " << time.count() << " microsegundos." << endl;
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

    for (int i = 0; i < N_amostras; i++)
    {
        gerarVetor(vetorC, false, COUNT_OF(vetorC));
        auto time0 = high_resolution_clock::now();
        heap(vetorC);
        auto time1 = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(time1 - time0);

        if (time.count() < menor)
            menor = time.count();
        if (time.count() > maior)
            maior = time.count();
        media += time.count();

        //logfile << "Tempo de ordenação: " << time.count() << " microsegundos." << endl;
    }
    media /= N_amostras;
    logfile << "VetorC:" << endl;
    logfile << "menor tempo: " << menor << endl;
    logfile << "maior tempo: " << maior << endl;
    logfile << "media: " << media << endl
            << endl;

    logfile.close();
    return 0;
}