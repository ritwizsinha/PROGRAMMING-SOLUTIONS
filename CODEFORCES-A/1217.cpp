#include<bits/stdc++.h>
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define endl "\n"
#define int long long
#define forn(i,n) for(long long i = 0; i < long long (n); ++i)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
inline bool is_palindrome(const string& s){ retur            n std::equal(s.begin(), s.end(), s.rbegin()); }
int32_t main()
{
IOS
int t;
cin>>t;
while(t--){
    int x,y,z;
    cin>>x>>y>>z;
    int a = y+z-x;
    if(a < 0)
    cout<<z+1<<endl;
    else{
        if(a/2 >= z)
        cout<<0<<endl;
        else
        {
            cout<<z - a/2<<endl;
        }
        
    }
}
return 0;
}