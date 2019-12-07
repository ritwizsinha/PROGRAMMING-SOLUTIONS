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
int n,m;
cin>>n>>m;
int a[n],b[n];
for(int i=0;i<n;i++)
cin>>a[i]>>b[i];
int k=0;
vector<int> v;
for(int i=1;i<=m;i++){
    int count=0;
    for(int  j=0;j<n;j++){
        if(i<=b[j] && i >= a[j])
        count++;
    }
    if(count == 0){
        k++;
        v.push_back(i);
    }
}
if(k==0)
cout<<0;
else
{
    cout<<k<<endl;
    for(auto val : v)
    cout<<val<<" ";
}

return 0;
}