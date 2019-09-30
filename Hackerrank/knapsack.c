#include <stdio.h>
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int knapSack(int W, int *wt, int *val, int n)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }
    if (wt[n - 1] > W)
    {
        return knapSack(W, wt, val, n - 1);
    }
    else
    {
        return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), knapSack(W, wt, val, n - 1));
    }
}

int knapSack2(int W, int *wt, int *val, int n)
{
    int K[n + 1][W + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
            {
                K[i][j] = 0;
            }
            else if (wt[i - 1] <= j)
            {
                K[i][j] = max(val[i - 1] + K[i - 1][j - wt[i - 1]], K[i - 1][j]);
            }
            else
            {
                K[i][j] = K[i - 1][j];
            }
        }
    }
    return K[n][W];
}
int DP[70];
int unboundedKnapSack(int W, int *wt, int *val, int n)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }
    else if (DP[W] != -1)
        return DP[W];
    else if (wt[n - 1] <= W)
    {
        return DP[W] = max(val[n - 1] + unboundedKnapSack(W - wt[n - 1], wt, val, n), unboundedKnapSack(W, wt, val, n - 1));
    }
    else
    {
        return DP[W] = unboundedKnapSack(W, wt, val, n - 1);
    }
}

int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    for (int i = 0; i < 70; i++)
        DP[i] = -1;
    int ans = unboundedKnapSack(W, wt, val, n);

    printf("%d", ans);
    return 0;
}