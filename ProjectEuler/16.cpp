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
int n;
cin>>n;
int a[400] =  {};
a[0] = 1;
for(auto val : a)
cout<<val<<" ";
cout<<endl;
for(int i=1;i<=n;i++){
    int carry = 0;
for(int i=0;i<400;i++){
    int temp = (a[i]*2  + carry);
    a[i] = (temp)%10;
    carry = temp/10;
}}
int sum = 0;
for(auto val : a)
sum+=val; 
cout<<sum<<endl;
}
auto end = chrono::high_resolution_clock::now();
 double time_taken =  chrono::duration_cast<chrono::nanoseconds>(end - start).count();
 time_taken *= 1e-9; 
//cout <<endl<<fixed<< time_taken << setprecision(9); 
return 0;
}