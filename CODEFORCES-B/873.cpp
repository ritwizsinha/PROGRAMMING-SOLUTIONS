#include<bits/stdc++.h>
#include<chrono>
#define MAX 1000001
#define pii pair<int,int>
#define F first
#define S second
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
int n;
cin>>n;
string s;
cin>>s;
// if(s == "10" || s == "01")
// cout<<2;

int arr[n],k=0;

for(auto chr: s)
{
    if(chr == '1')
    arr[k++] = 1;
    else
    arr[k++] = -1;
}
int cum[n+1];
cum[0] = 0;

for(int i=0;i<n;i++)
cum[i+1] = cum[i] + arr[i];
map<int ,vector<int> > mp;
for(int i=0;i<=n;i++)
mp[cum[i]].push_back(i);
for(auto m : mp)
sort(begin(m.second),end(m.second));
int mx = 0;
for(auto m : mp){
    mx = max(mx,m.second[m.second.size()-1]  -m.second[0]);
}
cout<<mx;

auto end = chrono::high_resolution_clock::now();
 double time_taken =  chrono::duration_cast<chrono::nanoseconds>(end - start).count();
 time_taken *= 1e-9; 
//cout <<fixed<< time_taken << setprecision(9); 
return 0;
}