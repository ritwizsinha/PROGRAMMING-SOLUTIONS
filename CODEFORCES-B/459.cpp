#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<chrono>
#define endl \n
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
int arr[n];
 for(int i=0;i<n;i++)
 cin>>arr[i];
 sort(arr,arr+n);
 int l=0,r=n-1,count=0;
  int  init = arr[r]-arr[l];
 while(arr[r]-arr[l] == init && l<r){
     r--;l++;count++;
 }
 cout<<init<<" " <<count;
 int timepass=0;
 timepass++;
auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
//cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
return 0;
}
