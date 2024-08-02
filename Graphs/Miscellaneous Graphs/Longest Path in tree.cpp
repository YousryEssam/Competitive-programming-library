#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define lOO 0x3f3f3f3f3f3f3f3f
int  n , m ;
///////////////////////////////////////////////////////////


// longest path in a tree O(2*n);
int n, mx = 0, at = 0;
vector<int>vis;
vector<vector<int>>adj;
void DFS(int i, int cost)
{
    if (cost >= mx)
    {
        mx = cost;
        at = i;
    }
    vis[i] = 1;
    for (auto j : adj[i])
    {
        if (!vis[j])
            DFS(j, cost + 1);
    }
}
void solve()
{
    cin >> n;
    adj.resize(n + 3);
    vis.resize(n + 3);
    for (int i = 1; i < n; i++)
    {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // firist dfs 
    DFS(1, 0);
    // clar & resz vis
    vis.clear();
    vis.resize(n + 1, 0);
    // reset mx 
    mx = -1;
    DFS(at, 0);
    cout << mx << endl;
}