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
int a[7],sum=0;
for(int i=0;i<7;i++)
{cin>>a[i];sum+=a[i];}
int c  = n > sum ? n%sum : n;
if(c == 0){
    int sum2 =0;
for(int i=0;i<7;i++){
    sum2+=a[i];
    if(sum2 == sum)
    {
        cout<<i+1;
        break;
    }
}
}
else{
for(int i=0;i<7;i++){
    if(c <=a[i]){
        cout<<i+1;
        break;
    }
    else
    {
        c-=a[i];
    }
    
}
}
auto end = chrono::high_resolution_clock::now();
 double time_taken =  chrono::duration_cast<chrono::nanoseconds>(end - start).count();
 time_taken *= 1e-9; 
//cout <<fixed<< time_taken << setprecision(9); 
return 0;
}