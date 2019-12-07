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
int n,k;
cin>>n>>k;
string s;
cin>>s;
int arr[n];
for(int i=0;i<n;i++)
arr[i] = 1;
int  i=0;
for(int i=97;i<=122 && k>0;i++){
    int j=0;
    while(j<n && k >0){
        if(s[j] == (char)i)
        {arr[j] = 0;k--;}
        j++;
    }
}
for(int i=0;i<n;i++){
    if(arr[i] == 1)
    cout<<s[i];
}
auto end = chrono::high_resolution_clock::now();
 double time_taken =  chrono::duration_cast<chrono::nanoseconds>(end - start).count();
 time_taken *= 1e-9; 
//cout <<fixed<< time_taken << setprecision(9); 
return 0;
}