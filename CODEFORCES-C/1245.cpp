#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <chrono>
#include<assert.h>
#define MAX 1000001
#define all(s) begin(s),end(s)
#define pii pair<int, int>
#define F first
#define S second
#define MIN3POS(a, b, c) (a) =< (b) ? ((a) =< (c) ? 1 : 3) : ((b) =< (c) ? 2 : 3)
#define MAX3POS(a,b,c) (a) >= (b) ? ((a) >= (c) ? 1 : 3) : ((b) >= (c) ? 2:3)
#define endl '\n'
#define int long long
#define forn(i, n) for (long long i = 0; i < long long(n); ++i)
#define IOS   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
vector<int> powers2(32,0);
void initialize(){ for(int i=1;i<powers2.size();i++) powers2[i] = powers2[i-1]*2;}
inline bool is_palindrome(const string &s) { return std::equal(s.begin(), s.end(), s.rbegin()); }
int32_t main()
{
auto start = chrono::high_resolution_clock::now();
IOS
int MOD  = 1000000007;
string s;
cin>>s;int n = s.size();
vector<int> dp(n);
if(find(all(s),'m') != end(s) || find(all(s),'w') !=end(s))
cout<<0<<endl;
else{
dp[0]  = 1;
if(s[0] == s[1] && (s[0] == 'u' || s[0] == 'n'))
dp[1] = 2*dp[0];
else
dp[1] = dp[0];
int i=2;
while (i<n)
{
    if(s[i] == s[i-1] &&  (s[i] == 'u' || s[i] == 'n'))
    dp[i] = (dp[i-1]%MOD + dp[i-2]%MOD)%MOD;
    else
    dp[i] = dp[i-1]%MOD;
    i++;
}
cout<<dp[n-1];
}
auto end = chrono::high_resolution_clock::now();
double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
time_taken *= 1e-9;
//cout << fixed << time_taken;
return 0;
}