#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<chrono>
#include<bits/stdc++.h>
#define endl "\n"
#define int long long
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
using namespace std::chrono;  
    
vector<int> aw;
int h[1000000] = {0};
int32_t main()
{
IOS
int n;
cin>>n;
for(int i=0;i<n;i++){
    int a,b;
    cin>>a>>b;
    aw.push_back(b);
    h[a]++;
}
for (int i = 0; i < n; i++)
{
    int x = h[aw[i]];
    cout<<n-1+x<<" "<<n-1-x<<endl;
}

 auto start = high_resolution_clock::now(); 
auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
//cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
return 0;
}