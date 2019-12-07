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
int32_t main()
{
    auto start = chrono::high_resolution_clock::now();
    IOS int n, k;
    cin >> n >> k;
    map<int, vector<int>> mp;
    int mx = 0;
    forn(i, n)
    {
        int a;
        cin >> a;
        mx = max(mx, a);
        mp[a].push_back(i + 1);
    }
    if (mp[0].size() > 1)
    {
        cout << -1;
        return 0;
    }
    queue<int> q;
    if(mp[0].size() <1){
        cout<<-1;return 0;
    }
    q.push(mp[0][0]);
    int flag = 1;
    mp.erase(0);
    vector<pair<int, int>> v;
    for (int i = 1; i <= mx; i++)
    {
        if (mp.count(i))
        {
            if(i == 1){
            if (mp[i].size() <= k * q.size())
            {
                int pos = 0;
                queue<int> q2;
                while (!q.empty() && pos < mp[i].size())
                {
                    int parent = q.front();
                    q.pop();
                    int f = 0;
                    while (f < k && pos < mp[i].size())
                    {
                        v.push_back(make_pair(parent, mp[i][pos]));
                        q2.push(mp[i][pos]);
                        f++, pos++;
                    }
                }
                q  = q2;
            }
            else
            {
                cout<<-1;return 0;
            }
            }
            else {
                            if (mp[i].size() <= (k-1) * q.size())
            {
                int pos = 0;
                queue<int> q2;
                while (!q.empty() && pos < mp[i].size())
                {
                    int parent = q.front();
                    q.pop();
                    int f = 0;
                    while (f < (k-1) && pos < mp[i].size())
                    {
                        v.push_back(make_pair(parent, mp[i][pos]));
                        q2.push(mp[i][pos]);
                        f++, pos++;
                    }
                }
                q  = q2;
            }
            else
            {
                cout<<-1;return 0;
            }
            }
        }
        else
        {
            cout<<-1;return 0;
        }
    }
    cout<<v.size()<<endl;
    for(auto [ed1,ed2]: v)
    cout<<ed1<<" " <<ed2<<endl;
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    //cout << fixed << time_taken;
    return 0;
}