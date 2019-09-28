//Not  done
//Not understood
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    ll n;
    cin>>n;
    if(n<=2)
    {
        cout<<n;
        return 0;
    }
    if(1 & n) cout<<(ll)(n*(n-1)*(n-2));
    else
    {
        if(n%3!=0) cout<<(ll)(n)*(n-1)*(n-3);
        else cout<<(ll)(n-1)*(n-2)*(n-3);
    }
    
    return 0;
}