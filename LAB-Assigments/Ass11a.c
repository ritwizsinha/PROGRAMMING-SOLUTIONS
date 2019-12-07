#include <stdio.h>
#include <stdlib.h>
int n,m;
char dish[100][100];
int quant[100];
int q;
char name[100][100],dish1[100];
int v[100][100];
int st[100],en[100];
int match[100];
int vis[100];
int ans,idx;
int solve(int a)
{
  for(int i=0; i<idx; i++)
  {
    if(v[a][i] && vis[i]==0)
    {
      vis[i]=1;
      if(match[i]<0)
      {
        match[i]=a;
        return 1;
      }
      else if(solve(match[i]))
      {
        match[i]=a;
        return 1;
      }
    }
  }
  return 0;
}
int main()
{
  printf("Number of Dishes prepared by Angeethi : ");
  scanf("%d",&m);
  printf("Enter name of m dishes without spaces and quantity of each \n");
  for(int i=0; i<m; i++)
  {
    scanf("%s",dish[i]);
    scanf("%d",& quant[i]);
    st[i]=idx;
    en[i]=idx+quant[i]-1;
    idx=en[i]+1;
  }
  printf("Enter number of costumers : ");
  scanf("%d",&n);
  printf("Enter Costumer preferences : \n");
  for(int i=0; i<n; i++)
  {
    
    scanf("%s",name[i]);
    scanf("%d",&q);
    while(q--)
    {
      for(int j=0; j<100; j++)
        dish1[i]='\0';
      scanf("%s",dish1);
      for(int j=0; j<m; j++)
      {
        int flag=1;
        for(int k=0; k<100; k++)
        {
          if(dish[j][k]!=dish1[k])
          {
            flag=0;
            break;
          }
        }
        if(flag==1)
        {
          for(int k=st[j]; k<=en[j]; k++)
            v[i][k]=1;
          break;
        }
      }
    }
  }
  // for(int i=0; i<n; i++)
  // {
  //   for(int j=0; j<idx; j++)
  //     printf("%d",v[i][j]);
  //   printf("\n");
  // }
  for(int i=0; i<100; i++)
    match[i]=-1;
  for(int i=0; i<n; i++)
  {
    for(int i=0; i<100; i++)
      vis[i]=0;
    if(solve(i))
    {
      ans++;
    }
  }
  printf("Number of costumer Satisfied : ");
  printf("%d\n",ans);
  for(int i=0; i<idx; i++)
  {
    if(match[i]<0)
      continue;
    printf("Name of costumer : %s \n",name[match[i]]);
   
    
    for(int j=0; j<m; j++)
    {
      if(st[j]<=i && en[j]>=i)
      {
        printf("Item Delivered : %s",dish[j]);
      }
    }
    printf("\n");

  }
}
