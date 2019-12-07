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
bool e(char a){
    if(a >= '1' && a<='2')
    return true;
    return false;
}
bool f(char a){
    if(a >= '3' && a<='6')
    return true;
    return false;
}
int32_t main()
{
auto start = chrono::high_resolution_clock::now(); 
IOS
int q;
cin>>q;
while(q--){
    int n;
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    char cur = 'U';
    int flag = 1;
    int l=0;
    while(l<n){
        if(cur == 'U'){
            if(e(s1[l]))
            l++;
            else if(f(s2[l]))
            {
                cur = 'D';
                l++;
            }
            else if(e(s2[l])){
                flag=0;
                break;
            }
        }
        else if(cur == 'D'){
            if(e(s2[l]))
            l++;
            else if(f(s1[l])){
                cur = 'U';
                l++;
            }
            else {
                flag=0;
                break;
            }
        }
    }
    if(flag == 0 || cur == 'U')
    cout<<"NO"<<endl;
    else 
    cout<<"YES"<<endl;
}
auto end = chrono::high_resolution_clock::now();
 double time_taken =  chrono::duration_cast<chrono::nanoseconds>(end - start).count();
 time_taken *= 1e-9; 
//cout <<fixed<< time_taken << setprecision(9); 
return 0;
}
