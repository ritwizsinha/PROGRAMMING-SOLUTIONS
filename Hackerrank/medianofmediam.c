#include <stdio.h>



    int main()
{
    int arr[] = {2, 5, 9, 1, 4, 3};
    int n = 10;
    quickSort(arr, 0, n - 1);
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}