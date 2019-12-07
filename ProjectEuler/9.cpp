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
int n=1000,a,b;
for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        if(i + j < 1000  && 2*n*(i+j) == n*n + 2*i*j)
        {
            a = i;
            b = j;
        }
    }
}
cout<<a*b*(n-a-b);
return 0;
}

// A better solution would be as each pythagorean triplet can be expressed as some multiple of 2mn , m^2-n^2 and m^2 + n^2
// so adding these we just find the first sum that us devisor of 1000 and thus the constant multiple is found
// Se discussions for details