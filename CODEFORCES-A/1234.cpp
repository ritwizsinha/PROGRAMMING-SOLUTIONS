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
while(q--){
int n;
cin>>n;
int a[n];
int sum = 0;
for(int i=0;i<n;i++)
{cin>>a[i];
sum+=a[i];
}
if(sum%n == 0)
cout<<sum/n<<endl;
else
{
    cout<<sum/n+1<<endl;
}
}
return 0;
}
