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

int32_t main()
{
    auto start = chrono::high_resolution_clock::now();
    IOS int q;
    cin >> q;
    while (q--)
    {
        int h, n;
        cin >> h >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        int count = 0;
        int i = 0;
        while (i < n)
        {
            if (v[i] <= 2)
                break;
            if (v[i] == (v[i + 1] + 1))
                i += 2;
            else
            {
                count++;
                i++;
            }
        }
        cout << count << endl;
    }
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    ///cout <<fixed<< time_taken << setprecision(9);
    return 0;
}