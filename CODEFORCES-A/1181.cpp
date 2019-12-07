#include<bits/stdc++.h>
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define endl "\n"
#define int long long
#define forn(i,n) for(long long i = 0; i < long long (n); ++i)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }
int32_t main()
{
IOS
int x,y,z;
cin>>x>>y>>z;
if(x%z > y%z){
    cout<<(x+y%z)/z + y/z<<" "<<y%z;
}
else{
    cout<<(y  + x%z) /z + x/z<<" "<<x%z;
}


return 0;
}