// Not done by myself
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
#define all(s) begin(s), end(s)
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
vector<int> powers2(32, 0);
void initialize()
{
    for (int i = 1; i < powers2.size(); i++)
        powers2[i] = powers2[i - 1] * 2;
}
inline bool is_palindrome(const string &s) { return std::equal(s.begin(), s.end(), s.rbegin()); }
map<int, vector<int>> adj;
int bipartite = 1;
vector<int> color;
void dfs(int src, int col)
{
    color[src] = col;
    for (auto val : adj[src])
    {
        if (color[val] == -1)
            color[val] = col, dfs(val, col ^ 1);
        else if (color[val] == col)
            bipartite = 0;
    }
}
int32_t main()
{
    auto start = chrono::high_resolution_clock::now();
    IOS int n, m;
    cin >> n >> m;
    vector<pair<int, int>> vp;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        vp.push_back(make_pair(a, b));
    }
    color = vector<int>(n + 1, -1);
    dfs(1, 0);
    if (bipartite)
        cout << "YES" << endl;
    else
    {
        cout << "NO";
        return 0;
    }
    for (int i = 0; i < m; i++)
    {
        cout << (color[vp[i].first] < color[vp[i].second]);
    }
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    //cout << fixed << time_taken;
    return 0;
}