#include <stdio.h>
#include <math.h> 
#include <stdlib.h>
int dp[1001][1001];
int ans[1001][1001][5];
int max(int a, int b)
{
    if(a>=b) return a;
    else return b;
}
void times(int x, int y, int freq[])
{
    if(dp[x][y]==0) return;
    freq[ans[x][y][0]]++;
    times(ans[x][y][1],ans[x][y][2],freq);
    times(ans[x][y][3],ans[x][y][4],freq);
}
int main()
{
    int x,y;
    printf("Enter the dimension of sheet :");
    scanf("%d %d",&x,&y);
    printf("Enter the number of products :");
    int n;
    scanf("%d",&n);
    printf("Enter dimensions of all products and profit respectively ");
    int arr[n][3];
    for(int i=0;i<n;i++) scanf("%d %d %d",&arr[i][0],&arr[i][1],&arr[i][2]);
    // memset(ans,0,sizeof(ans));
    memset(dp,0,sizeof(dp));
    for(int i=0;i<y;i++) dp[0][i]=0;
    for(int i=0;i<x;i++) dp[i][0]=0;
    for(int i=1;i<=x;i++)
    {
        for(int j=1;j<=y;j++)
        {
            for(int k=0;k<n;k++)
            {
                int i1,j1;
                i1=i-arr[k][0];
                j1=j-arr[k][1];
                if(i1<0 || j1<0) continue;
                else
                {
                    int w1=arr[k][2]+dp[i1][j]+dp[arr[k][0]][j1];
                    w1=max(w1,arr[k][2]+dp[i][j1]+dp[i1][arr[k][1]]);
                    if(w1>dp[i][j])
                    {
                        dp[i][j]=w1;
                        if(arr[k][2]+dp[i1][j]+dp[arr[k][0]][j1]>arr[k][2]+dp[i][j1]+dp[i1][arr[k][1]])
                        {
                            ans[i][j][0]=k;
                            ans[i][j][1]=i1;
                            ans[i][j][2]=j;
                            ans[i][j][3]=arr[k][0];
                            ans[i][j][4]=j1;
                        }
                        else
                        {
                            ans[i][j][0]=k;
                            ans[i][j][1]=i;
                            ans[i][j][2]=j1;
                            ans[i][j][3]=i1;
                            ans[i][j][4]=arr[k][1];
                        }
                    }
                }
            }
        }
    }
    // for(int i=0;i<=x;i++)
    // {
    //     for(int j=0;j<=y;j++)
    //     {
    //         printf("%d ",dp[i][j]);
    //     }
    //     printf("\n");
    // }
    int freq[n];
    memset(freq,0,sizeof(freq));
    times(x,y,freq);
    // for(int i=0;i<n;i++) printf("%d ",freq[i]);
    printf("\n");
    printf("Maximum profit : %d\n",dp[x][y]);
    printf("Strategy of cutting cloth\n");
    for(int i=0;i<n;i++)
    {
        if(freq[i]!=0)
        {
            printf("%d clothes of %dX%d\n",freq[i],arr[i][0],arr[i][1]);
        }
    }
    return 0;
}
