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
bool comp(char a,char b){
    if(((int)(a- 48))%2 != ((int)(b-48))%2){
        if(a < b )
        return true;
    }
    return false;
}
int par(char a){
    return ((int)(a-48))%2;
}
int32_t main()
{
auto start = chrono::high_resolution_clock::now();
IOS
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    int odds=0,evens1=0,evens2 = 0;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        if(s.size() & 1)
        odds++;
        else {
            int cnt = count(begin(s),end(s),'1');
            cnt & 1 ? evens2++ : evens1++;
        }
    }
    if(odds == 0 && evens2%2 == 1)
    cout<<n-1<<endl;
    else
    {
        cout<<n<<endl;
    }
    
}

auto end = chrono::high_resolution_clock::now();
double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
time_taken *= 1e-9;
//cout << fixed << time_taken;
return 0;
}