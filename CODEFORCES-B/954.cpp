#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#define MIN3(a, b, c) (a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c))
#define endl "\n"
#define int long long
#define forn(i, n) for (long long i = 0; i < long long(n); ++i)
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
using namespace std;
using namespace std::chrono;
inline bool is_palindrome(const string &s) { return std::equal(s.begin(), s.end(), s.rbegin()); }
bool used = false;

int32_t main()
{
    IOS auto start = high_resolution_clock::now();
    int n;
    cin >> n;
    string s;
    cin >> s;
    int count=0,index,flag=0;
    int i;
    for(i=0;2*i<s.size();i++){
        string s1 = s.substr(0,i+1);
        string s2 = s.substr(i+1,i+1);
        // cout<<"s1 "<<s1<<endl<<"s2 "<<s2<<endl;
        if(s1 == s2){
            count = s1.size() + 1;
            index = i;
            flag=1;
        }
    }
    if(index == 0 || !flag)
    cout<<n;
    else
    cout<<count+ n-2*index-2;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    //cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
    return 0;
}