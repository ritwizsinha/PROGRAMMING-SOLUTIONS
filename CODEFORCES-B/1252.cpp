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
int  n,q;
cin>>n>>q;
int a[n][2],b[n][2];
int sz = 1;
for(int i=0;i<n;i++){
    cin>>a[i][0];
    if(i==0)
    a[i][1] = sz;
    else
    {
        a[i][1] = a[i-1][0] % 2 == a[i][0]%2 ? sz : ++sz;
    }
    
}
for(int i=0;i<n;i++){
    cin>>b[i][0];
    if(i==0)
    b[i][1] = sz;
    else
    {
        b[i][1] = b[i-1][0] % 2 == b[i][0]%2 ? sz : ++sz;
    }
    
}
// for(int i=0;i<n;i++){
//     cout<<a[i][0]<<" "<<a[i][1]<<endl;
// }

// v1[0].second = 1;
// int sz = 1;
// for(int i=1;i<n;i++){
//     if(((v1[i-1].first)%2 == 0  && (v1[i].first)%2 == 0) || (v1[i-1].first%2 !=0 && v1[i].first%2 !=0) ){
//     v1[i].second  = sz;
//     }
//     else if((v1[i-1].first%2 == 0 && (v1[i].first)%2 != 0) || v1[i-1].first%2 !=0 && v1[i].first%2 == 0){
//         sz++;
//         v1[i].second = sz;
//     }
// }
// v2[0].second = 1;
// sz=1;
// for(int i=1;i<n;i++){
//     if((v2[i-1].first%2 == 0  && v2[i].first%2 == 0) || (v2[i-1].first%2 !=0 && v2[i].first%2 !=0) ){
//     v2[i].second  = sz;
//     }
//     else if((v2[i-1].first%2 == 0 && v2[i].first%2 != 0) || v2[i-1].first%2 !=0 && v2[i].first%2 == 0){
//         sz++;
//         v2[i].second = sz;
//     }
// }
// for(auto a : v1){
//     cout<<a.first<<" "<<a.second<<endl;
// }
while(q--){
    int ra,ca,rb,cb;
    cin>>ra>>ca>>rb>>cb;
    if(a[ra-1][1] == a[rb-1][1] && b[ca-1][1] == b[cb-1][1])
    cout<<"YES"<<endl;
    else
    {
        cout<<"NO"<<endl;
    }
    
    }
// }
auto end = chrono::high_resolution_clock::now();
double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
time_taken *= 1e-9;
//cout << fixed << time_taken;
return 0;
}