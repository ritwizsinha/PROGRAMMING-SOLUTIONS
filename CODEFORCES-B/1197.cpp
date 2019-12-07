//Done Myself
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <math.h>
#define MIN3(a, b, c) (a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c))
#define endl "\n"
#define int long long
#define forn(i, n) for (long long i = 0; i < long long(n); ++i)
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
using namespace std;
using namespace std::chrono;
inline bool is_palindrome(const string &s) { return std::equal(s.begin(), s.end(), s.rbegin()); }
int n, maxi;
vector<int> v;
int func(int a, int b)
{
    if (a < 0 && b >= n)
    {
        return 1;
    }
    if (a < 0)
    {
        if (v[b] > maxi)
            return 0;
        maxi = v[b];
        b++;
        return func(a, b);
    }
    if (b >= n)
    {
        if (v[a] > maxi)
            return 0;
        maxi = v[a];
        a--;
        return func(a, b);
    }
    if (max(v[b], v[a]) > maxi)
        return 0;
    if (v[b] > v[a])
    {
        maxi = v[b];
        b++;
        return func(a, b);
    }
    if (v[a] > v[b])
    {
        maxi = v[a];
        a--;
        return func(a, b);
    }
}
int32_t main()
{
    IOS auto start = high_resolution_clock::now();
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    int maxPos;
    maxi = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] > maxi)
        {
            maxi = v[i];
            maxPos = i;
        }
    }
    int a = func(maxPos - 1, maxPos + 1);
    cout << a;
    if (a == 1)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    //cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
    return 0;
}