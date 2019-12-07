//Done by myself

#include<bits/stdc++.h>
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define endl "\n"
#define int long long
#define forn(i,n) for(long long i = 0; i < long long (n); ++i)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }
struct size{
    int a,b;
};
bool compare(struct size x,struct size y)
{
    return (x.a - x.b) > (y.a - y.b);
}
int32_t main()
{
IOS
int n,m;
cin>>n>>m;
struct size f[n];
for(int i=0;i<n;i++)
cin>>f[i].a>>f[i].b;
sort(f,f+n,compare);
int sum=0;
for(auto val : f)
sum+=val.a;
int i=0;
while(sum > m){
sum-=f[i].a-f[i].b;
i++;
}
if(i>n)
cout<<-1;
else
{
    cout<<i;
}

return 0;
}