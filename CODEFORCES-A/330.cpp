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
 int r,c;
 cin>>r>>c;
 if(r<=0 && c<=0)
 cout<<0;
 else{
 char ch[r][c];
 for(int i=0;i<r;i++){
     for(int j=0;j<c;j++)
     cin>>ch[i][j];
 }
 int count=0;
 for(int i=0;i<r;i++){
     int flag=0;
     for(int j=0;j<c;j++){
         if(ch[i][j]=='S')
         {
             flag=1;
             break;
         }
     }
     if(flag==0)
     count++;
 }

 int total = count*c;
 int rr = r-count;
 count=0;
 for(int i=0;i<c;i++){
     int flag=0;
     for(int j=0;j<r;j++){
         if(ch[j][i]=='S'){
             flag=1;
             break;
         }
     }
     if(!flag)
     count++;
 }

 total+=count*rr;
 cout<<total;
 }
auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
//cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
return 0;
}