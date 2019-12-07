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
int max = 0;
char a,b;
for(int i=0;i<n-1;i++){
    int count = 0;
    for(int j=0;j<n-1;j++){
        if(s[i] == s[j] && s[i+1] == s[j+1])
        count++;
    }
    if(count > max){
        a= s[i];
        b = s[i+1];
        max = count;
    }
}
cout<<a<<b;
return 0;
}