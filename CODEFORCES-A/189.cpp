#include<bits/stdc++.h>
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define endl "\n"
#define int long long
#define forn(i,n) for(long long i = 0; i < long long (n); ++i)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }
main()
{
IOS
int n,arr[3];
cin>>n>>arr[0]>>arr[1]>>arr[2];
sort(arr,arr+3);
int dp[n+1];
int i=0;
dp[0] = 0;
while(i!=n){
    if(i >= arr[2])
    dp[i] = max(max(dp[i-arr[0]]+1,dp[i-arr[1]]+1),dp[i-arr[2]]+1);
    else if(i>=arr[1])
    dp[i] = max(dp[i-arr[0]]+1,dp[i-arr[1]]+1);
    else if(i>=arr[1])
        dp[i] = dp[i-arr[0]]+1;
    else
    dp[i] = 0;
    i++;
}
cout<<dp[n];
return 0;
}