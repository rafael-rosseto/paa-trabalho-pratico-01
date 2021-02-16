#ifndef VETOR_H
#define VETOR_H

#include <cstdlib>
#include <iostream>
#include <ctime>

#define COUNT_OF(x) ((sizeof(x) / sizeof(0 [x])) / ((size_t)(!(sizeof(x) % sizeof(0 [x])))))

void gerarVetor(int vetor[], bool ordenado, int size)
{
    if (ordenado)
    {
        for (int i = 0; i < size; i++)
        {
            vetor[i] = i + 1;
        }
    }
    else
    {
        srand(time(0));
        for (int i = 0; i < size; i++)
        {
            vetor[i] = rand() % 99999 + 1;
        }
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