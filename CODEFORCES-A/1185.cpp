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
 int a[3];
 for(int i=0;i<3;i++)
 cin>>a[i];
 int d;
 cin>>d;
 sort(a,a+3);
 int count=0;
 if(a[1]-a[0]<d)
 count += d - abs(a[1]-a[0]);
 if(a[2]-a[1]<d) 
 count+= d - abs(a[2]-a[1]);
 cout<<count;
auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
//cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
return 0;
}