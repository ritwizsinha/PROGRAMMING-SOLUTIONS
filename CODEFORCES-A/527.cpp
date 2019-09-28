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
    int n,k;
    cin>>n>>k;
    string s = "";
    if(k<=n){
    for(int i=0;i<k;i++)
    s+=(char)(i+97);
    string s1 = s;
    for(int i=0;i<n/k-1;i++)
    {s+=s1;}
    for(int i=0;i<n%k;i++)
    s+=(char)(i+97);
    cout<<s<<endl;}
}
return 0;
}