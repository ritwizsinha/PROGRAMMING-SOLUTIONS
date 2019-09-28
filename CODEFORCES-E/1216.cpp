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
int q;
cin>>q;
string s;
int i=1;
while(s.size() <=600){
for(int j=1;j<=i;j++)
s+=to_string(j);
i++;
}
int arr[q];
for(int i=0;i<q;i++)
cin>>arr[i];
for(auto val : arr){
    
    cout<<s[val-1]<<endl;

}
return 0;
}