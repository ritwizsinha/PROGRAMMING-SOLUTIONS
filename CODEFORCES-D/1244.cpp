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
vector<int> a, b, c, dp(3), color, colChosen;
map<int, vector<int>> edge;
int cond2 = 0;
int sum1 = 0,sum2=0,sum3=0;
void dfs(int src,int cond,int &sum){
    cout<<cond<<endl<<sum<<endl;
    for(auto val : edge[src]){
        if(color[val] == 0){
            if(cond == 0)
            sum+=a[val-1];
            else if(cond == 1)
            sum+=b[val-1];
            else if(cond == 2)
            sum+=c[val-1];
            color[val] = 1;
            dfs(val,(cond+1)%3,sum);
        }
    }
}
void assignColor(int src,int cond){
    for(auto val : edge[src]){
        if(colChosen[val-1] == 0){
            colChosen[val-1] = cond+1;
            assignColor(val,(cond+1)%3);
        }
    }
}
int32_t main()
{
    auto start = chrono::high_resolution_clock::now();
    IOS
     int n;
     cin>>n;
    a = vector<int>(n);
    b = vector<int>(n);
    c = vector<int>(n);
    colChosen = vector<int>(n,0);
    color = vector<int>(n + 1, 0);
    forn(i, n)
            cin >>
        a[i];
    forn(i, n)
            cin >>
        b[i];
    forn(i, n)
            cin >>
        c[i];
    int flag = 0;
    forn(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for (auto [val, count] : edge)
    {
        if (count.size() > 2)
        {
            cout <<val;
            return 0;
        }
        // cout<<count[0]<<endl;
    }
    dfs(1,0,sum1);
    color = vector<int>(n+1,0);
    // dfs(1,1,sum2);
    // color = vector<int>(n+1,0);

    // dfs(1,2,sum3);
    cout<<sum1<<endl;
    // cout<<sum2<<endl;
    // cout<<sum3<<endl;

    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    //cout << fixed << time_taken;
    return 0;
}