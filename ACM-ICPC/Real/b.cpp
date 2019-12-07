#include<bits/stdc++.h>
#include<chrono>
#define MAX 1000001
#define pii pair<int,int>
#define F first
#define S second
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define endl "\n"
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
    int n;
    cin>>n;
    map<string,int> mp;
    map<string,int>mp1;
    map<string,int>mp2;
    for(int i=0;i<n;i++){
    string s;
    int t;
    cin>>s>>t;
    mp[s]=1;
    if(t== 0)
    mp1[s] +=1;
    else
    mp2[s]+=1;
}
int count = 0;
for(auto ss  : mp)
{
    if(mp1.find(ss.first) != mp1.end() && mp2.find(ss.first) != mp2.end()){
    count+=max(mp1[ss.first],mp2[ss.first]);
    }
    else if(mp1.find(ss.first) != mp1.end())
    count+=mp1[ss.first];
    else
    {
        count+=mp2[ss.first];
    }
    
}
cout<<count<<endl;

}

auto end = chrono::high_resolution_clock::now();
 double time_taken =  chrono::duration_cast<chrono::nanoseconds>(end - start).count();
 time_taken *= 1e-9; 
//cout <<fixed<< time_taken << setprecision(9); 
return 0;
}