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
int t;
cin>>t;
while (t--)
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];

   int value = 0;
   int dp[100000][2];
   for(int i=0;i<n-1;i++){
       dp[i+1][0] = max(dp[i][0],dp[i][1] + abs(arr[i]-1));
       dp[i+1][1] = max(dp[i][0] + abs(arr[i+1] - 1),dp[i][1] + abs(arr[i+1] - arr[i]));
   }
   cout<<max(dp[n-1][0],dp[n-1][1])<<endl;
}


}