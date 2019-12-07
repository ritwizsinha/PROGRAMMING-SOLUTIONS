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
int q;
cin>>q;
while(q--){
    int n,m;
    cin>>n>>m;
    int N = n/m;
    int cum[11];
    cum[0] = 0;
    for(int i=1;i<=10;i++)
    cum[i]  =  cum[i-1] + (m*i)%10;
    cout<<(N/10)*cum[10] + cum[N%10]<<endl;
}
auto end = chrono::high_resolution_clock::now();
 double time_taken =  chrono::duration_cast<chrono::nanoseconds>(end - start).count();
 time_taken *= 1e-9; 
//cout <<fixed<< time_taken << setprecision(9); 
return 0;
}