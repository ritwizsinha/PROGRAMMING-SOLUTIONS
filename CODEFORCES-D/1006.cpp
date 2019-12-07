//Very difficult
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
    string s1, s2;
    cin >> s1 >> s2;
    int count = 0;
    int l = 0, r = n - 1;
    while (l <= r)
    {  
        map<char,int > mp;
         if(l != r){
        mp[s1[l]]++;
        mp[s1[r]]++;
        mp[s2[l]]++;
        mp[s2[r]]++;
        int flag = 0;
            if(mp.size() == 4)
            count+=2;
            else if(mp.size() == 3){
            count+=(1 + (s1[l] == s1[r]));
            }
            else if(mp.size() == 2)
            count+= mp[s1[l]] !=2;
        }
        else{
            if(s1[l] != s2[r])
            count+=1;
        }
        l++;r--;
    }
    cout << count;
    return 0;
}
//try to think  a little and simplify the problem bastard !