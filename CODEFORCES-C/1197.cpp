#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<chrono>
#include<math.h>
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define endl "\n"
#define int long long
#define forn(i,n) for(long long i = 0; i < long long (n); ++i)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
using namespace std::chrono;
inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }
vector<int> v;
int k;
int mini=0;
int func(int start,int mid,int end,int k){
    if(end-start+1 == k){
    return mini;
    }
    if(k==1){
    return mini + v[end] -v[start];}
    if(v[mid] - v[start] >= v[end] - v[mid+1] ){
        mini+=v[end] - v[mid+1];
        return func(start,(mid-start)/2,mid,--k);
    }
    mini+=v[mid] - v[start];
    return func(mid+1,(end+mid+1)/2,end,--k);
}
int32_t main()
{
IOS
 auto start = high_resolution_clock::now(); 
 int n,k;
 cin>>n>>k;
 for(int i=0;i<n;i++)
 {
     int a;
     cin>>a;
     v.push_back(a);
 }
 cout<<func(0,n/2,n-1,k);
auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
//cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
return 0;
}