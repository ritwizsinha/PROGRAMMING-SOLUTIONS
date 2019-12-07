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
vector<int> visited;
vector<int> dist;
void bfs(int src){
    visited[src]  = 1;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
            int val = q.front();
            q.pop();
            for(auto val2 : mp[val]){
                if(!visited[val2]){
                    q.push(val2);
                    dist[val2] = dist[val] + 1;
                    visited[val2] = 1;
                }
            }
    }
}
int32_t main()
{
auto start = chrono::high_resolution_clock::now();
IOS
int t;
cin>>t;
while(t--){
    mp.clear();
    int n,m;
    cin>>n>>m;
    forn(i,m){
        int a,b;
        cin>>a>>b;
        mp[a].push_back(b),mp[b].push_back(a);
    }
    visited.clear(),dist.clear();
    visited = vector<int>(n+1,0);
    dist  = vector<int>(n+1,0);
    bfs(1);
    cout<<dist[n]<<endl;
}
auto end = chrono::high_resolution_clock::now();
double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
time_taken *= 1e-9;
//cout << fixed << time_taken;
return 0;
}