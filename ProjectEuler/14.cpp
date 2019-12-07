#include <bits/stdc++.h>
#include <chrono>
#define MIN3(a, b, c) (a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c))
#define endl "\n"
#define int long long
#define forn(i, n) for (long long i = 0; i < long long(n); ++i)
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
using namespace std;
inline bool is_palindrome(const string &s) { return std::equal(s.begin(), s.end(), s.rbegin()); }
int MAX = 1000001;
unsigned long long dp[5000001];

int func(int i){
    int steps = 0; 
    if(i >5000000){
        while(i>5000000){
            if(i & 1){
                steps+=2;
                i = (3*i+1) >> 1;
            }
            else
            {
                steps++;
                i=i>>1;
            }
            
        }
        return steps + func(i);
    }
    if(dp[i] == -1){
            if( i & 1){
            dp[i] = 2 + func((3*i+1)>>1);
            }
            else
            dp[i]  = 1 + func(i>>1);
            }
            return dp[i];
            
}

int32_t main()
{
    auto start = chrono::high_resolution_clock::now();
    IOS 
    for(int i=0;i<5000001;i++)
    dp[i] = -1;
        int t;
    cin>>t;
    dp[0] = 0; dp[1] = 0;

    for(int i=2;i<=5000000;i++)
    int a  = func(i);
    while(t--){
        int n;
        cin>>n;
        int mx = 0,pos;
        for(int i=0;i<=n;i++){
            if(dp[i] >= mx){
                mx = dp[i];
                pos = i;
            }
        }
        cout<<pos<<endl;
    } 
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << endl<< fixed << time_taken << setprecision(20);
    return 0;
}
