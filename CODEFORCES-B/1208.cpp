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
int n;
cin>>n;
vector<int> v(n);
for(int i=0;i<n;i++)
cin>>v[i];
int ans = n;
int low = 0,high=n;
 while(high-low>=0){
    int mid = (high + low)/2;
    map<int,int> mp;
    for(int i=0;i<n;i++)
    mp[v[i]]++;
    int flag=0;
    for(int i=0;i<mid;i++){
        mp[v[i]]--;
        if(mp[v[i]] == 0) mp.erase(v[i]);
    } 
    if(mp.size() == n - mid)
    flag=1;
    for(int i=mid;i<n;i++){
        mp[v[i-mid]]++;
        mp[v[i]]--;
        if(mp[v[i]] == 0) mp.erase(v[i]);
        if(mp.size() == n-mid)
        flag=1;
    }
    if(flag == 1)
    high  = mid-1,ans = mid;
    else
    low = mid+1;
 }
 cout<<ans;
auto end = chrono::high_resolution_clock::now();
double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
time_taken *= 1e-9;
//cout << fixed << time_taken;
return 0;
}