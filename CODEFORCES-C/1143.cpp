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
#define forn(i, n) for (long long i = 0; i < long long(n); ++i)
#define IOS   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
vector<int> powers2(32,0);
void initialize(){ for(int i=1;i<powers2.size();i++) powers2[i] = powers2[i-1]*2;}
inline bool is_palindrome(const string &s) { return std::equal(s.begin(), s.end(), s.rbegin()); }
map<int,vector<int>> mp;
vector<int> c,nx;
void bfs(int src,int size){
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        int flag=1;
        for(auto val : mp[x]){
            if(c[val] !=1)
            flag=0;
            q.push(val);
        }
        if(flag==1 && c[x] == 1)
            nx.push_back(x);
    }
}
int32_t main()
{
auto start = chrono::high_resolution_clock::now();
IOS
int n;
cin>>n;
int a[n],src;
c.resize(n);

for(int i=0;i<n;i++){
cin>>a[i]>>c[i];
if(a[i]!=-1)
mp[a[i]-1].push_back(i) ;
else
src = i;
}
 bfs(src,n);
// for(auto [val,arr]: mp)
// {
//     cout<<val<<" ";
//     for(auto val1 : arr)
//     cout<<val1<<" ";
//     cout<<endl;
// }
if(nx.size() == 0)
cout<<-1;
sort(all(nx));
for(auto val : nx)
cout<<val+1<<" ";
auto end = chrono::high_resolution_clock::now();
double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
time_taken *= 1e-9;
//cout << fixed << time_taken;
return 0;
}