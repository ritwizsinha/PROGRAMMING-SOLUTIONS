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
    IOS int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    map<int, int> dp;
    int ans = 0, pos;
    for (int i = 0; i < n; i++)
    {
        int x = arr[i];
        dp[x] = dp[x - 1] + 1;
        if (dp[x] > ans)
        {
            ans = dp[x];
            pos = x;
        }
    }
    cout << dp[pos];
    int index = find(begin(arr),end(arr),pos) - begin(arr);
    cout<<endl;
	vector<int> res;
	for (int i = n - 1; i >= 0; --i) {
		if (arr[i] == pos) {
			res.push_back(i+1);
			--pos;
		}
	}
	reverse(res.begin(), res.end());
	
    for(auto a : res)
    cout<<a<<" ";
    return 0;
}