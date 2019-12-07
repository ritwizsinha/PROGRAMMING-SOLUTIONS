#include<bits/stdc++.h>
#include<chrono>
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define endl "\n"
#define int long long
#define forn(i,n) for(long long i = 0; i < long long (n); ++i)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }
int32_t main()
{
auto start = chrono::high_resolution_clock::now(); 
IOS
int t;
cin>>t;
while(t--){
    int n,r;
    cin>>n>>r;
    int mx = 0;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    sort(begin(v),end(v));
    auto ip =  unique(begin(v),end(v));
    v.resize(distance(v.begin(), ip)); 
    n = ip - begin(v);
    int ans = 0;
    for(int i=n-1;i>=0;i--)
    ans+=(v[i] - ans*r > 0);

    cout<<ans<<endl;
}
auto end = chrono::high_resolution_clock::now();
 double time_taken =  chrono::duration_cast<chrono::nanoseconds>(end - start).count();
 time_taken *= 1e-9; 
//cout <<fixed<< time_taken << setprecision(9); 
return 0;
}