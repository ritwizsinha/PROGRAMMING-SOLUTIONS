#include <stdio.h>
#include <string.h>
int dp[1000][1000];
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
char str[1000];
int size = 0;
int lcs(char *str1, char *str2)
{
    int x = strlen(str1);
    int y = strlen(str2);
    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; j <= y; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (str1[i - 1] == str2[j - 1])
            {
                str[size++] += str[i - 1];

                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; j <= y; j++)
        {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
    printf("%s\n", str);
    return dp[x][y];
}

int main()
{
    char str1[] = "12341";
    char str2[] = "341213";
    int ans = lcs(str1, str2);
    printf("%d ", ans);
}