#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<chrono>
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define endl "\n"
#define int long long
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
using namespace std::chrono;
inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }
int32_t main()
{
IOS
 auto start = high_resolution_clock::now(); 
 int n,price;
 vector<int> v;
 int count=0;
 cin>>n>>price;
 for(int i=0;i<n;i++){
     int a;
     cin>>a;
     for(int j=0;j<a;j++){
         int b;
         cin>>b;
         if(b<price){
             v.push_back(i+1);
             count++;
             break;
         }
     }
 }
 cout<<count<<endl;
 for(int i=0;i<v.size();i++)
 cout<<v[i]<<" ";
auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
//cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
return 0;
}