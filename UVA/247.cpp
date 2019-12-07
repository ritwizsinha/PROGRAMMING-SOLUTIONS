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
#define forn(i, n) for (long long i = 0; i < n; ++i)
#define IOS   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
vector<int> powers2(32,0);
void initialize(){ for(int i=1;i<powers2.size();i++) powers2[i] = powers2[i-1]*2;}
inline bool is_palindrome(const string &s) { return std::equal(s.begin(), s.end(), s.rbegin()); }
map<string,vector<string>> adj,transpose;
stack<string> st;
map<string,bool> visited;
map<int,vector<string>> res;
void dfsPushStack(string src){
    visited[src] = true;
    for(auto val : adj[src]){
        if(!visited[val])
        dfsPushStack(val),st.push(val);
    }
}
void normalDfs(string src){
    visited[src] = true;
    for(auto val : transpose[src]){
        if(!visited[val])
        normalDfs(val);
    }
}
void scc(){
    int k=0;
    while(!st.empty()){
        string name = st.top();
        st.pop();
        if(!visited[name]){
            res[k].push_back(name);
            normalDfs(name);
        }
        else{
            while(visited[name] && !st.empty()){
                res[k].push_back(name);
                name = st.top();
                st.pop();
            }
            k++;
        }
    }
}
int32_t main()
{
auto start = chrono::high_resolution_clock::now();
IOS
int n;
while(cin>>n){
    if(n == 0)break;
    adj.clear(),transpose.clear(),res.clear();
    visited = map<string,bool>();
    map<string,bool> visited2;
    int m;
    cin>>m;
    st = stack<string>();
    string start;
    forn(i,m){
        string s1,s2;
        cin>>s1>>s2;
        start = s1;
        adj[s1].push_back(s2);
        transpose[s2].push_back(s1);
        visited[s1] = false,visited[s2] = false;
        visited2[s1] = false,visited2[s2] = false;
    }
     dfsPushStack(start);
    visited = visited2;
    scc();
    for(auto [pos,str]: res){
        cout<<pos+1<<endl;
        for(auto val : str)
        cout<<val<<" ";
        cout<<endl;
    }
}   
auto end = chrono::high_resolution_clock::now();
double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
time_taken *= 1e-9;
cout << fixed << time_taken;
return 0;
}