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
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int l = 0, r = n - 1;
    int sum1 = a[l], sum2 = a[r];
    int x = -1, y = n - 1;
    while (l < r)
    {
        if (sum1 < sum2)
        {
            l++;
            sum1 += a[l];
        }
        else if (sum1 > sum2)
        {
            r--;
            sum2 += a[r];
        }
        else if (sum1 == sum2)
        {
            x = l, y = r;l++;
            r--;
            sum1 += a[l];
            sum2 += a[r];
        }
    }   
    int sumz = 0;
    if(x!=-1){
    for (int i = 0; i <= x; i++)
        sumz += a[i];
    cout << sumz;
    }    else
    {
        cout<<0;
    }
    
    return 0;
}