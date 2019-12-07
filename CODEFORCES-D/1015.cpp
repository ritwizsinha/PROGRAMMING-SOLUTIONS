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
    IOS int n, k, s;
    cin >> n >> k >> s;
    int redHome = s / (n - 1);
    int rem = s % (n - 1);
    if (rem == 0 && redHome > k || rem != 0 && redHome + 1 > k)
        cout << "NO";
    else
    {
        cout << "YES" << endl;
        if (k - redHome > rem)
        {
            rem += n - 1;
            redHome--;
        }
        for (int i = 1; i <= redHome; i++)
        {
            if (i % 2 == 0)
                cout << 1 << " ";
            else
                cout << n << " ";
        }
        k -= redHome;
        int pos;
        if (k != 0)
        {
            if (redHome % 2 == 0)
            {
                pos = 1;
                for (int i = 1; i < k; i++)
                    cout << ++pos << " ";
                int newPos = pos + rem - k + 1;
                if (newPos > n)
                {
                    if (2 * n - newPos == pos)
                        cout << pos - rem + k - 1 << " ";
                    else
                    {
                        cout << 2 * n - newPos << " ";
                    }
                }
                else
                {
                    cout << newPos;
                }
            }

            else
            {
                pos = n;
                for (int i = 1; i < k; i++)
                    cout << --pos << " ";

                if (rem - k + 1 >= pos)
                {
                    cout << rem - k + 2 - pos;
                }
                else
                {
                    cout << pos - rem + k - 1;
                }
            }
        }
    }
    return 0;
}