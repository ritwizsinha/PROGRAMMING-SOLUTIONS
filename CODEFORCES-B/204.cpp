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
#define MAXI 2000000000
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
vector<int> x(n),y(n);
set<int> s;
map<int,int> mpx,mpy;
forn(i,n){
    int a, b;
    cin>>a>>b;
    s.insert(a);
    s.insert(b);
    x[i] = a,y[i] = b;
    mpx[a]++,mpy[b]++;
}   
forn(i,n){
if(x[i] == y[i])
mpy[x[i]]--;
}
int mn = MAXI;
for(auto val  : s){
    int c1  = mpx[val];
    int c2 = mpy[val];
    if((n&1) && c1> n/2 || !(n&1) && c1>=n/2)
    {
        cout<<0;
        return 0;
    }
    if((n&1) && c1+c2 > n/2 || !(n&1) && c1+c2 >=n/2)
        {
            if(n & 1){
                mn = min(mn,min(c2,n/2+1 - c2));
            }
            else
            mn = min(mn,min(c2,n/2 - c2));
        }
}
if(mn == MAXI){
    cout<<-1;
}
else
cout<<mn;
auto end = chrono::high_resolution_clock::now();
double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
time_taken *= 1e-9;
//cout << fixed << time_taken;
return 0;
}