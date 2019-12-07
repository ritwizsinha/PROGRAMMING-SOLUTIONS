#include<bits/stdc++.h>
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define endl "\n"
#define int long long
#define forn(i,n) for(long long i = 0; i < long long (n); ++i)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
char change(char a,char b,char c){
    int x = b-97;
    int y = c-97;
    int num = rand()%26;
    while(num == x || num == y){
        num = rand()%26;
    }
    return (char)(97 + num);
}
inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }
int32_t main()
{
IOS
srand(time(0));
string s;
cin>>s;
for(int i=1;i<s.size()-1;i++)
if(s[i] == s[i-1] || s[i] == s[i+1])
s[i] = change(s[i],s[i-1],s[i+1]);
cout<<s;
return 0;
}