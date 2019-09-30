#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int l, int r)
{
    int x = arr[r];
    int i = l - 1, j;
    for (j = l; j <= r - 1; j++)
    {
        if (arr[j] < x)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[r]);
    return i + 1;
}

void quickSort(int *arr, int l, int r)
{
    if (l < r)
    {
        int q = partition(arr, l, r);
        quickSort(arr, l, q - 1);
        quickSort(arr, q + 1, r);
    }
    return;
}

int main()
{
    int arr[] = {2, 5, 9, 1, 2, 4, 3, 0, 2, 2};
    int n = 10;
    quickSort(arr, 0, n - 1);
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}