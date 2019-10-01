//1216A
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
int count = 0;
int num = 0;

for(int i=1;i<n;i+=2){
if(s[i-1] == 'a' && s[i] == 'a'){
num++;
s[i] = 'b';
}
else if(s[i-1] == 'b' && s[i] == 'b'){
num++;
s[i] = 'a';

}
}

cout<<num<<endl;
cout<<s;
return 0;
}
