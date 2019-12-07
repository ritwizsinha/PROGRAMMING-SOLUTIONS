#include<stdio.h>
#include<string.h>
char gene1[1000],gene2[1000];
int find_3_min(int x,int y,int z){
    int mx = x;
    if(y > x)
    mx = y;
    if(z > mx)
    mx = z;
    return mx;
}
int dp[1000][1000];

int edit_distance(int pos1,int pos2){
    int a = find_3_min(pos1,pos2,2);
if (pos1 == 0 || pos2 == 0) 
        return pos1 + pos2;

    if (dp[pos1 - 1][pos2 - 1] != -1) 
        return dp[pos1 - 1][pos2 - 1]; 
    if (gene1[pos1 - 1] == gene2[pos2 - 1]) 
        return dp[pos1 - 1][pos2 - 1] = edit_distance(pos1 - 1, pos2 - 1); 
    int mn = edit_distance(pos1, pos2 - 1);
    if(mn > edit_distance(pos1 - 1, pos2))
    mn = edit_distance(pos1 - 1, pos2);
    if(mn > edit_distance(pos1 - 1, pos2 - 1))
    mn = edit_distance(pos1 - 1, pos2 - 1);
    return dp[pos1-1][pos2-1]  = 1 + mn;
}
int main(){
    int i=0;
    for(;i<1000;i++){
        int j=0;
    for(;j<1000;j++)
    dp[i][j] = -1;
}
    printf("Enter gene1\n");
    scanf("%s",gene1);
    printf("\nEnter gene2\n");
    scanf("%s",gene2);
    printf("Similiarity :  %d ",(int)strlen(gene1)  + (int)strlen(gene2) - edit_distance((int)strlen(gene1),(int)strlen(gene2)));
    printf("\n");
    // for(int i=0;i<(int)strlen(gene1);i++){
    //     for(int j=0;j<(int)strlen(gene2);j++)
    //     printf("%d ",dp[i][j]);
    //     printf("\n") ;
    // }
    printf("Total number of operations required = %d",edit_distance((int)strlen(gene1),(int)strlen(gene2)));
}
