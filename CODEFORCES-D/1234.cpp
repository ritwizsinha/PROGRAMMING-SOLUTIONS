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
#define forn(i, n) for (long long i = 0; i < long long(n); ++i)
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
string s;
vector<string> tree;

void build(int node, int l, int r)
{
    if (l == r)
    {
        string cnt(26, '0');
        cnt[(int)(s[l] - 'a')] = '1';
        tree[node] = cnt;
    }
    else
    {
        int mid = (l + r) / 2;
        build(2 * node + 1, l, mid);
        build(2 * node + 2, mid + 1, r);
        int first = 2 * node + 1, second = 2 * node + 2;
        string s(26, '0');
        for (int i = 0; i < 26; i++)
            if (tree[first][i] == '1' || tree[second][i] == '1')
                s[i] = '1';
        tree[node] = s;
    }
}
void update(int node, int l, int r, int pos, char val)
{
    if (l == r)
    {
        tree[node][(int)(s[pos] - 'a')] = '0';
        tree[node][(int)(val - 'a')] = '1';
    }
    else
    {
        int mid = (l + r) / 2;
        if (pos <= mid)
        {
            update(2 * node + 1, l, mid, pos, val);
        }
        else
            update(2 * node + 2, mid + 1, r, pos, val);
        int first = 2 * node + 1, second = 2 * node + 2;
        string s(26, '0');
        for (int i = 0; i < 26; i++)
            if (tree[first][i] == '1' || tree[second][i] == '1')
                s[i] = '1';
        tree[node] = s;
    }
}
string find(int node, int rl, int rr, int l, int r)
{
    if (rl > rr)
        return 0;
    
    if (rl == l && rr == r)
        return tree[node];
    int m = (l + r) / 2;
    if(rr <=m)
    return find(2*node+1,rl,rr,l,m);
    else if(rl>=m+1)
    return find(2*node+2,rl,rr,m+1,r);
    else {
     string s(26,'0');
    string s1 = find(2*node+1,rl,m,l,m);
    string s2 = find(2*node+2,m+1,rr,m+1,r);
    for(int i=0;i<26;i++){
        if(s1[i] == '1' || s2[i] == '1')
        s[i] = '1';
    }
    return s;
    }
}
int32_t main()
{
    auto start = chrono::high_resolution_clock::now();
    IOS
            cin >>
        s;

    int n = s.size();
    tree.resize(4 * n + 1);
    build(0, 0, n - 1);
    int q;
    cin >> q;
    while(q--){
        int choice ;
        cin>>choice;
        // cout<<"q "<<q<<endl;
        // cout<<choice<<endl;
        if(choice == 1){
            
            int pos;
            char ch;
            cin>>pos>>ch;
            update(0,0,n-1,pos-1,ch);
            s[pos-1] = ch;
        }
        else{
            int l,r;
            cin>>l>>r;
            string s3 = find(0,l-1,r-1,0,n-1);
             cout<<count(all(s3),'1')<<endl;
        }
    }
    // int pos;char c;
    // cin>>pos>>c;
    // update(0,0,n-1,pos-1,c);
    // for(auto val : tree)
    // {
    //     for(int i=0;i<26;i++)
    //     if(val[i] == '1')
    //     cout<<(char)(i+'a');
    //     cout<<endl;
    // }
    // auto end = chrono::high_resolution_clock::now();
    // double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    // time_taken *= 1e-9;
    // cout << fixed << time_taken;
    return 0;
}