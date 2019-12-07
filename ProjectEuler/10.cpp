#include<bits/stdc++.h>
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define endl "\n"
#define int long long
#define forn(i,n) for(long long i = 0; i < long long (n); ++i)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }
bool isPrime(int i){
    for(int j=3;j*j<=i;j++)
    {
        if(i%j == 0)
        return false;
    }
    return true;
}
int32_t main()
{
IOS
int n = 2000000,sum=0;
for(int i=3;i<n;i+=2){
if(isPrime(i))
sum+=i;
}
cout<<sum+2;
return 0;
}