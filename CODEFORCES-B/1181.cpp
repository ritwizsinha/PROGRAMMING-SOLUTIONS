#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<chrono>
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define endl "\n"
#define int long long
#define forn(i,n) for(long long i = 0; i <n; ++i)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
using namespace std::chrono;
inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }

int32_t main()
{
IOS
int n;
cin>>n;
vector<int> v(0,n);
for(int i=0;i<n;i++)
cin>>v[i];
// For odd
if(n & 1){
int i =n/2;j=i-1;
while(v[i]==0) i++;
while(v[j]==0) j--;
j--;
vector<int> v2
v2.assign(begin(v),begin(v)+j);
vector<int> v3
v3.assign(begin(v)+i,end(v));
}
//For even
else{

}
auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
//cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
return 0;
}