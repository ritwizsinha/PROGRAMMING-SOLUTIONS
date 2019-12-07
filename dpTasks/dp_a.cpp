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
#define pii pair<int, int>
#define F first
#define S second
#define MIN3(a, b, c) (a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c))
#define endl "\n"
#define int long long
#define forn(i, n) for (long long i = 0; i < long long(n); ++i)
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
using namespace std;
inline bool is_palindrome(const string &s) { return std::equal(s.begin(), s.end(), s.rbegin()); }
int32_t main()
{
    auto start = chrono::high_resolution_clock::now();
    IOS
    int n,k;
    cin>>n>>k;
    vector<int> v(n),dp(n,0);
    for(int i=0;i<n;i++)
    cin>>v[i];
    dp[0] = 0;
    for(int i=1;i<n;i++){
        int mn = (int)INFINITY;
        for(int j=1;j<=k && i-j>=0;j++)
            {
                assert(i-j>=0);
                mn = min(mn,dp[i-j] + abs(v[i-j] - v[i]));
            }
            dp[i] = mn;
    }
cout<<dp[n-1];
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    //cout << fixed << time_taken;
    return 0;
}