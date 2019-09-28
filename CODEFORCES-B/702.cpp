#include<iostream>
#include<string>
#include<math.h>
#include<vector>
#include<algorithm>
#include<chrono>
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define endl "\n"
#define int long long
#define forn(i,n) for(long long i = 0; i < long long (n); ++i)
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
 vector<int> v(n);
 for(int i=0;i<n;i++)
 cin>>v[i];
  vector<int> pow2;
 for(int i=0;i<30;i++)
 pow2.push_back(pow(2,i+1));
//  for(auto val : pow2)
//  cout<<val<<endl;
sort(begin(v),end(v));
int count=0;
for(auto it = v.begin();it!=v.end();it++){
    for(auto mul: pow2){
        auto iter = it;
        auto it2 = lower_bound(++iter,v.end(),mul-*it);
        // cout<<(int)(it2-v.begin())<<endl<<"value is  "<<*it2<<endl ;
        if(*it2 == mul - *it){
            auto it3 = upper_bound(iter,v.end(),*it2);
            // cout<<it3 - it2<<endl;
            count+= (int)(it3 - it2);
            // cout<<"value inside if  "<<*it2<<endl;
        }
 }

}
cout<<count;
auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
//cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
return 0;
}