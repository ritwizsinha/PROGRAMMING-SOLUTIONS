

#include<bits/stdc++.h>
#define pb push_back
#define IOS ios::sync_with_stdio(false);
#define ll long long
using namespace std;
int main()
{
	ll t,i;
	cin>>t;
	for(i=0;i<t;i++)
	{
		int f=0,flag=0,j,a,qaz=0;
		ll dis=-1;
		ll n;
		cin>>n;
		for(j=0;j<n;j++)
		{
			cin>>a;
			if(a!=0 && a!=1)
			{
				if(f==0)
				{
					dis=a;
					f=1;
				}
				else
				flag=1;
			}
			if(a==1)
			{
				qaz++;
			}
		}

		if(dis==-1&&qaz>0)
		{
			cout<<"yes"<<endl;
			continue;	
		}
		if(flag==1)
		{
			cout<<"no"<<endl; 
		
		}
		else{
			cout<<"yes"<<endl;
		}
	}
}

