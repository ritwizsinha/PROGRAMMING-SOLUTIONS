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

void SieveOfEratosthenes(int n) 
{ 
    vector<int> prime(n+1,true);
    
    for (int p=3; p*p<=n; p+=2) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
    int count=0;
    for (int p=2; p<=n; p++) 
       if (p==2 || (prime[p] && p%2!=0)){
           count++;
           if(count%100 ==1)
           cout<<p<<endl; 
       } 
} 

int32_t main()
{
IOS
 auto start = high_resolution_clock::now(); 
int n=100000000;
SieveOfEratosthenes(n);

auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
return 0;
}