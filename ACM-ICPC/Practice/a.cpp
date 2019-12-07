#include<bits/stdc++.h>
#define pb push_back
#define IOS ios::sync_with_stdio(false);
#define ll long long
using namespace std;
int main()
{
    IOS
    int t,i;
    cin>>t;
    string s;
 
    for(i=0;i<t;i++)
    {
        cin>>s;
            if(s.size() == 1)
    cout<<s<<endl;
    else{
        int n=s.size();
        int f=-1,j;
        for(j=0;j<n-1;j++)
        {
            if(s[j+1]>=s[j])
            continue;
            else
            {
                f=j;
                break;
            }
        }
        if(f==-1)
        f=n-1;
        j=0;
        if(f==0)
        {
            while(j==f || s[j]=='0')
            {
                if(j==n-1)
                cout<<s[j];
                j++;
                continue;
            }
        }
        for(;j<n;j++)
        {
            if(j!=f)
            cout<<s[j];
        }
        cout<<endl;
    }
    }
}
 
 

