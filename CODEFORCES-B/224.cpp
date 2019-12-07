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
int n,k;
vector<int> v;
int l,r;
bool check(int mid){
    map<int,int> mp;
    for(int i=0;i<n;i++)
    mp[v[i]]++;
    
}
int32_t main()
{
auto start = chrono::high_resolution_clock::now();
IOS
int n,k;
cin>>n>>k;
v.resize(n);
map<int,int> mp;
for(int i=0;i<n;i++)
cin>>v[i],mp[v[i]]++;
if(mp.size() < k)
cout<<-1<<" "<<-1;
else
{   
    int l=0,r=0;
    set<int> s;
    map<int,int> mp2;
    int hi = n,lo = 0;
    while(hi>=lo){
        int mid = (hi + lo)>>1;
        if(check(mid)) hi = mid-1;
        else low = mid+1;
    }
}
auto end = chrono::high_resolution_clock::now();
double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
time_taken *= 1e-9;
//cout << fixed << time_taken;
return 0;
}