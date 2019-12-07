#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <numeric>
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
#define int long long
#define forn(i, n) for (long long i = 0; i < long long(n); ++i)
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
using namespace std;
vector<int> powers2(32, 0);
void initialize()
{
    for (int i = 1; i < powers2.size(); i++)
        powers2[i] = powers2[i - 1] * 2;
}
inline bool is_palindrome(const string &s) { return std::equal(s.begin(), s.end(), s.rbegin()); }
struct pos
{
    int mn, mx;
};
int32_t main()
{
    auto start = chrono::high_resolution_clock::now();
    IOS int n, m;
    cin >> n >> m;
    vector<int> v(m);
    for (int i = 0; i < m; i++)
        cin >> v[i];
    vector<int> c(n), ans(n+1);
    struct pos aa[n + 1];
    for (int i = 1; i <= n; i++)
        aa[i].mn = aa[i].mx = i-1;
    iota(begin(c), end(c), 1);
    for(int i=1;i<=n;i++)
    ans[i] = i-1;
    for (auto val : v)
    {
        int pos = ans[val];
        if (pos == 0)
            continue;
        else
        {
                ans[val]--;
                ans[c[pos - 1]]++;
                aa[val].mn = min(aa[val].mn, ans[val]);
                 aa[c[pos - 1]].mx = max(aa[c[pos - 1]].mx, ans[c[pos - 1]]);
                             swap(c[pos], c[pos - 1]);

        }
    // for(auto val : c)
    // cout<<val<<" ";
    // cout<<endl;
        // cout<<aa[val].mn<<" "<<aa[val].mx<<endl;
        //    for(int i=1;i<=n;i++)
        // cout<<aa[i].mn+1<<" "<<aa[i].mx+1<<endl;
    }
    for (int i = 1; i <= n; i++)
        cout << aa[i].mn+1 << " " << aa[i].mx+1 << endl;
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    //cout << fixed << time_taken;
    return 0;
}