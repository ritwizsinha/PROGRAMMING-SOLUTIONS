#include<bits/stdc++.h>
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define endl "\n"
#define int long long
#define forn(i,n) for(long long i = 0; i < long long (n); ++i)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }
struct number{
    int num;
    int pos;
};
bool compare(struct number n1,struct number n2){
    return n1.num > n2.num;
}
int32_t main()
{
IOS
int n;
cin>>n;
struct number a[n];
for(int i=0;i<n;i++){
    cin>>a[i].num;
    a[i].pos = i;
}
sort(a,a+n,compare);
int count=0;
for(int i=0;i<n;i++){
    count+= a[i].num*i +1;
}
cout<<count;
cout<<endl;
for(auto val :a)
cout<<val.pos+1<<" ";
return 0;
}