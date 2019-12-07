#include<stdio.h>
#define MAX 100
#define con 1
int n;
int adj[MAX][MAX];

int isReachable(int s, int d) 
{ 
    if (s == d) 
      return 1;
    int visited[1000] ={0};
    for (int i = 0; i < n; i++) 
        visited[i] = 0; 
  
    int queue[100],front=0,back=0;
    visited[s] = 1; 
    queue[back++] = s; 
  
    
    while (front!=back) 
    { 
        
        s = queue[front]; 
        front++; 

        int i=0;
        for (;i<n;i++) 
        { 
            if(adj[s][i] !=0){
            if (i == d) 
                return 1; 
  
            
            if (!visited[i]) 
            { 
                visited[i] = 1; 
                queue[back++]  = i; 
            } 
            }
        } 
    } 
      
    
    return 1; 
} 
int main(){
int i=0;
scanf("%d",&n);
for(;i<n;i++){
    int a,b;
    scanf("%d %d",&a,&b);
    adj[b][a] =1;
}
int checkBFS(int i){
    if(i == con)
    return 1;
    return 0;
}
int q;
scanf("%d",&q);
i=0;
for(;i<q;i++){
    int a,b;
    scanf("%d %d",&a,&b);
    if(isReachable(b,a) ==1 && checkBFS(i)!=1)
    printf("%d\n",b);
    else if(isReachable(a,b) ==1 && checkBFS(i)!=1)
    {
        printf("%d\n",a);
    }
    else
    printf("%d",a > b ? b : a);
    
}

}