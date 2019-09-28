#include<iostream>
#include<string>
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
vector< pair<int, int> > v1,v2;
for(int i=0;i<n;i++){
    int a,b;
    cin>>a>>b;
    v1.push_back(make_pair(a,b));
    v2.push_back(make_pair(a*i + b*(n-i-1),i));
}
    sort(begin(v2),end(v2));
cout<<v2[0].first;
auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
//cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
return 0;
}