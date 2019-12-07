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
 string s;
int memo[10000][10000];
int count;
char chooseLetter(char x,char y){
    if((x == 'R' && y=='G') || (x=='G' &&y=='R') )
    return 'B';
    if((x== 'G' && y=='B') || (x=='B' && y == 'G'))
    return 'R';
    if((x=='B' && y=='R') || (x=='R' && y=='B'))
    return 'G';
    if(x=='R' && y=='R')
    return 'G';
    if(x=='G' && y=='G')
    return 'B';
    if(x=='B' && y =='B')
    return 'R';
}
int su(int l,int r){
    if(memo[l][r]!=-1)
    return memo[l][r];
    int n = r-l+1;
    if(n==1){
        memo[l][r] = 0;
        return 0;
    }
    if(n==2){
        if(s[r] ==s[l]){
            if(s[l]=='R')
            s[r]='G';
            else if(s[l]=='G')
            s[r]='B';
            else
            s[r] = 'R';
            memo[l][r] = 1;
        }
        return memo[l][r];
    }
    if(n & 1){
        char ch = s[n/2];
        memo[l][r] = su(l,l+n/2-1) +  su(l+n/2+1,l+n-1);
        if(ch == s[l+n/2-1] || ch ==s[l+n/2+1])
        {
             s[l+n/2] = chooseLetter(s[l+n/2-1],s[l+n/2+1]);
             memo[l][r]++;
        }

    }
    else
    {
        char ch = s[l+n/2-1];
        memo[l][r] = su(l,l+n/2-2) + su(l+n/2,l+n-1);
        if(ch == s[l+n/2-2] || ch == s[l+n/2]){
            s[l+n/2] = chooseLetter(s[l+n/2-2],s[l+n/2]);
            memo[l][r]++;
        }
    }
    

}
int32_t main()
{
IOS
 auto start = high_resolution_clock::now(); 
 int n;
 cin>>n;

 cin>>s;
 for(int i=0;i<n;i++){
     for(int j=0;j<n;j++)
     memo[i][j] == -1;
 }
su(0,n-1);
cout<<memo[0][n];
auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
return 0;
}