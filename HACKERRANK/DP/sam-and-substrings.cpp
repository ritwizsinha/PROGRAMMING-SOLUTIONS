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
#define MIN3POS(a, b, c) (a) =< (b) ? ((a) =< (c) ? 1 : 3) : ((b) =< (c) ? 2 : 3)
#define MAX3POS(a,b,c) (a) >= (b) ? ((a) >= (c) ? 1 : 3) : ((b) >= (c) ? 2:3)
#define endl '\n'
#define int long long
#define forn(i, n) for (long long i = 0; i < long long(n); ++i)
#define IOS   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MOD 1000000007;
using namespace std;
inline bool is_palindrome(const string &s) { return std::equal(s.begin(), s.end(), s.rbegin()); }
int32_t main()
{
auto start = chrono::high_resolution_clock::now();
IOS;

string s;
cin>>s;
int n = s.size();
int front[n] = {},back[n] = {};
front[0] = (int)(s[0]-48);
for(int i=1;i<n;i++){
    front[i] = (10*front[i-1] + (int)s[i]-48)%MOD;
}
back[n-1] = (int)(s[n-1] - 48);
for(int i=n-2;i>=0;i--){
back[i]=((int)pow(10,n-i-1)*((int)s[i]-48) + back[i+1])%MOD;
}
int sum = 0;
for(int i=0;i<n-1;i++){
sum+=(front[i] + back[i+1])%MOD;
cout<<front[i]<<" "<<back[i+1]<<endl;
}
sum = (sum + front[n-1])%MOD;
cout<<sum<<endl;
auto end = chrono::high_resolution_clock::now();
double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
time_taken *= 1e-9;
//cout << fixed << time_taken;
return 0;
}