#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<chrono>
#define endl "\n"
#define int long long
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
using namespace std::chrono;
int32_t main()
{
IOS
 auto start = high_resolution_clock::now(); 
 int n;
 cin>>n;
 int a[n];
 for(int i=0;i<n;i++)
 cin>>a[i];
 int min = 999999999999;
 for(int i=0;i<n;i++){
     int num = a[i]/max(i+1,n-1-i);
     if(num<min)
     min=num;
 }
 cout<<min;
auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
//cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
return 0;
}