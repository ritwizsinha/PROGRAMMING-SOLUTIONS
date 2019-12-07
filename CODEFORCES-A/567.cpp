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
int a[n];
for(int i=0;i<n;i++)
cin>>a[i];
for(int i=0;i<n;i++){
    if(i==0){
        cout<<a[i+1] - a[i]<<" "<<a[n-1] - a[i]<<endl;
    }
    if(i == n-1)
    cout<<abs(a[i-1] - a[i])<<" "<<abs(a[0] - a[i])<<endl;
    else
    {
        cout<<min(abs(a[i-1] - a[i]),abs(a[i+1] - a[i]))<<" "<<max(abs(a[n-1] - a[i]),abs(a[0] - a[i]))<<endl;
    }
    
}
auto end = chrono::high_resolution_clock::now();
 double time_taken =  chrono::duration_cast<chrono::nanoseconds>(end - start).count();
 time_taken *= 1e-9; 
//cout <<fixed<< time_taken << setprecision(9); 
return 0;
}