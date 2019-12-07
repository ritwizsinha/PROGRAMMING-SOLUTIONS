//Easy as shit
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
int sumDigits(int n){
    int sum =0;
    while(n){
        sum+=n%10;
        n/=10;
    }
    return sum;
}
int32_t main()
{
IOS
 auto start = high_resolution_clock::now(); 
 int a;
 cin>>a;
    while(sumDigits(a)%4!=0){
        a++;
    }
    cout<<a;


auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
//cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
return 0;
}