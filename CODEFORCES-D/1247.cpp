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
#include<assert.h>
#define MAX 1000001
#define pii pair<int, int>
#define F first
#define S second
#define MIN3POS(a, b, c) (a) =< (b) ? ((a) =< (c) ? 1 : 3) : ((b) =< (c) ? 2 : 3)
#define MAX3POS(a,b,c) (a) >= (b) ? ((a) >= (c) ? 1 : 3) : ((b) >= (c) ? 2:3)
#define endl '\n'
#define int long long
#define forn(i, n) for (long long i = 0; i < long long(n); ++i)
#define IOS   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
inline bool is_palindrome(const string &s) { return std::equal(s.begin(), s.end(), s.rbegin()); }
const int N = 100001;
int lp[N+1] = {};
vector<int> pr;
void linear_seive(){
    for(int i=1;i<=N;i++){
        if(lp[i] == 0){
            lp[i] = i;
            pr.push_back(i);
        }
        for(int j=1;j<pr.size() && pr[j]<=lp[i] && i*pr[j]<=N;j++)
        lp[i*pr[j]] = pr[j];
    }
}
vector<bool> is_prime(N+1, true);
void main_seive(){
is_prime[0] = is_prime[1] = false;
for (int i = 2; i * i <= N; i++) {
    if (is_prime[i]) {
        for (int j = i * i; j <= N; j += i)
            is_prime[j] = false;
    }
}
}
int32_t main()
{
auto start = chrono::high_resolution_clock::now();
IOS
int n,k;
cin>>n>>k;
linear_seive();
vector<int> v(n),c(n,1);
for(int i=0;i<n;i++)
cin>>v[i];
sort(begin(v),end(v));
int count=0;
for(int i=0;i<n;i++){
    if(c[i]!=0){
        int num = v[i];
        c[i] = 0;
        map<int,int> mp2;
        while(num!=1){
            mp2[lp[num]]++;
            num/=lp[num];
        }
        
        int number = 1;
        for(auto val : mp2)
            number*=pow(val.first,k);
        
        number/=v[i];
        cout<<number<<endl;
        vector<int> v3(v);
        auto it = lower_bound(begin(v),end(v),number);
        if(it != v.end()){
            if(it == v.begin() + i){
                ++it;
                if(*it == number)
                count++,c[it-v.begin()] = 0;
            }
            else
            {
                count++,c[it-v.begin()] = 0;
            }
            
        }
    }
}
cout<<count<<endl;
auto end = chrono::high_resolution_clock::now();
double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
time_taken *= 1e-9;
//cout << fixed << time_taken;
return 0;
}