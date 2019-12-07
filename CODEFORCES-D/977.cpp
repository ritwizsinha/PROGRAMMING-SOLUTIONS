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
    cin >> n;
    vector<int> b(n, -1), a(n),c(n,-1);
    for (int i = 0; i < n; i++)
        cin >> a[i];
        sort(all(a));
    int i = 0;
    while (i < n)
    {
        if (b[i] == -1)
        {
            if(a[i]%3 == 0){
                auto it = find(all(a),a[i]/3);
                if(it !=end(a))
                b[i] = it - begin(a);
                c[it - begin(a)] = i;
            }
            auto it2 = find(all(a),a[i]*2);
            if(it2 !=end(a))
            b[i] = it2 - begin(a);
            c[it2 - begin(a)] = i;
        }
        i++;
    }
    // for(auto val : a)
    // cout<<val<<" ";
    // cout<<endl;
    // for(auto val : b )
    // cout<<val<<' ';
    // cout<<endl;
    // for(auto val : c)
    // cout<<val<<" ";
     auto Pos = find(all(c),-1) -begin(c);
    // int count = 0;
    while(Pos != -1 ){
        cout<<a[Pos]<<" ";
         Pos = b[Pos];
    }
auto end = chrono::high_resolution_clock::now();
double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
time_taken *= 1e-9;
//cout << fixed << time_taken;
return 0;
}