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
#define all(s) begin(s),end(s)
#define MIN3POS(a, b, c) (a) =< (b) ? ((a) =< (c) ? 1 : 3) : ((b) =< (c) ? 2 : 3)
#define MAX3POS(a,b,c) (a) >= (b) ? ((a) >= (c) ? 1 : 3) : ((b) >= (c) ? 2:3)
#define endl '\n'
#define int long long
#define forn(i, n) for (long long i = 0; i < n; ++i)
#define IOS   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;  
vector<int> powers2(32,0);
void initialize(){ for(int i=1;i<powers2.size();i++) powers2[i] = powers2[i-1]*2;}
inline bool is_palindrome(const string &s) { return std::equal(s.begin(), s.end(), s.rbegin()); }
map<int,vector<int>> mp;
vector<bool> visited;

void dfs(int src,int &count){
    visited[src] = true;
    for(auto val : mp[src])
    if(!visited[val])
    count++,dfs(val,count);
}
int32_t main()
{
auto start = chrono::high_resolution_clock::now();
IOS
int n,k;
cin>>n>>k;
visited.resize(n+1);
forn(i,k)
{
    int a,b;
    cin>>a>>b;

    mp[a].push_back(b);
    mp[b].push_back(a);
}
// for(auto [val,arr]: mp){
//     cout<<val<<" ";
//     for(auto val2 : arr)
//     cout<<val2<<" ";
//     cout<<endl;
// }
int sum = 0;
for(int i=1;i<=n;i++){
    int count = 0;
    if(!visited[i])
    dfs(i,count);
    sum+=count;
}
cout<<k - sum<<endl;
auto end = chrono::high_resolution_clock::now();
double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
time_taken *= 1e-9;
//cout << fixed << time_taken;
return 0;
}