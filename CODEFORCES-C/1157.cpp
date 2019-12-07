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
#define forn(i, n) for (long long i = 0; i < n; ++i)
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
inline bool is_palindrome(const string &s) { return std::equal(s.begin(), s.end(), s.rbegin()); }
vector<char> s;
int32_t main()
{
    auto start = chrono::high_resolution_clock::now();
    IOS int n;
    cin >> n;
    int a[n];
    forn(i, n)
            cin >>
        a[i];
    int l = 0, r = n - 1;
    int buf = 0;
    vector<char> s;
    while (l <= r)
    {
        if(l == r)
        s.push_back('R'),l++;
        if (buf > a[l] && buf > a[r])
            break;
        else if (buf > a[l] && buf < a[r])
        {
            while (a[r - 1] > a[r] && r >= l)
            {
                s.push_back('R');
                r--;
            }
        }
        else if (buf < a[l] && buf > a[r])
        {
            while (a[l + 1] > a[l] && l <= r)
            {
                s.push_back('L');
                l++;
            }
        }
        else if (a[l] > buf && a[r] > buf)
        {
            if (a[l] < a[r])
            {
                buf = a[l];
                l++;
                s.push_back('L');
            }
            else if(a[l] > a[r]){
                buf = a[r];
                r--;
                s.push_back('R');
            }
            else if (a[l] == a[r] && l != r)
            {
                
                if(l == r-1)
                s.push_back('R');
                int x = l, y = r;
                int size1 = 0, size2 = 0;
                while (a[x + 1] > a[x] && x + 1 < r)
                {
                    x++;
                    size1++;
                }
                while (a[y - 1] > a[y] && y - 1 > l)
                {
                    y--;
                    size2++;
                }
                if (size1 > size2)
                {
                    while (a[l + 1] > a[l] && l + 1 < r)
                    {
                        s.push_back('L');
                        l++;
                    }
                    s.push_back('L');
                    break;
                }
                else
                {
                    while(a[r-1] > a[r] && r-1 > l){
                        s.push_back('R');
                        r--;
                    }
                    s.push_back('R');
                    break;
                }
                
            }
        }
    }
    cout<<s.size()<<endl;
        for(auto val : s)
        cout<<val;
        auto end = chrono::high_resolution_clock::now();
        double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        time_taken *= 1e-9;
       // cout << fixed << time_taken;
        return 0;
    }