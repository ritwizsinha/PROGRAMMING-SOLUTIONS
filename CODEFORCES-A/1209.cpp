//done myself
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
int a[n],b[n] ;
for(int i=0;i<n;i++)
b[i] = 1;
for(int i=0;i<n;i++)
cin>>a[i];
sort(a,a+n);
int i=0;
b[0]  =1;
for(int i=0;i<n;i++){
    if(b[i] == 0)
    continue;
    else{
        b[i] = 1;
        for(int j=i+1;j<n;j++)
        if(a[j]%a[i] == 0)
        b[j] = 0;
    }
}
int count = 0;
for(auto val : b)
if(val == 1)
count++;
cout<<count;
return 0;
}