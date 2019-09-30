#include <stdio.h>
int c[1000];
void countSort(int *a, int *b, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        c[a[i]]++;
    }
    for (i = 1; i <= 9; i++)
    {
        c[i] = c[i] + c[i - 1];
    }
    for (int i = 9; i >= 1; i--)
        c[i] = c[i - 1];
    for (i = n - 1; i >= 0; i--)
    {
        b[c[a[i]]] = a[i];
        c[a[i]]--;
    }
}

int main()
{
    int arr[] = {2, 5, 9, 1, 4, 3};
    int n = 6;
    int b[n];
    for (int i = 0; i < 1000; i++)
    {
        c[i] = 0;
    }
    countSort(arr, b, n);
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", b[i]);
    }
}