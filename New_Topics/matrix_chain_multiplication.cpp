#include <bits/stdc++.h>
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

int matrix_chain(int *arr, int n,int s[][10000])
{
    int dp[1000][1000];
    for (int i = 0; i < n; i++)
        dp[i][i] = 0;
    for (int l = 2; l < n; l++)
    {
        for (int i = 1; i < n - l + 1; i++)
        {
            int j = i + l - 1;
            dp[i][j] = __INT_MAX__;
            for (int k = i; k < j; k++){
                int q = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
                if(q<dp[i][j])
                dp[i][j] = q;
                s[i][j] = k;
            }
        }
    }
    return dp[1][n-1];

}
void print_optimal_parents(int s[][10000],int i,int j){
    if(i==j)
    cout<<"A"<<i;
    else{
        cout<<"(";
        print_optimal_parents(s,i,s[i][j]);
        print_optimal_parents(s,s[i][j]+1,j);
        cout<<")";
    }
}
main()
{
    IOS int n;
    cin >> n;
    int a[n];
    int s[n][10000];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << matrix_chain(a, n,s);
    return 0;
}