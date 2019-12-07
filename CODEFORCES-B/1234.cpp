#include<bits/stdc++.h>
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define endl "\n"
#define int long long
#define forn(i,n) for(long long i = 0; i < long long (n); ++i)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }
void showq(queue <int> gq) 
{ 
    queue <int> g = gq; 
    while (!g.empty()) 
    { 
        cout << '\t' << g.front(); 
        g.pop(); 
    } 
    cout << '\n'; 
} 
int32_t main()
{
IOS
int n,k;
cin>>n>>k;
int a[n];
map<int,int> mp;
for(int i=0;i<n;i++)
{cin>>a[i];
mp[a[i]]++;
}
vector<int> v2;
int size = 0;
for(int i=0;i<n;i++){
    if(mp[a[i]] !=-1 && size <k){
    v2.push_back(a[i]);
    size++;
    mp[a[i]] = -1;
    }
}
cout<<v2.size()<<endl;
for(int i=v2.size()-1;i>=0;i--)
cout<<v2[i]<<" ";

return 0;
}