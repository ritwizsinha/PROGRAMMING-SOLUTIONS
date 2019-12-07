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
int a[20][20];
for(int i=0;i<20;i++){
    for(int j=0;j<20;j++)
    cin>>a[i][j];
}
int mx = 0;
for(int i=3;i<=16;i++){
    for(int j=3;j<=16;j++){
        int arr[10],k=0;
      arr[k++] = a[i][j+1]*a[i][j+2]*a[i][j+3]*a[i][j];
      arr[k++] = a[i][j]*a[i][j-1]*a[i][j-2]*a[i][j-3];
      arr[k++] = a[i+1][j]*a[i+1][j]*a[i+3][j]*a[i][j];
      arr[k++] = a[i][j+1]*a[i][j+2]*a[i][j+3]*a[i][j];
      arr[k++] = a[i][j]*a[i+1][j+1]*a[i+2][j+2]*a[i+3][j+3];
      arr[k++] = a[i-1][j-1]*a[i][j]*a[i-2][j-2]*a[i-3][j-3];
      arr[k++] = a[i][j]*a[i+1][j-1]*a[i-2][j-2]*a[i-3][j-3];
      arr[k++] = a[i][j]*a[i-1][j+1]*a[i-2][j+2]*a[i-3][j+3];
      for(auto ar : arr){
          mx = max(mx,ar);
      }
    }
}
cout<<mx;
return 0;
}
// A very irritating question , not done by myself12