//Done by myself
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
vector<int> powers2(33, 0);
void initialize()
{
    for (int i = 1; i < powers2.size(); i++)
        powers2[i] = powers2[i - 1] * 2;
}
inline bool is_palindrome(const string &s) { return std::equal(s.begin(), s.end(), s.rbegin()); }
int32_t main()
{
    auto start = chrono::high_resolution_clock::now();
    IOS int a, p;
    cin >> a >> p;
    int flag = 0;
    for (int j = 1; j <= 32; j++)
    {
        int n = a - p*j;
        if( n < 0){
            cout<<-1<<endl;
            return 0;
        }
        int count = __builtin_popcount(n);
        if (count > j)
            continue;
        else
        {
            int sum = 0;
            vector<int> v;
            while (n != 0)
            {
                if (n % 2 == 1)
                    v.push_back(sum);
                sum++;
                n /= 2;
            }
            if (count == j)
            {
                flag = 1;
                cout << j << endl;
                break;
            }
            else
            {
                int i = 0;
                while (j != count && i < v.size())
                {
                    while (v[i] != 0 && j != count)
                        v.push_back(v[i] - 1), v[i] -= 1, count++;
                    i++;
                }
                if (j != count)
                    continue;
                else
                {
                    flag=1;
                    cout << j;
                    break;
                }
            }
        }
    }
    if(flag == 0)
    cout<<-1;
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    //cout << fixed << time_taken;
    return 0;
}