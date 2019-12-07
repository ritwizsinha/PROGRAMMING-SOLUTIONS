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
int n,k;
cin>>n>>k;
int a[n];
vector<int> v;

for(int i=0;i<n;i++)
{cin>>a[i];
v.push_back(a[i]);
}
sort(begin(v),end(v),greater<int>());
vector<int> b;
b.assign(v.begin(),v.begin() + k);
int sum =0 ;
for(auto val : b)
sum+= val;
cout<<sum<<endl;
int i=0,size=0,count=0;
while(i<n){
    auto it = find(begin(b),end(b),a[i]);
    if(it!=b.end()){
        b.erase(it);
        size++;
        count++;
        if(count<=k-1)
        cout<<size<<" ";
        else
        {
            cout<<size + n-i -1<<" ";
        }
        
        size = 0; 
    }
    else
    {
        size++;
    }
    i++;

}


return 0;
}