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
#define all(s) begin(s),end(s)
#define MIN3POS(a, b, c) (a) =< (b) ? ((a) =< (c) ? 1 : 3) : ((b) =< (c) ? 2 : 3)
#define MAX3POS(a,b,c) (a) >= (b) ? ((a) >= (c) ? 1 : 3) : ((b) >= (c) ? 2:3)
#define endl '\n'
#define int long long
#define forn(i, n) for (long long i = 0; i < long long(n); ++i)
#define IOS   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
vector<int> powers2(32,0);
void initialize(){ for(int i=1;i<powers2.size();i++) powers2[i] = powers2[i-1]*2;}
inline bool is_palindrome(const string &s) { return std::equal(s.begin(), s.end(), s.rbegin()); }
int k1,k2;
int dp[101][101][2][11] = {};
#define mod 100000000
int recur(int a,int b,int tog,int count){
    if(dp[a][b][tog][count] == -1){
    if(a == 0){
        if(tog == 1){
            if(count + b > k2)
            dp[a][b][tog][count] =  0;
            else
            dp[a][b][tog][count] =  1;
        }
       else  if(tog == 0){
            if(b > k2)
            dp[a][b][tog][count] = 0;
            else
            dp[a][b][tog][count] = 1;
        }
    }
    else if(b == 0){
        if(tog == 1){
            if(a > k1)
            dp[a][b][tog][count] =  0;
            else
            dp[a][b][tog][count] =  1;
        }
       else  if(tog == 0){
            if(count + a > k1)
            dp[a][b][tog][count] =  0;
            else
            dp[a][b][tog][count] =  1;
        }
    }
    else if(tog == 0){
        if(count == k1)
        dp[a][b][tog][count] =  recur(a,b-1,1-tog,1);
        else
        dp[a][b][tog][count] = recur(a-1,b,tog,count+1) + recur(a,b-1,1-tog,1);
    }
    else if(tog == 1){
        if(count == k2)
        dp[a][b][tog][count] = recur(a-1,b,1-tog,1);
        else
        dp[a][b][tog][count] = recur(a-1,b,1-tog,1) + recur(a,b-1,tog,count+1);
    }
    }
    return dp[a][b][tog][count]%mod;
}
int32_t main()  
{
auto start = chrono::high_resolution_clock::now();
IOS
int n1,n2;                                            
cin>>n1>>n2>>k1>>k2;
for(int i=0;i<101;i++){
    for(int j=0;j<101;j++){
        for(int h=0;h<2;h++){
            for(int k=0;k<11;k++)
            dp[i][j][h][k] = -1;
        }
    }
}
int sum = (recur(n1-1,n2,0,1) + recur(n1,n2-1,1,1))%mod;
cout<<sum<<endl;
auto end = chrono::high_resolution_clock::now();
double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
time_taken *= 1e-9;
//cout << fixed << time_taken;
return 0;
}