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
int n,k;
cin>>n>>k;
int a[n];
for(int i=0;i<n;i++)
cin>>a[i];
sort(a,a+n);
if(k == n)
cout<<a[n-1];
else if(k == 0){
    if(a[0] == 1)
    cout<<-1;
    else
    {
        cout<<a[0]-1;
    }
    
}
else{
int num = a[k-1];
if(a[k] == a[k-1])
cout<<-1;
else 
cout<<a[k-1];
}return 0;
}