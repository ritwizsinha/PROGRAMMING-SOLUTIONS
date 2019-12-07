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
map<int,vector<int>> adj;
bool visited[100];
    int n;
vector<int> topoSorted;
void dfstopo(int src){
visited[src] = true;
for(auto val : adj[src])
if(!visited[val])
dfstopo(val);
topoSorted.push_back(src);
}
int32_t main()
{
auto start = chrono::high_resolution_clock::now();
int t=0;
while(cin>>n){
    t++;
    map<string,int> mp;
    map<int,string> mp2;
    forn(i,n){
        string s;
        cin>>s;
        mp[s]  = i;
        mp2[i]  = s;
    }
    int m;
    cin>>m;

    forn(i,m){
        string s1,s2;
        cin>>s1>>s2;
        adj[mp[s1]].push_back(mp[s2]);
    }
    memset(visited,false,n*sizeof(visited[0]));
    forn(i,n)
    if(!visited[i])
    dfstopo(i);
    reverse(all(topoSorted));
    cout<<"Case #"<<t<<": "<<"Dilbert should drink beverages in this order: ";
    for(auto val : topoSorted)
    cout<<mp2[val]<<" ";
    cout<<".";
    cout<<endl<<endl;
    topoSorted.clear();
}
auto end = chrono::high_resolution_clock::now();
double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
time_taken *= 1e-9;
//cout << fixed << time_taken;
return 0;
}
//Not submitted