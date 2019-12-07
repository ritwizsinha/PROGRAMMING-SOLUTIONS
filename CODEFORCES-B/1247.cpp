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
#include <assert.h>
#define MAX 1000001
#define pii pair<int, int>
#define F first
#define S second
#define MIN3POS(a, b, c) (a) = < (b) ? ((a) = < (c) ? 1 : 3) : ((b) = < (c) ? 2 : 3)
#define MAX3POS(a, b, c) (a) >= (b) ? ((a) >= (c) ? 1 : 3) : ((b) >= (c) ? 2 : 3)
#define endl '\n'
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
    IOS int t;
    cin >> t;
    while (t--)
    {
        int n, k, d;
        cin >> n >> k >> d;
        map<int, int> mp;
        vector<int> v(n), dp(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        int mn = INT_MAX;
        int sz = 0;
        for (int i = 0; i < d; i++)
            mp[v[i]]++;
        mn = mp.size();
        for (int i = 1; i <= n - d; i++)
        {
            mp[v[i - 1]]--;
            if (mp[v[i - 1]] == 0)
                mp.erase(v[i - 1]);
            mp[v[i + d - 1]]++;
            if (mn > mp.size())
                mn = mp.size();
        }

        cout << mn << endl;
    }
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    //cout << fixed << time_taken;
    return 0;
}