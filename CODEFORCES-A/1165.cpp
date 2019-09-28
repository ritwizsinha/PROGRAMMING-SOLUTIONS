#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#define endl "\n"
#define int long long
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
using namespace std;
using namespace std::chrono;
int32_t main()
{
    IOS auto start = high_resolution_clock::now();
    int n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    //cout<<s;
    int count = 0;
    for (int i = 0; i < x; i++)
    {
        if (i < y)
        {
            if (s[i] == '1')
            {
                count++;
            }
        }
        else if (i == y)
        {
            if (s[i] == '0')
                count++;
        }
        else
        {
            if (s[i] == '1')
                count++;
        }
    }
    cout << count;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    //cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
    return 0;
}