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
#define all(v) begin(v),end(v)
#define int long long
#define forn(i, n) for (long long i = 0; i < long long(n); ++i)
#define IOS   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
inline bool is_palindrome(const string &s) { return std::equal(s.begin(), s.end(), s.rbegin()); }
int32_t main()
{
auto start = chrono::high_resolution_clock::now();
IOS
int n,q;
cin>>n>>q;
vector<int> v(n);
for(int i=0;i<n;i++){
    cin>>v[i];
}
sort(all(v));
int sum  = accumulate(all(v),0);
for(int i=0;i<q;i++){
    int val ;
    cin>>val;
    if(val & 1 || q > sum)
    cout<<-1<<endl;
    else
    {   int count=0;
        while (1)
        {
            int pos = lower_bound(all(v),val) -begin(v);
            if(pos == 0 || q == 1)
            break;
            else{
            if(v[pos] == q){
                count=1;
                break;
            }
            q-=v[pos-1];
            count++;
            }
        }
        cout<<count;
        
    }
    
}
auto end = chrono::high_resolution_clock::now();
double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
time_taken *= 1e-9;
cout << fixed << time_taken;
return 0;
}