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
    IOS int sum = 0;
    string s2(100, '0');
    for (int i = 0; i < 2; i++)
    {
        string s;
        cin >> s;
        cout<<s<<endl;
        int j = s.size() - 1;
        while (j >= 0)
        {
            cout<<s[j] - 48<<endl;
            // s2[50 + j] = ((s2[50 + j] + s[j] - 96) % 10);
            // s2[49 + j] = s2[49 + j] + (s2[50 + j] + s[j]) / 10;
            j--;
        }
        cout<<"end"<<endl;
    }
    //cout << s2;
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << fixed << time_taken << setprecision(9);
    return 0;
}
// A good solution
