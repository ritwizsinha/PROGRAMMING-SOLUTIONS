#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<chrono>
#include<math.h>
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define endl "\n"
#define int long long
#define forn(i,n) for(long long i = 0; i < long long (n); ++i)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }
 vector<int> v;
int coins,all;
bool a[52][252];
int s[52][252];
int change(int i,int money){
    if(money < 0) return 0;
    if(money == 0) return 1;
    if(i == all) return 0;
    if(a[i][money] == false){
        s[i][money] = change(i+1,money) + change(i,money - v[i]);
        a[i][money] = true;
    }
    return s[i][money];
}

int32_t main()
{
IOS
int n;
cin>>n>>all;
for(int i=0;i<all;i++)
{
    int a;
    cin>>a;
    v.push_back(a);
}
cout<<change(0,n);
return 0;
}