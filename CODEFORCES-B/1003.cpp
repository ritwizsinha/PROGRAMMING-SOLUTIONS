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
int a,b,x;
cin>>a>>b>>x;
string s;
while(x>1){ 
    if(s.size() == 0)
    {
        if(b>a){
            s+="1";
            b--;
        }
        else
        {
            s+="0";
            a--;
        }
    }
    else{
        if(s[s.size()-1] == '0'){
            s+="1";
            b--;
        }
        else
        {
            s+="0";
            a--;
        }
            x--;
    }

}
if(s[s.size()-1] == '0'){
    while(a){
        s+="0";
        a--;
    }
    while(b){
        s+="1";
        b--;
    }
}
else{
    while(b){
        s+="1";
        b--;
    }
    while(a){
        s+="0";
        a--;
    }
}
cout<<s;
return 0;
}
//Made a fucking stupid mistake by not finding what is what a 0 and b 1 not vice versa