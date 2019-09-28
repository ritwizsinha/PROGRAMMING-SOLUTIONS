`#include <bits/stdc++.h>
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
    IOS int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], b[2][n];
        string s;
        cin >> s;
        if (s.size() == 1)
            cout << 1 << endl;
        else
        {
            for (int i = 0; i < n; i++)
            {
                a[i] = s[i] - 48;
                b[0][i] = a[i];
            }
            sort(a, a + n);
            int l1 = 0, l2 = 0;
            while (l1 < n && l2 < n)
            {
                if (a[l1] == b[0][l2])
                {
                    b[1][l2] = 1;
                    l1++, l2++;
                }
                else
                {
                    b[1][l2] = 2;
                    l2++;
                }
            }
            int flag = 0;
            vector<int> v;
            for (int i = 0; i < n - 1; i++)
            {
                if (b[1][i] == 2)
                {
                    v.push_back(b[0][i]);
                }
            }
            if (v.size() == 0)
            {
                for (int i = 0; i < n; i++)
                    cout << 2;
                    cout<<endl;
            }
            else
            {
                for (int i = 0; i < v.size() - 1; i++)
                {
                    if (v[i] > v[i + 1])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 1)
                {
                    cout << "-" << endl;
                }
                else
                {
                    for (auto val : b[1])
                        cout << val;
                        cout<<endl;
                }

            }
        }
    }
    return 0;
}