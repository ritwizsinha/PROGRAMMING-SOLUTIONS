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
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
cin>>a[i];
for(auto val : a)
{
    if(val %2 == 0)
    cout<<val-1<<" ";
    else
    {
        cout<<val<<" ";
    }
    
}
return 0;
}