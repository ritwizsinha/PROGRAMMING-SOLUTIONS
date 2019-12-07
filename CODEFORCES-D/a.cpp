#include<bits/stdc++.h>
#define pb push_back
#define IOS ios::sync_with_stdio(false);
#define ll long long
#define mod 1000000007
using namespace std;
vector <ll> v[750001];
int main()
{
    ll i,j;
    for(i=1;i<=750000;i++)
    {
        for(j=i;j<=750000;j+=i)
        {
            v[j].pb(i);
        }
    }
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n];
        ll mx = 0;
        for(ll i=0;i<n;i++){
            cin>>a[i];
            mx = max(mx, a[i]);
        }
        ll dp[mx + 2] = {0};
        for(auto cc : a)
        dp[cc] = 1;
        for(auto val : a){
            for(auto div : v[val]){
                if(dp[div]!=0&&div!=val){
                    dp[val] = ((dp[div])%mod +(dp[val])%mod)%mod;
                }
            }
        }
        ll sum = 0;
        for(auto s : dp)
            sum =((sum)%mod+(s%mod))%mod;

        cout<<sum<<endl;
    }
    return 0;
}
