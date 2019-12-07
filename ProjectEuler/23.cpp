#include<bits/stdc++.h>
#include<chrono>
#define MAX 1000001
#define pii pair<int,int>
#define F first
#define S second
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define endl "\n"
#define int long long
#define forn(i,n) for(long long i = 0; i < long long (n); ++i)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }
const unsigned long long N = 1000000;
int lp[N + 1];
vector<int> pr;
void seive()
{
    for (int i = 2; i <= N; i++)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(lp[i]);
        }
        for (int j = 0; j < pr.size() && i * pr[j] <= N; j++)
            lp[i * pr[j]] = pr[j];
    }
}
int retSum(int n)
{
    int store = n;
    int cur = lp[n];
    int sum = 1;
    while (n != 1)
    {
        int cnt = 0;
        while (lp[n] == cur)
        {
            cnt++;
            n /= cur;
        }
        sum *= ((pow(cur, cnt + 1) - 1) / (cur - 1));
        cur = lp[n];
        // cout<<cnt<<endl;
        if (n == 1)
            break;
    }
    return sum - store;
}
int32_t main()
{
auto start = chrono::high_resolution_clock::now(); 
IOS
seive();
vector<int> v;
for(int i=1;i<28213;i++)   if(i < retSum(i) ) v.push_back(i);
int sum=0;
for(int i=1;i<=28213;i++){
    for(int j=1;j<=28213;j++){}
}
cout<<v.size()<<endl;
for(int i=1;i<28123;i++){
    int flag=0;
    int l=0,r=v.size()-1;
    while(l<=r){
        if(v[l] + v[r] == i){
            flag=1;
            break;
        }
        else if(v[l] + v[r] < i)
        l++;
        else if(v[l] + v[r]  > i)
        r--;
    }
    if(flag==0)
    sum+=i;
}
cout<<sum<<endl;
auto end = chrono::high_resolution_clock::now();
 double time_taken =  chrono::duration_cast<chrono::nanoseconds>(end - start).count();
 time_taken *= 1e-9; 
cout <<fixed<< time_taken << setprecision(9); 
return 0;
}