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
int t;
cin>>t;
while(t--){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    int i=0,flag=1;
    while(i<n-1){
        if(v[i]>=v[i+1]){
            m+=v[i] - v[i+1];
            v[i] = v[i+1];
            if(v[i]>=k){
            m+=k;
            }
            else{
            m+=v[i];
            }
            i++;
        }
        else if(v[i+1]-v[i]<=k){
            if(v[i+1]<=k)
            m+=v[i];
            else
            m+=k + v[i] - v[i+1];
            i++;
        }
        else if( v[i+1] - v[i] > k && m>=v[i+1] - k -v[i])
        {
            m-= v[i+1] -k -v[i];
            i++;
        }
        else{
            flag = 0;
            break;
        }
    }
    if(flag == 1)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
    

}
return 0;
}