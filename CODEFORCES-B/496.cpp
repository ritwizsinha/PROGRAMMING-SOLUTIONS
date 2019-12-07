#include<bits/stdc++.h>
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define endl "\n"
#define int long long
#define forn(i,n) for(long long i = 0; i < long long (n); ++i)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }
string s1,s2;

int32_t main()
{
IOS

cin>>s1>>s2;
int i=s1.size(),j=s2.size();
while(s1[i] == s2[j] && i>=0 && j>=0){
    i--;j--;
}
int arr[100];

cout<< j+1 + i+1;
return 0;
}