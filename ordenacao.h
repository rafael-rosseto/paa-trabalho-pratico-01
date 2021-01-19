#ifndef ORDENACAO_H
#define ORDENACAO_H

void troca(int *x, int *y)
{
    int aux = *x;
    *x = *y;
    *y = aux;
}

void bubbleSortSimples(int array[], int size)
{
    int i, j;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                troca(&array[j], &array[j + 1]);
            }
        }
    }
}

void bubbleSortMelhor(int array[], int size)
{
    int i, j;
    bool trocado;
    for (i = 0; i < size - 1; i++)
    {
        trocado = false;
        for (j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                troca(&array[j], &array[j + 1]);
                trocado = true;
            }
        }
        if (trocado == false)
        {
            break;
        }
    }
}

void quickSortPrimeiro(int array[])
{
}

void quickSortCentro(int array[])
{
}

void insertionSort(int array[], int size)
{
    int i, j, k;
    for (i = 1; i < size; i++)
    {
        k = array[i];
        for (j = i - 1; j >= 0 && k < array[j]; j--)
        {
            array[j + 1] = array[j];
        }
        array[j + 1] = k;
    }
}

void shellSort(int array[], int size)
{
    for (int meio = size / 2; meio > 0; meio /= 2)
    {
        for (int i = meio; i < size; i += 1)
        {
            int temp = array[i];
            int j;
            for (j = i; j >= meio && array[j - meio] > temp; j -= meio)
                array[j] = array[j - meio];
            array[j] = temp;
        }
    }
}

void selectionSort(int array[], int size)
{
    int i, j, minimo;
    for (i = 0; i < size - 1; i++)
    {
        minimo = i;
        for (j = i + 1; j < size; j++)
            if (array[j] < array[minimo])
                minimo = j;
        troca(&array[minimo], &array[i]);
    }
}

void heapSort(int array[])
{
}

void mergeSort(int array[])
{
}

#endif /* ORDENACAO_H */