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
 string s1,s2;
 cin>>s1>>s2;
 int s_1[26]={0},s_2[26]={0};
 for( char s : s1)
 s_1[(int)s-97]++;

 for( char s : s2)
 s_2[(int)s-97]++;
bool automaton=false ;
for(char s : s2){
    if(s_1[(int)s - 97] == 0){
        cout<<"need tree";
        return 0;
    }
    
}
if(s1.size() > s2.size())
automaton = true;
if(s1.find(s2)!=string::npos){
    cout<<"automaton";
}
else{
    if(automaton)
    cout<<"both";
    else
    {
        cout<<"array";
    }
    
}
auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
//cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
return 0;
}