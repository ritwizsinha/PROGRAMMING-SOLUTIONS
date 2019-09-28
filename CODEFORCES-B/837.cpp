#include<bits/stdc++.h>
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define endl "\n"
#define int long long
#define forn(i,n) for(long long i = 0; i < long long (n); ++i)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }
void array_nullify(int **arr,int l,int m){
for(int i=0;i<l;i++){
    for(int j=0;j<m;j++)
    arr[i][j] = 0;
}
}
int32_t main()
{
IOS
int n;
cin>>n;
string s;
cin  >> s;
int c[n] = {};
for(int i=0;i<n;i++){
    int cnt = 0;
    if(s[i] == '1')
    cnt++;
    else
    cnt--;
    c[i] = cnt;
}
int mx =0;
    map<int, int>mp;
    mp[0] = 0;
    for(int i = 1; i <= n; i++){
        if(mp.find(c[i]) != mp.end()){
            mx = max(mx, i - mp[c[i]]);
        }
        else mp[c[i]] = i;
    }
cout<<mx;
 return 0;
}