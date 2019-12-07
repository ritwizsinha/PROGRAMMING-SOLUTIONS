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
#define forn(i, n) for (long long i = 0; i < n; ++i)
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
int adj[200][200], visited[100] = {}, n;
char res[200][200];
void dfs(int src)
{
    visited[src] = 1;
    for (int i = 0; i < n; i++)
        if (adj[src][i] == 1 && visited[i] != 1)
            dfs(i);
}
void dfs2(int src, int avoid)
{
    visited[src] = 1;
    forn(i, n)
    {
        if (adj[src][i] == 1 && visited[i] != 1 && src != avoid)
            dfs2(i, avoid);
    }
}
int dfsutil(int src, int avoid, int reach)
{
    forn(i, 100) visited[i] = 0;
    dfs2(src, avoid);
    if (visited[reach] == 0)
        return 1;
    return 0;
}
int32_t main()
{
    auto start = chrono::high_resolution_clock::now();
    IOS

        int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> adj[i][j];
        }
        dfs(0);
        forn(i, n)
        {
            forn(j, n)
                res[i][j] = '0';
        }
        for (int i = 0; i < n; i++)
            res[i][i] = 'Y';
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 0)
            {
                for (int j = 0; j < n; j++)
                    if (i != j)
                        res[j][i] = 'N';
            }
        }
        forn(i, n)
        {
            forn(j, n)
            {
                if (res[i][j] == '0')
                {
                    int rs = dfsutil(0, i, j);
                    if (rs == 1)
                        res[i][j] = 'Y';
                    else
                        res[i][j] = 'N';
                }
            }
        }
        forn(i, n)
        {
            cout << "+ ";
            forn(k, n) cout << "- ";
            cout << "+" << endl;
            cout << "|";
            forn(j, n)
                    cout
                << res[i][j] << "|";
            cout << endl;
        }
        cout << "+ ";
        forn(k, n) cout << "- ";
        cout << "+" << endl;
    }
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
   // cout << fixed << time_taken;
    return 0;
}
//Not submitted due to stupid output format