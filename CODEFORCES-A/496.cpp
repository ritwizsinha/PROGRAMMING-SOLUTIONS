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
int count= 0;
int a[n];
for(int i=0;i<n;i++)
cin>>a[i];
int b[n];
int k=0;
for(int i=0;i<n;i++){
    if(a[i] == 1)
    {
        count++;
        b[k++] = i;wedwd
    }
}
cout<<count<<endl;
for(int i=0;i<k-1;i++){
    cout<<b[i+1]-b[i]<<" ";
}
cout<<n-b[k-1];
return 0;
}