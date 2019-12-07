#include <bits/stdc++.h>
using namespace std;
struct Edge
{
    int a, b, cost;
};
struct places
{
    string s;
    int col;
};
int n, m;
vector<Edge> edges;
const int INF = 1000000000;
struct places place[10000];
void solve()
{
    vector<int> d(n);
    vector<int> p(n, -1);
    int x;
    for (int i = 0; i < n; ++i  )
    {
        x = -1;
        for (Edge e : edges)
        {
            if (d[e.a] + e.cost < d[e.b])
            {
                d[e.b] = d[e.a] + e.cost;
                p[e.b] = e.a;
                x = e.b;
            }
        }
    } 

    if (x == -1)
    {
        cout << "No negative cycle found.";
    }
    else
    {
        for (int i = 0; i < n; ++i)
        {
            x = p[x];
            // cout << "parent " << x << endl;
        }

        vector<int> cycle;
        for (int v = x;; v = p[v])
        {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());

        cout << "Negative cycle: ";
        for(int i=0;i< cycle.size()-1;i++)
        cout<<place[cycle[i]].s<<"->";
        int j = cycle.size();
        cout<<place[cycle[j-1]].s;
        cout << endl;
    }
}
int countPairs(string s1, string s2) 
{ 
    int count = 0;
  int freq[26] = {};
  int freq2[26] = {};
  for(auto ch : s1)
  freq[ch-'A']++;
  for(auto ch  : s2)
  freq2[ch-'A']++;
  for(int i=0;i<26;i++)
  if(freq[i] != 0 && freq2[i] != 0)
  count++;
  return count;
} 
  

int main()
{
    cin >> n;


    for (int i = 0; i < n; i++)
    {
        string color;
        cin >> place[i].s >> color;
        if (color == "green")
            place[i].col = 0;
        else if (color == "blue")
            place[i].col = 1;
        else
            place[i].col = 2;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            string s1 = place[i].s;
            string s2 = place[j].s;
            string s3 = s1;
            string s4 = s2;
            int count = 0;
            map<char,int> mp;
            int sum = s3.size() + s4.size();
            count = countPairs(s1,s2);
            if (count >= 2)
            {

                if (s3[count - 1] > s4[count - 1])
                {
                    struct Edge aa;
                    aa.a = j, aa.b = i;
                    // cout<<" i "<<i<<" j "<<j<<endl;
                    if (place[i].col == place[j].col)
                    {
                        aa.cost = -1 * sum;
                    }
                    else if (place[aa.a].col == 0 && place[aa.b].col == 1)
                    {
                        aa.cost = 2 * sum;
                    }
                    else
                        aa.cost = sum;
                    edges.push_back(aa);
                }
                else if (s3[count - 1] < s4[count - 1])
                {
                    struct Edge aa;
                    aa.a = i, aa.b = j;
                    if (place[i].col == place[j].col)
                    {
                        aa.cost = -1 * sum;
                    }
                    else if (place[aa.a].col == 0 && place[aa.b].col == 1)
                    {
                        aa.cost = 2 * sum;
                    }
                    else
                        aa.cost = sum;
                    edges.push_back(aa);    
                }
                else
                {
                    struct Edge aa;
                    if (s3.size() > s4.size())
                        aa.a = i, aa.b = j;
                    else if (s3.size() < s4.size())
                        aa.a = j, aa.b = i;
                    else 
                    {
                        cout << "please for the love of god enter strings of different length";
                        return 0;
                    }
                    if (place[i].col == place[j].col)
                    {
                        aa.cost = -1 * sum;
                    }
                    else if (place[aa.a].col == 0 && place[aa.b].col == 1)
                    {
                        aa.cost = 2 * sum;
                    }
                    else
                        aa.cost = sum;
                    edges.push_back(aa);
                }
            }
        }
    }

    solve();
    // for (Edge e : edges)
    // {
    //     cout << e.a << " " << e.b << " " << e.cost << endl;
    // }
    
}