#include<bits/stdc++.h>
#include<chrono>
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define endl "\n"
#define int long long
#define forn(i,n) for(long long i = 0; i < long long (n); ++i)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }
int32_t main()
{
auto start = chrono::high_resolution_clock::now(); 
IOS
int t;
cin>>t;
int MOD = 1000000007;


while(t--){
    int n,m;
    int dp[1001] = {};
    dp[0] = 1;
    cin>>n>>m;
    for(int i=0;i<=n+m;i++){
    for(int j=min(i,m);j>=0;j--)
    dp[j] = (dp[j]  + dp[j-1]);
    }

    cout<<dp[m];
}
auto end = chrono::high_resolution_clock::now();
 double time_taken =  chrono::duration_cast<chrono::nanoseconds>(end - start).count();
 time_taken *= 1e-9; 
//cout <<endl<<fixed<< time_taken << setprecision(9); 
return 0;
}