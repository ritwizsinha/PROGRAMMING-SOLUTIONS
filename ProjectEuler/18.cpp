#include<bits/stdc++.h>
#include<chrono>
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define endl "\n"
#define int long long
#define forn(i,n) for(long long i = 0; i < long long (n); ++i)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }
vector<vector<int> > v;
int n;
int dp[101][101];
// int fun(int h,int pos){
//     if(dp[h][pos] ==0){
//         if(h==n-1)
//         dp[h][pos] = 
//         int mx = 0;
//         for(int i=0;i<=h+1;i++){
//             mx = max(mx,v[h][pos] + fun(h+1,i));
//         }
//             dp[h][pos] = mx;
    
//     }
//     return dp[h][pos];
// }
int32_t main()
{
auto start = chrono::high_resolution_clock::now(); 
IOS
cin>>n;
for(int i=1;i<=n;i++){
    vector<int> v2; 
    for(int j=1;j<=i;j++){
        int a;
        cin>>a;
        v2.push_back(a);
    }
    v.push_back(v2);
}
for(int i=0;i<=n-1;i++)
dp[n-1][i] = v[n-1][i];
int mx = 0;
for(int i=n-2;i>=0;i--){
    for(int j=0;j<=i;j++)
    dp[i][j] = max(dp[i][j],max(v[i][j] + dp[i+1][j], v[i][j] + dp[i+1][j+1]));
}
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
    cout<<dp[i][j]<<" ";
    cout<<endl;
}
cout<<endl;
cout<<dp[0][0]<<endl;

// int num  = fun(0,0);


// cout<<num<<endl;
auto end = chrono::high_resolution_clock::now();
 double time_taken =  chrono::duration_cast<chrono::nanoseconds>(end - start).count();
 time_taken *= 1e-9; 
cout <<fixed<< time_taken << setprecision(9); 
return 0;
}

//Succesfully solves problem 18 and 67 using dp
// Read thread for https://mathschallenge.net/archive