#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <numeric>
#include<unordered_map>
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

    int n;
    cin >> n;
    string l, r;
    cin >> l >> r;
    unordered_map<char, vector<int>> ll;
    for (int i = 0; i < n; ++i) {
        ll[l[i]].push_back(i);
    }
    vector<int> rq;
    vector<pair<int,int> > result;
    for (int i = 0; i < n; ++i) {
        auto c = r[i];
        if (c == '?') {
            rq.emplace_back(i);
        } else if (!ll[c].empty()) {
            result.emplace_back(ll[c].back(), i);
            ll[c].pop_back();
        } else if (!ll['?'].empty()) {
            result.emplace_back(ll['?'].back(), i);
            ll['?'].pop_back();
        }
    }
    for (auto& it : ll) {
        while (!rq.empty() && !it.second.empty()) {
            result.emplace_back(it.second.back(), rq.back());
            it.second.pop_back();
            rq.pop_back();
        }
    }
    cout << result.size() << endl;
    for (auto p :result) {
        cout << p.first + 1 << ' ' << p.second + 1 << endl;
    }
    return 0;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}