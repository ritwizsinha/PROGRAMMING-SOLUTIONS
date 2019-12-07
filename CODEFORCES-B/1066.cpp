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
int n,r;
cin>>n>>r;
vector<int> l,m;
int count1;
for(int i=0;i<n;i++){
    int a;
    cin>>a;
    if(a == 1){
        count1++;
    l.push_back(i-r+1);
    m.push_back(i+r-1);
    }
}

int x=0;
int lastPos=0,count=0;
int flag=1;
if(l.size() == 0 || r==1 && l.size() < n){
cout<<-1;
return 0;
}
while(x<n-1){
    int pos = lower_bound(all(l),x)   - begin(l);
    if(x == 0){
        if(pos == l.size()){
            lastPos = pos-1,x = m[pos-1],count++;
        }
        else if(l[pos] > 0 && pos == 0)
        {
            flag=0;
            break;
        }
        else{
            if(l[pos] > 0 && pos !=0){
                lastPos = pos-1,x = m[pos-1],count++;
            }
            else if(l[pos] <= 0)
            lastPos = pos ,x = m[pos],count++;
        }
    }
    else
    {
        if(pos == l.size()){
            lastPos = pos-1,x = m[pos-1],count++;
        }
        else if(l[pos] > x+1 && pos-1 <=lastPos){
            flag = 0;
            break;
        }
        else{
            if(l[pos] > x+1 && pos-1>lastPos){
                lastPos = pos-1,x=m[pos-1],count++;
            }
            else if(l[pos] <= x+1)
            lastPos = pos,x = m[pos],count++;
        }
    }
}
if(flag)
cout<<count;
else
cout<<-1;
auto end = chrono::high_resolution_clock::now();
double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
time_taken *= 1e-9;
//cout << fixed << time_taken;
return 0;
}