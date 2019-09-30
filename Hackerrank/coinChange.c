#include <stdio.h>
int coinexchange(int *input, int k, int is, int *output, int os, int t)
{
    if (t == 0)
    {
        for (int i = 0; i < os; i++)
        {
            printf("%d ", output[i]);
        }
        printf("\n");
        return 1;
    }
    if (t < 0 || k >= is)
    {
        return 0;
    }
    int ans = 0;
    ans += coinexchange(input, k + 1, is, output, os, t);
    output[os] = input[k];
    ans += coinexchange(input, k, is, output, os + 1, t - input[k]);
    return ans;
}
int main()
{
    int s[] = {1, 2, 3};
    int total = 4;
    int output[1000];
    int ans = coinexchange(s, 0, 3, output, 0, total);
    printf("%d ", ans);
    return 0;
}