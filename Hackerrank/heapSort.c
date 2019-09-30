#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Heapify(int *a, int i, int n)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;
    if (l < n && a[l] > a[i])
    {
        largest = l;
    }

    if (r < n && a[r] > a[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(&a[i], &a[largest]);
        Heapify(a, largest, n);
    }
    return;
}

void buildHeap(int *a, int n)
{
    for (int i = (n) / 2; i >= 0; i--)
    {
        Heapify(a, i, n);
    }
    return;
}

void HeapSort(int *a, int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        swap(&a[0], &a[i]);
        Heapify(a, 0, i);
    }
    return;
}

void increasekey(int *a, int n, int value, int x)
{
    if (value > a[x])
    {
        a[x] = value;
        while (x > 0 && a[(x - 1) / 2] < a[x])
        {
            swap(&a[x], &a[(x - 1) / 2]);
            x = (x - 1) / 2;
        }
    }
    return;
}

void insert(int *a, int n, int value)
{
    int i = n;
    a[i] = -10000;
    increasekey(a, n + 1, value, n);
    return;
}

int heapMax(int *a)
{
    return a[0];
}

void heapExtractMax(int *a, int n)
{
    swap(&a[0], &a[n - 1]);
    Heapify(a, 0, n - 1);
    return;
}

int main()
{
    int arr[1000];
    int n = 10;
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    buildHeap(arr, n);
    // HeapSort(arr, n);
    // heapExtractMax(arr, n);
    //increasekey(arr, n, 20, 9);
    insert(arr, n, 20);
    for (int i = 0; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}