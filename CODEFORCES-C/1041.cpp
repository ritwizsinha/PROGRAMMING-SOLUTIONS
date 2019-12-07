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

int32_t main()
{
auto start = chrono::high_resolution_clock::now();
IOS
int n,m,s;
cin>>n>>m>>s;
vector<int> v(n),day(n);
map<int,int> mp,mp2;
for(int i=0;i<n;i++)
cin>>v[i],mp2[i] = v[i];
sort(all(v));
mp[v[0]] = 1;
day[0] = 1;
int k=1;
map<int,int> mp3;
mp3[v[0]] = 1;
for(int i=1;i<n;i++){
    auto it = mp.upper_bound(v[i]-s-1);
    if(it == mp.begin()){
        k++;
        day[i] = k;
        mp[v[i]] = 1;
        mp3[v[i]]  = k;
    }
    else{
        day[i] = mp3[mp.begin()->first];
        mp3[v[i]] = day[i];
        mp.erase(mp.begin()->first);
        mp[v[i]] = 1;
    }
}
cout<<k<<endl;
for(int i=0;i<n;i++){
    int val  = mp2[i];
    int pos = lower_bound(all(v),val) - begin(v);
    cout<<day[pos]<<" ";
}
auto end = chrono::high_resolution_clock::now();
double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
time_taken *= 1e-9;
//cout << fixed << time_taken;
return 0;
}