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
#define forn(i, n) for(long long i = 0; i < n; ++i)
#define IOS   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
vector<int> powers2(32,0);
void initialize(){ for(int i=1;i<powers2.size();i++) powers2[i] = powers2[i-1]*2;}
inline bool is_palindrome(const string &s) { return std::equal(s.begin(), s.end(), s.rbegin()); }
int adj[100][100] = {},visited[100] = {},n;
void dfs(int src){
    cout<<(char)(src+'A')<<" ";
    visited[src] = 1;
    forn(i,n)
    if(adj[src][i] == 1 && visited[i] == 0)
    dfs(i);
}
int FullDfs(){
    int count = 0;
forn(i,n)
if(visited[i] == 0)
dfs(i),count++;
return count == 0 ? 1 : count;
}
int32_t main()
{
auto start = chrono::high_resolution_clock::now();
IOS
int t;
cin>>t;
while(t--){
    char a;
    cin>>a;
    n  = a - 'A'+1;
    forn(i,n){
        char a,b;
        cin>>a>>b;
    adj[(int)(a-'A')][(int)(b-'A')] = adj[(int)(b-'A')][(int)(a-'A')] = 1;
    }
    forn(i,n)
    adj[i][i] = 1;
    forn(i,n){
        forn(j,n)
        cout<<adj[i][j]<<' ';
        cout<<endl;
    }
   cout<< FullDfs();
}
auto end = chrono::high_resolution_clock::now();
double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
time_taken *= 1e-9;
//cout << fixed << time_taken;
return 0;
}