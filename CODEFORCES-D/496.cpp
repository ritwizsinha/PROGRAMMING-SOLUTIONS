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
string s;
int cnt;
inline int a(char s){
    return (s-'0')%3;
}
// Using Greedy
// int32_t main()
// {
//     IOS
//     cin >>s;
//     int n = s.size();
//     int i = 0, count = 0;
//     while (i < n)
//     {
//         if (a(s[i]) == 0)
//         {
//             count++;
//             i++;
//         }
//         else if ((a(s[i]) + a(s[i+1]))%3 == 0)
//         {
//             i += 2;
//             count++;
//         }
//         else if (a(s[i]) == 1 && a(s[i+1]) == 1 && a(s[i+2]) == 1 || a(s[i]) == 2 && a(s[i+1]) ==2 && a(s[i+2]) ==2)
//         {
//             i += 3;
//             count++;
//         }
//         else
//         i++;
//     }
//     cout << count;
//     return 0;
// }



//Using Dp

int32_t main(){
    IOS
    cin>>s;
    
    return 0;
}