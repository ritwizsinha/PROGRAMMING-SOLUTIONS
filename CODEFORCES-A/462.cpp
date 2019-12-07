#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<chrono>
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define endl "\n"
#define int long long
#define forn(i,l,r) for(long long i = l; i < r; ++i)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
using namespace std::chrono;
inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }
int32_t main()
{
IOS
 auto start = high_resolution_clock::now(); 
 int n;
 cin>>n;
 char a[n][n];
 forn(i,0,n){
     forn(j,0,n){
         cin>>a[i][j];
 }}
 int flag=0;
 for(int i=1;i<=n-2;i++){
     for(int j=1;j<=n-2;i++){
         int count=0;
         if(a[i+1][j] == 'o')
            count++;
        if(a[i-1][j] == 'o')
        count++;
        if(a[i][j+1] == 'o')
        count++;
        if(a[i][j-1] == 'o')
        count++;
        cout<<count;
        if(count%2 ==1)
         {
             flag=1;
             break;
         }
     }
     if(flag==1)
     break;
 }
 if(flag==1){
     cout<<"NO";
 }
 else
 {
     cout<<"YES";
 }
 
auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
//cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
return 0;
}