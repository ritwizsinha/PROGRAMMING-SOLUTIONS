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
int n;
cin>>n;
vector<int> v;
 
for(int i=0;i<n;i++)
{
    int a;
    cin>>a;
    v.push_back(a);
}

int count=0;
int status[n] = {0};
int mx  = v[v.size()-1];

sort(begin(v),end(v));
for(int i=0;i<n;i++){
    int flag=0;
    int pow = 1;
    for(int j=0;j<=32;j++,pow*=2){
        if(pow > v[i]){
            if(pow>v[i] && pow-v[i]!=v[i])
			{
				if(binary_search(v.begin(),v.end(),pow-v[i]))
				{
					flag=1;
					break;
				}
			}
			if(pow-v[i]==v[i])
			{
				if(*(++lower_bound(v.begin(),v.end(),pow-v[i]))==v[i])
				{
					flag=1;
					break;
				}
			}
        }}
        if(flag==0)
        count++;
        }
cout<<count;
return 0;
}