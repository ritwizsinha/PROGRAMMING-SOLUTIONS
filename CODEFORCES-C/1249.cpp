#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <chrono>
#include <assert.h>
#define MAX 1000001
#define pii pair<int, int>
#define F first
#define S second
#define all(s) begin(s), end(s)
#define MIN3POS(a, b, c) (a) = < (b) ? ((a) = < (c) ? 1 : 3) : ((b) = < (c) ? 2 : 3)
#define MAX3POS(a, b, c) (a) >= (b) ? ((a) >= (c) ? 1 : 3) : ((b) >= (c) ? 2 : 3)
#define endl '\n'
#define int long long
#define forn(i, n) for (long long i = 0; i < long long(n); ++i)
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
using namespace std;
vector<int> powers2(32, 0);
void initialize()
{
    for (int i = 1; i < powers2.size(); i++)
        powers2[i] = powers2[i - 1] * 2;
}
vector<long long> x, y;
void solve(const int &test_id)
{
    long long n, res = 0;
    cin >> n;
    while (n > 0)
    {
        int lb = lower_bound(y.begin(), y.end(), n) - y.begin();
        if (y[lb] == n)
        {
            res += y[lb];
            break;
        }
        else
        {
            res += x[lb];
            n -= x[lb];
        }
    }
    cout << res << endl;
}
void init()
{
    x.push_back(1);
    while (x[x.size() - 1] < 1e18)
        x.push_back(x[x.size() - 1] * 3);
    y = x;
    for (unsigned i = 1; i < y.size(); i++)
        y[i] = y[i - 1] + x[i];
}

void solve_cases()
{
    int test_cases = 1;
    cin >> test_cases;
    init();
    for (int i = 1; i <= test_cases; i++)
        solve(i);
}

inline bool is_palindrome(const string &s) { return std::equal(s.begin(), s.end(), s.rbegin()); }
int ret2(int n, bool &b)
{
    int count = -1;
    while (n != 0)
    {
        int rem = n % 3;
        if (rem == 2)
            b = true;
        n /= 3;
        count++;
    }
    return count;
}
int binpow(unsigned int a, unsigned int b)
{
    unsigned int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
int32_t main()
{
    auto start = chrono::high_resolution_clock::now();
    solve_cases();

    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    //cout << fixed << time_taken;
    return 0;
}