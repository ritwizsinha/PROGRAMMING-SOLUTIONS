//done saw bit of solution //good question
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
int32_t main()
{
    IOS int n;
    cin >> n;
    int a[n];
    int lowestcm = 1;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        while(a[i]%2 == 0)
        a[i]/=2;
        while(a[i]%3 == 0)
        a[i]/=3;
    }
    for(int i=0;i<n;i++){
        if(a[0] != a[i]){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";

}