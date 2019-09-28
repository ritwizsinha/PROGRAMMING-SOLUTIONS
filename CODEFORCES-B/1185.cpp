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
     string s1,s2;
     int f(int l1,int l2){
         if(l1==0 && l2==0 && s1[l1]!=s2[l2])
         return 0;
         if(s1[l1]=='\0')
         {
             while(s1[l1-1]==s2[l2])
             l2++;
             if(s2[l2]!='\0')
             return 0;
             return 1;
         }
         if(s1[l1] == s2[l2])
         {
             l1++;l2++;
             return f(l1,l2);
         }
         if(s1[l1] !=s2[l2] && s1[l1-1] == s2[l2]){
             while(s1[l1-1] == s2[l2])
             l2++;
             return f(l1,l2);
         }
         else
         return 0;

     }
int32_t main()
{
IOS
 auto start = high_resolution_clock::now(); 
 int t;
 cin>>t;
 while(t--){
     cin>>s1>>s2;
    int bo = f(0,0);
    if(bo==1)
    cout<<"YES"<<endl;
    else
    {
        cout<<"NO"<<endl;
    }
    
     
 }
auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
return 0;
}