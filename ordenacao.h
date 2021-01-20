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

int pivot(int arr[], int l, int h, bool pivotNoInicio)
{
    if (pivotNoInicio)
    {
        int x = arr[l];
        int i = (h + 1);

        for (int j = h; j >= l+1; j--)
        {
            if (arr[j] >= x)
            {
                i--;
                troca(&arr[i], &arr[j]);
            }
        }
        troca(&arr[i - 1], &arr[l]);
        return (i - 1);
    }
    else
    {
        int x = arr[((h+l) / 2)];//pivo
        int i = l;//esq
        int j = h;//dir
        int k;

        do{
            while(x>arr[i]) i++;
            while(x<arr[j]) j--;
           troca(&arr[j],&arr[i]);
        }while(i<j);
        for(k=l; arr[k]!=x; k++);
        return(k);
    }
}

void quickSort(int arr[], int l, int h, bool pivotNoInicio)
{
    int stack[h - l + 1];
    int top = -1;

    stack[++top] = l;
    stack[++top] = h;

    while (top >= 0)
    {
        h = stack[top--];
        l = stack[top--];

        int p = pivot(arr, l, h, pivotNoInicio);

        if (p - 1 > l)
        {
            stack[++top] = l;
            stack[++top] = p - 1;
        }

        if (p + 1 < h)
        {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
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

void maxHeap(int array[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (array[i] > array[(i - 1) / 2])
        {
            int j = i;

            while (array[j] > array[(j - 1) / 2])
            {
                troca(&array[j], &array[(j - 1) / 2]);
                j = (j - 1) / 2;
            }
        }
    }
}

void heapSort(int array[], int n)
{
    maxHeap(array, n);

    for (int i = n - 1; i > 0; i--)
    {
        troca(&array[0], &array[i]);

        int j = 0, index;

        do
        {
            index = (2 * j + 1);

            if (array[index] < array[index + 1] && index < (i - 1))
            {
                index++;
            }
            if (array[j] < array[index] && index < i)
            {
                troca(&array[j], &array[index]);
            }

            j = index;

        } while (index < i);
    }
}

void merge(int array[], int inicio, int meio, int fim)
{
    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
    {
        L[i] = array[inicio + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = array[meio + 1 + j];
    }

    i = 0;
    j = 0;
    k = inicio;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        array[k] = R[j];
        j++;
        k++;
    }
}

int min(int x, int y)
{
    return (x < y) ? x : y;
}

void mergeSort(int arr[], int n)
{
    int tamanho;
    int esquerda;

    for (tamanho = 1; tamanho <= n - 1; tamanho = 2 * tamanho)
    {
        for (esquerda = 0; esquerda < n - 1; esquerda += 2 * tamanho)
        {
            int mid = min(esquerda + tamanho - 1, n - 1);

            int direita = min(esquerda + 2 * tamanho - 1, n - 1);

            merge(arr, esquerda, mid, direita);
        }
    }
}

#endif /* ORDENACAO_H */