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
    string s, t;
    cin >> s >> t;
    string s1 = s;
    string s2 = t;
    sort(begin(s1), end(s1));
    sort(begin(s2), end(s2));
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (s1[i] != s2[i])
        {
            flag = 1;
            break;
        }
    }
if(flag==1){
    cout<<-1;
}
else{
    if(n==1)
    cout<<0;
    else{
    int count = 0, i = 0;
    vector<int> v;
    while (i < n)
    {
        if (s[i] != t[i])
        {
            int pos = find(begin(s) + i + 1, end(s), t[i]) - begin(s);

            while (s[i] != t[i])
            {
                v.push_back(pos);
                count++;
                int a = s[pos];
                s[pos] = s[pos - 1];
                s[pos - 1] = a;
                pos--;
            }
        }
        i++;
    }
        cout << count << endl;
        for (auto val : v)
            cout << val << " ";}
}
    return 0;
}