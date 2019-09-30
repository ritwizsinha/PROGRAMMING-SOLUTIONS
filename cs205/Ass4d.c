#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a1, int *a2)
{
    int t = *a1;
    *a1 = *a2;
    *a2 = t;
}

int part(int *arr, int l, int r)
{
    int pivot = arr[r];
    int i = (l - 1);
    int j = l;
    for (; j <= r - 1; j++)
    {
        if (arr[j] <= pivot)
        {

            i++;
            swap(arr + i, arr + j);
        }
    }
    swap(arr + i + 1, arr + r);
    return (i + 1);
}
int partitioning_Rand_element(int *arr, int l, int r)
{

    int random = l + rand() % (r - l + 1);
    swap(arr + random, arr + r);

    return part(arr, l, r);
}
int kth_s_ele(int *arr, int l, int r, int k)
{
    if (k > 0 && k <= r - l + 1)
    {
        int pos = partitioning_Rand_element(arr, l, r);
        if (pos - l == k - 1)
            return arr[pos];
        if (pos - l > k - 1)
            return kth_s_ele(arr, l, pos - 1, k);
        return kth_s_ele(arr, pos + 1, r,
                         k - pos + l - 1);
    }
    return -1;
}
int main()
{
    srand((unsigned int)time(NULL));
    printf("Enter the total no. of computers : \n");
    int n;
    scanf("%d", &n);
    printf("\nEnter the positions of computers in the co-ordinate system\n");
    int x[1000], y[1000];
    int i = 0;
    for (i = 0; i < n; i++)
    {
        printf("Enter the co-ordinates (In the form of x, y)\n");
        scanf("%d %d", x + i, y + i);
    }
    int res;
    if (n % 2 != 0)
    {
        res = kth_s_ele(y, 0, n - 1, n / 2 + 1);
    }
    else
    {
        res = kth_s_ele(y, 0, n - 1, n / 2);
    }
    printf("Line should be at y = %d\n", res);
    return 0;
}
