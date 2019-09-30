#include <stdio.h>
int main()
{
    int xcloth, ycloth;
    scanf("%d%d", &xcloth, &ycloth);
    int n;
    scanf("%d", &n);
    int x[1000], y[1000], prices[1000];
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d%d%d", x[i], y[i], prices[i]);
    }
    int ans = maxprofit(x, y, prices.n);
    printf("%d", ans);
}