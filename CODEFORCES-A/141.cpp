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
using namespace std;
inline bool is_palindrome(const string &s) { return std::equal(s.begin(), s.end(), s.rbegin()); }
int32_t main()
{
auto start = chrono::high_resolution_clock::now();
IOS
string s1,s2,s3;
cin>>s1>>s2>>s3;
map<char,int> mp1,mp2,mp3;
for(auto a : s1)
mp1[a]++;
for(auto a : s2)
mp2[a]++;
for(auto a : s3)
mp3[a]++;
int flag=1;

for(auto m : mp1){
    if(m.second <= mp3[m.first])
    mp3[m.first]-=m.second;
    else
    flag=0;
}
if(flag==0){
    cout<<"NO";
    return 0;
}
for(auto m : mp2){
    if(m.second > mp3[m.first]){
    flag=0;break;}
    else
    mp3[m.first]-=m.second;
}
for(auto m : mp3){
if(m.second == 0)
continue;
else
flag=0;
}
if(flag==0)
cout<<"NO";
else
cout<<"YES";
auto end = chrono::high_resolution_clock::now();
double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
time_taken *= 1e-9;
//cout << fixed << time_taken;
return 0;
}