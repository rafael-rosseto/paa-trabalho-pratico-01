#ifndef VETOR_H
#define VETOR_H

#define COUNT_OF(x) ((sizeof(x) / sizeof(0 [x])) / ((size_t)(!(sizeof(x) % sizeof(0 [x])))))

#include <cstdlib>
#include <iostream>
#include <ctime>

void gerarVetorOrdenado(int vetor[], int size)
{
    for (int i = 0; i < size; i++)
    {
        vetor[i] = i + 1;
    }
}

void gerarVetorAleatorio(int vetor[], int size)
{
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        vetor[i] = rand();
    }
}

void imprimirVetor(int vetor[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << vetor[i] << std::endl;
    }
}

#endif /* VETOR_H */