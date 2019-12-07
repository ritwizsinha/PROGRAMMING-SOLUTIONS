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
map<int,vector<int> > mp;
vector<int> dist;
vector<bool> visited;
void bfs(int src){
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    visited[src]= true;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto val : mp[v]){
            if(!visited[val]){
                q.push(val);
                dist[val] = dist[v]+1;
                visited[val] =true;
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
    mp.clear(),dist.clear(),visited.clear();
    int n,m;
    cin>>n>>m;
    dist = vector<int>(n+1,0);
    visited = vector<bool>(n+1,false);
    forn(i,m){
        int a,b;
        cin>>a>>b;
        mp[a].push_back(b),mp[b].push_back(a);
    }
    bfs(1);
    int odd=0,even=0;
    vector<int> oddA,evenA;
    forn(i,dist.size()){
        if(i==0)
        continue;
        if(dist[i] & 1){
            oddA.push_back(i);
            odd++;
        }
        else 
        evenA.push_back(i),even++;
    }
    if(odd < even){
        cout<<odd<<endl;
        for(auto val : oddA)
        cout<<val<<" ";
    }
    else{
        cout<<even<<endl;
        for(auto val : evenA)
        cout<<val<<" ";
        cout<<endl;
    }
}
auto end = chrono::high_resolution_clock::now();
double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
time_taken *= 1e-9;
//cout << fixed << time_taken;
return 0;
}