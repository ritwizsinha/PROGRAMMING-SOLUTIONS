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
int sum[n] = {};
for(int i=0;i<n;i++){
cin>>a[i];
}
sum[0] = a[0];
for(int i=1;i<n;i++)
sum[i] = sum[i-1] + a[i];
double mx = 0;
  for(int i=k;i<=n;i++)
  {
for(int j=0;j<=n-i;j++)
{
   double s;
   if(j==0)
      s=sum[j+i-1];
   else
   s=sum[j+i-1]-sum[j-1];
   double m=(double)(s/i);
    if(m > mx)
    mx = m;
}
  }

cout<<fixed<<std::setprecision(15)<<mx;
return 0;
}
