#include <stdio.h>
int cnt = 0;

void rarr(int *arr, int ind)
{
    int i = 0;
    while (i < ind)
    {
        int temp = arr[i];
        arr[i] = arr[ind];
        arr[ind] = temp;
        i++, ind--;
    }
}

int maxInd(int *arr, int size)
{
    int maxel = arr[0], i = 1, position = 0;
    for (; i < size; i++)
    {
        if (maxel < arr[i])
        {
            maxel = arr[i];
            position = i;
        }
    }
    return position;
}

void sortarr(int *arr, int size)
{
    if (size == 1)
    {
        return;
    }
    int ind = maxInd(arr, size);
    if (ind != size - 1)
    {
        if (ind != 0)
        {
            rarr(arr, ind);
            cnt++;
        }
        rarr(arr, size - 1);
        cnt++;
        size--;
        sortarr(arr, size);
    }
    else
        sortarr(arr, size - 1);
}

int main()
{

    printf("Enter the size of array \n");
    int size;
    scanf("%d", &size);
    int a[size], i = 0;
    printf("Enter all elements of the array.\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", a + i);
    }
    sortarr(a, size);
    printf("The sorted array is :\n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\nMinimum number of flips required is:  %d\n", cnt);

    return 0;
}
