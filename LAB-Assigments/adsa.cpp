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
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n+1];
        a[0] = 0;
        a[1] = 0;
        a[2] = 1;
        a[3] = 2;
        for(int i=4;i<=n;i++)
        a[i] = max(i/2+i/3+i/4,a[i/3] + a[i/2] + a[i/4]);
        cout<<a[n]<<endl;
     }
     
return 0;
}