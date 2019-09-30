
#include <bits/stdc++.h>
using namespace std;
int dp[1000][1000];

int sum(string s1, string s2)
{
    return s1.length() + s2.length();
}

int editstr(string s1, string s2, int m, int n)
{

    if (m == 0)
        return n;
        
    if (n == 0)
    {
        return m;
    }else if(dp[m-1][n-1] != -1){
    	return dp[m-1][n-1];
	}
    else if (s1[m - 1] == s2[n - 1])
    {
        dp[m - 1][n - 1] = editstr(s1, s2, m - 1, n - 1);
    }
    else
    {
        dp[m - 1][n - 1] = 1 + min(editstr(s1, s2, m - 1, n), min(editstr(s1, s2, m, n - 1), editstr(s1, s2, m - 1, n - 1)));
    }
    return dp[m - 1][n - 1];
}

int similarity(string s1, string s2)
{
    return sum(s1, s2) - editstr(s1, s2, s1.length(), s2.length());
}

int main()
{
    string s1, s2;
    cout << "Enter gene1 : ";
    cin >> s1;
    cout << "Enter gene2 : ";
    cin >> s2;
    for(int i=0;i<1000;i++){
    	for(int j=0;j<1000;j++){
    		dp[i][j] = -1;
		}
	}
    int ans = similarity(s1, s2);
    cout << "Similiarity : " << ans << endl;
    int ans1 = editstr(s1, s2, s1.length(), s2.length());
    cout << "Number of operations required : " << ans1 << endl;
    return 0;
}
