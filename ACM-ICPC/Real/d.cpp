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
int32_t main()
{
auto start = chrono::high_resolution_clock::now(); 
IOS
int t;
cin>>t;
while(t--){
    int n,k;
    map<char,vector<int> > v;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<string> s2;
    map<string,map<char,int> > mp;
    for(int i=0;i<k;i++)
    {
        cin>>s2[i];
        map<char,int>  mp2;
        for(auto aa : s2[i])
        {

            mp2[aa]++;
        }
        mp[s2[i]] = mp2;
     }
     for(char c = 'a';c<='t';c++){
                      vector<int> v2;
         for(int i=0;i<k;i++)
         {

             if(mp[s2[i]][c] > 0)
             v2.push_back(i+1);
         }
         v[c] = v2;
     }
       
    int i=0;
    while(i<n){
         vector<int> v3 = v[s2[i]];
         while(v3.size() !=0 || i<n-1){
             cout<<v3[0]<<" ";
             vector<int> v6;
              l = set_intersection(v3.begin(),v3.end(),v[s2[i+1]].begin(),v[s2[i+1]].end(),v6.begin());

             v3 = v6;
             i++;
         }
    }
}
auto end = chrono::high_resolution_clock::now();
 double time_taken =  chrono::duration_cast<chrono::nanoseconds>(end - start).count();
 time_taken *= 1e-9; 
cout <<fixed<< time_taken << setprecision(9); 
return 0;
}