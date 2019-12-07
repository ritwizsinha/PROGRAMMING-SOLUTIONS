
#include<bits/stdc++.h>
#include<chrono>
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define endl "\n"
#define int long long
#define forn(i,n) for(long long i = 0; i < long long (n); ++i)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }

int div(int i){
    int count=0;
    if(sqrt(i) * sqrt(i) - i == 0)
    count++;
    for(int j =2;j*j<i;j++)
    if(i%j==0)
    count+=2;
    return count+2;
}
int32_t main()
{
auto start = chrono::high_resolution_clock::now(); 
IOS
int sum=0,i=1;
while(div(sum)<=500){
sum+=i;
i++;
}
cout<<sum<<endl;
auto end = chrono::high_resolution_clock::now();
 double time_taken =  chrono::duration_cast<chrono::nanoseconds>(end - start).count();
 time_taken *= 1e-9; 
cout <<fixed<< time_taken << setprecision(9); 
return 0;
}
//done