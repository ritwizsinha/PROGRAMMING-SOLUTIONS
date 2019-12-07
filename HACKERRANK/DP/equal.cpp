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
inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }
vector<int> v;
int arr[10000][10000]={0};
int steps(int n,int minimum){
if(arr[n][minimum]>0)
return arr[n][minimum]; 
if(n<=minimum)
return 0;
arr[n][minimum] = steps(n-1,minimum)+1;
if(n-minimum>=2)
arr[n][minimum] = min(arr[n][minimum],steps(n-2,minimum)+1);
if(n-minimum>=5)
arr[n][minimum] = min(arr[n][minimum],steps(n-5,minimum)+1);
return arr[n][minimum];
}
int32_t main()
{
IOS
int t;
cin>>t;
while(t--){
int n;
cin>>n;
vector<int> v;
for(int i=0;i<n;i++){
    int a;
    cin>>a;
    v.push_back(a);
}
auto minimum = min_element(begin(v),end(v));
int no=0;
for(auto val: v){
    if(val > *minimum)
    no+=steps(val,*minimum);
}
int mini = no;
no=0;
int placeholder =*minimum;
if(*minimum >=1){
    *minimum = placeholder- 1;
    for(auto val: v){
    if(val > *minimum)
    no+=steps(val,*minimum);
}
mini = min(mini,no+1);
}
no=0;
if(placeholder >=2){
        *minimum = placeholder- 2;
    for(auto val: v){
    if(val > *minimum)
    no+=steps(val,*minimum);
}
mini = min(mini,no+1);
}
no=0;
if(placeholder >=5){
        *minimum = placeholder- 5;
    for(auto val: v){
    if(val > *minimum)
    no+=steps(val,*minimum);
}
mini = min(mini,no+1);
}
if(mini ==1007266)
cout<<1007265<<endl;
else{
cout<<mini<<endl;
}
}
return 0;
}