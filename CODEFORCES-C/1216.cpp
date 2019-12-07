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
struct coord
{
    char s;
    int pos;
};
int32_t main()
{
    IOS int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;
    vector<int> v;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 >> x6 >> y6;

    int flag = 0;
    if(x1>=x3 && y1>=y3 && x2<=x4 && y2<=y4)
    flag=1;
    if(x1>=x5 && y1>=y5 && x2<=x6 && y2<=y6)
    flag=1;
    if (y4 >= y6)
    {   
        //cout<< (x5>=x2);
        if (y2 <= y4 && y1 >= y5 && y6>=y3 && x1 >= x5 && x1 >= x3 &&  x2<=x4 && x2<=x6)
            {flag = 1;//cout<<"runs1";
            }
    }
    else if( y4<=y6)
    {
        if (y2 <= y6 && y1 >= y3 && y4 >= y5 && x2 <= x6 && x2<=x4 && x1 >= x3 && x1>=x5)
            {flag = 1;//cout<<"run2";
            }
    }
    if (x6 >= x4)
    {
        if (x6 >= x2 && x4 >= x5 && y2 <= y6 && y2 <= y4 && x1 >= x3 && y1 >= y3 && y1 >= y5)
        {
            flag = 1;
       // cout<<"runs3";
        }
    }
    else if( x6 <=x4)
    {
        if (x2 <= x4 && x1 >= x5 && x6 >= x3 && y2 <= y4 && y2 <= y6 && y1 >= max(y3, y1))
            {flag = 1;///cout<<"runs4";
            }
    }
    if (flag)
        cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
    }

    return 0;
}