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
string s1,s2;
cin>>s1>>s2;
int count= 0 ;
int l=0,r=n-1;
while(l<=r){
    if(s1[l] != s2[l] && (s1[l] !=s2[r] || s1[r] !=s2[l]) && (s1[l] !=s1[r] || s2[l] != s2[r]) )
    count++;
    l++;r--;
}
cout<<count;
return 0;
}