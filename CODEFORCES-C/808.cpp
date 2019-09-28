//Not submitted yet
// Not complete
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
int32_t main()
{
IOS
 auto start = high_resolution_clock::now(); 
 int n,w;
 cin>>n>>w;
 vector<int> v;
 int sum=0;
 for(int i=0;i<n;i++){
     int a;
     cin>>a;
     v.push_back(a);
     sum+=ceil((float)a/2);
 }
 vector<int> b;
 if(w<sum)
 cout<<-1;
 else
 {
     for(auto val : v){
         b.push_back(ceil((float)val/2));
         w-=ceil((float)val/2);
     }
     int i=0;
     vector<int> v2 = v;
     sort(begin(b),end(b),greater<int>());
     sort(begin(v2),end(v2),greater<int>());
     while (w>0)
     {  
         if(v2[i]>= b[i] +w)
         {
             b[i]+=w;
             w=0;
         }
         else if(v2[i] < b[i] + w){
             w-= (v2[i] -b[i]);
             b[i] = v2[i];
         }
         i++;

     }
     for(auto val : b)
     cout<<val << ' ';
     cout<<endl;
     for(auto val : v){
        auto it = find(begin(v2),end(v2),val) - begin(v2);
        cout<< b[it]<<" ";
     }
     
 }
auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
//cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
return 0;
}