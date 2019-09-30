#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int dp[1001][1001];
int ans[1001][1001][5];
int memo[100];
int max(int a, int b){
    if(a>=b){
        return a;
    }else{
        return b;
    }
}
void times(int x, int y, int freq[])
{
    if(dp[x][y]==0) return;
    freq[ans[x][y][0]]++;
    times(ans[x][y][1],ans[x][y][2],freq);
    times(ans[x][y][3],ans[x][y][4],freq);
}

int maxprofit(int * prices, int len){
    if(len==0){
        memo[len] = 0;
        return memo[len];
    }
    if(memo[len] != -1){
        return memo[len];
    }
    int j;
    int maxans = 0;
    for(j=1;j<=len;j++){
        int present = prices[j-1] + maxprofit(prices,len-j);
        maxans = max(maxans,present);
    }
    memo[len] = maxans;
    return maxans;
}

void makedparr(int x,int y,int n,int* arr1, int * arr2,int * arr3){
    int i;
    for(i=0;i<y;i++) dp[0][i]=0;
    for(i=0;i<x;i++) dp[i][0]=0;
    for(i=1;i<=x;i++)
    {
        int j=1;
        for(;j<=y;j++)
        {   int k=0;
            for(;k<n;k++)
            {
                int i1,j1;
                i1=i-arr1[k];
                j1=j-arr2[k];
                if(i1<0 || j1<0) continue;
                else
                {
                    int w1=arr3[k]+dp[i1][j]+dp[arr1[k]][j1];
                    if(w1 < arr3[k]+dp[i][j1]+dp[i1][arr2[k]]){
                        w1 = arr3[k]+dp[i][j1]+dp[i1][arr2[k]];
                    }
                    if(w1>dp[i][j])
                    {
                        dp[i][j]=w1;
                        if(arr3[k]+dp[i1][j]+dp[arr1[k]][j1]>arr3[k]+dp[i][j1]+dp[i1][arr2[k]])
                        {
                            ans[i][j][0]=k;
                            ans[i][j][1]=i1;
                            ans[i][j][2]=j;
                            ans[i][j][3]=arr1[k];
                            ans[i][j][4]=j1;
                        }
                        else
                        {
                            ans[i][j][0]=k;
                            ans[i][j][1]=i;
                            ans[i][j][2]=j1;
                            ans[i][j][3]=i1;
                            ans[i][j][4]=arr2[k];
                        }
                    }
                }
            }
        }
    }
    return;
}

int main()
{
    int x,y;
    printf("Enter the dimension of the sheet :");
    scanf("%d %d",&x,&y);
    printf("Input the number of products :");
    int n;
    scanf("%d",&n);
    printf("Enter dimensions of all products & profit respectively ");
    int arr1[n],arr2[n],arr3[n];
    int i;
    for(i=0;i<n;i++) scanf("%d %d %d",&arr1[i],&arr2[i],&arr3[i]);
    // memset(ans,0,sizeof(ans));
    memset(dp,0,sizeof(dp));
    makedparr(x,y,n,arr1,arr2,arr3);
    int freq[n];
    memset(freq,0,sizeof(freq));
    times(x,y,freq);
    // for(int i=0;i<n;i++) printf("%d ",freq[i]);
    printf("\n");
    printf("Maximum profit is : %d\n",dp[x][y]);
    printf("Strategy of cutting cloth\n");
    
    for(i=0;i<n;i++)
    {
        if(freq[i]!=0)
        {
            printf("%d clothes of %dX%d\n",freq[i],arr1[i],arr2[i]);
        }
    }
    return 0;
}
