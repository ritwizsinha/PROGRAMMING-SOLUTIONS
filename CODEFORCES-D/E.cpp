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
int t;
cin>>t;
while(t--){
int x1,y1,x2,y2;
cin>>x1>>y1>>x2>>y2;
if(x1 == x2 && y2 > y1)
cout<<"up"<<endl;
else if( x1 == x2 && y2 < y1)
cout<<"down"<<endl;
else if(y1 == y2 && x2 > x1)
cout<<"right"<<endl;
else if( y1 == y2 && x2 < x1)
cout<<"left"<<endl;
else 
cout<<"sad"<<endl;

}
auto end = chrono::high_resolution_clock::now();
 double time_taken =  chrono::duration_cast<chrono::nanoseconds>(end - start).count();
 time_taken *= 1e-9; 
//cout <<fixed<< time_taken << setprecision(9); 
return 0;
}