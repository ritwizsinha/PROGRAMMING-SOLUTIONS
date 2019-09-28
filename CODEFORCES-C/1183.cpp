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
int q;
cin>>q;
while (q--)
{       
    int k,n,a,b;
    cin>>k>>n>>a>>b;
    int ans = k - (n+1)*b ;
    // cout<<"ans :"<<ans<<" ";
    if(ans < 0)
    cout<<-1<<endl;
    else if(ans == 0)
    cout<<0<<endl;
    else if(ans/(a-b) > n)
    cout<<n<<endl;
    else if(ans % (a-b) == 0)
    cout<<ans/(a-b)+1<<endl;
        else if(ans < a-b)
    cout<<1<<endl;
    else if(ans % (a-b) != 0)
    cout<<ans/(a-b)<<endl;

    
}

return 0;
}