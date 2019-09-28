//Passed in one attempt
#include<bits/stdc++.h>
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define endl "\n"
#define int long long
#define forn(i,n) for(long long i = 0; i < long long (n); ++i)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int maximum(int a,int b,int c){
    int mx = a;
    if(b > mx)
    mx = b;
    if(c > mx)
    mx = c;
    return mx;
}
inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }
int32_t main()
{
IOS
int n;
cin>>n;
int a[n],b[n];
for(int i=0;i<n;i++)
cin>>a[i];
for(int i=0;i<n;i++)
cin>>b[i];
int dp[100000][3];
dp[0][0] = a[0];
dp[0][1] = b[0];
dp[0][2] = 0;
for(int i=1;i<n;i++){
    dp[i][0]  = max(dp[i-1][1] + a[i],dp[i-1][2] + a[i]);
    dp[i][1]  = max(dp[i-1][0] + b[i],dp[i-1][2] + b[i]);
    dp[i][2] = maximum(dp[i-1][0],dp[i-1][1],dp[i-1][2]);
}
cout<<maximum(dp[n-1][0],dp[n-1][1],dp[n-1][2]);
return 0;
}