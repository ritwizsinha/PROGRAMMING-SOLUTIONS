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
int multdigits(int n){
    int mul=1;
    while(n){
        mul*=n%10;
        n/=10;
    }
    return mul;
}
int mulString(string s){
    int mul = 1;
    for(auto ch : s){
        mul*= (ch-48);
    }
    return mul;
}
int charToInt(char c){
    return (int)c-48;
}
int32_t main()
{
IOS
 auto start = high_resolution_clock::now(); 
string s;
cin>>s;
int max = 0;
int pointer = s.size()-1;
int mul  = mulString(s);
cout<<mul;
while(pointer !=0){
     
}
cout<<max;

auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
//cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
return 0;
}