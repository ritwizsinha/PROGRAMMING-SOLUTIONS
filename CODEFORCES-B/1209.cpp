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
string s;
cin>>s;
string s1 = s;
int a[n],b[n];
for(int i=0;i<n;i++)
cin>>a[i]>>b[i];
int min= 100000000;
for(int i=0;i<n;i++){
    if(b[i] < min)
    min = b[i];
}
int i=min;
while(1){
    for(int j=0;s1[j];j++){
        if(s[j] == 1)
        {
            if(i%b[j] == 0)
            s[j] == 0;
        }
        if(s[j] == 0)
    }
    }
return 0;
}