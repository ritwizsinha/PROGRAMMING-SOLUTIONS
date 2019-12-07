#include<bits/stdc++.h>
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define endl "\n"
#define int long long
#define forn(i,n) for(long long i = 0; i < long long (n); ++i)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }
int32_t main()
{
IOS
int  n;
cin>>n;
int k= 2*n-2;
string s[k];

for(int i=0;i<k;i++)
cin>>s[i];
set<string> v;
for(int i=0;i<k;i++){
    for(int j=0;j<k;j++)
    if(s[i].size() + s[j].size() == n)
    v.insert(s[i] + s[j]);
}

 int flag=0;
string str2 ;
for(auto val : v){
            int flag2=0;
    for(int i=0;i<k;i++){

        if(s[i] == val.substr(0,s[i].size()) || s[i] == val.substr(val.size()-s[i].size(),val.size()-1))
        continue;
        else{
            flag2 = 1;
            break;
        }}
        if(flag2 == 1)
        continue;
        else{
            flag=1;
            str2 = val;
            break;
            }
}
int countS = 0,countP = 0;
string final ;
for(int i=0;i<k;i++){

        // if(s[i] == str2.substr(0,s[i].size()) && s[i] == str2.substr(str2.size()-s[i].size(),str2.size()-1))
        // {
        //     if(countS <= countP)
        //     {cout<<"S";countS++;}
        //     else
        //     {countP++;
        //         cout<<"P";
        //     }
            
        // }
        if(countP == countS){
            
        }
}
return 0;
}