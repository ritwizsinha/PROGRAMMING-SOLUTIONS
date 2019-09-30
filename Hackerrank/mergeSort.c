#include <stdio.h>

void merge(int *a, int l, int r)
{
    int b[1000];
    int m = (l + r) / 2;
    int i = l;
    int j = m + 1, k = 0;
    while (i <= m && j <= r)
    {
        if (a[i] <= a[j])
        {
            b[k++] = a[i++];
        }
        else
        {
            b[k++] = a[j++];
        }
    }
    while (i <= m)
    {
        b[k++] = a[i++];
    }
    while (j <= r)
    {
        b[k++] = a[j++];
    }
    for (i = l, k = 0; i <= r; i++, k++)
    {
        a[i] = b[k];
    }
    return;
}

void mergeSort(int *a, int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, r);
    }
    return;
}

int main()
{
    int arr[] = {2, 5, 9, 1, 2, 4, 3, 0, 2, 2};
    int n = 10;
    mergeSort(arr, 0, n - 1);
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}