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
inline bool is_palindrome(const string &s) { return std::equal(s.begin(), s.end(), s.rbegin());}
int dp[3010][3010];
string s1,s2;
int lcs(int l1,int l2){
    if(dp[l1][l2] == 0){
        if(l1<= 0 || l2 <= 0)
        return 0;
        if(s1[l1-1] == s2[l2-1])
        dp[l1][l2] = lcs(l1-1,l2-1) + 1;     
        else
        dp[l1][l2] = max(lcs(l1-1,l2),lcs(l1,l2-1));
    }
    return dp[l1][l2];
}
int32_t main()
{
auto start = chrono::high_resolution_clock::now();
IOS

cin>>s1>>s2;
lcs(s1.size(),s2.size());
for(int i=1;i<=s1.size();i++){
    for(int j=1;j<=s2.size();j++){
        if(s1[j-1] == s2[j-1])
        dp[i][j] = dp[i-1][j-1] + 1;
        else
        {
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
        
    }
}
int i = s1.size(),j = s2.size();
int index = dp[i][j];
vector<char> lcss(index);
 while (i > 0 && j > 0) 
   { 

      if (s1[i-1] == s2[j-1]) 
      { 
          lcss[index-1] = s1[i-1];
          i--; j--; index--;    
      } 
      else if (dp[i-1][j] > dp[i][j-1]) 
         i--; 
      else
         j--; 
   } 
for(auto  s : lcss)
cout<<s;
auto end = chrono::high_resolution_clock::now();
double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
time_taken *= 1e-9;
//cout << fixed << time_taken;
return 0;
}