#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define lOO 0x3f3f3f3f3f3f3f3f
int  n , m ;
///////////////////////////////////////////////////////////

//Topological Sorting
int n; // number of vertices
vector<int> ans;
vector<bool> visited;
vector<vector<int>> adj; // adjacency list of graph
void dfs(int v)
{
    visited[v] = true;
    for (int u : adj[v]) if (!visited[u]) dfs(u);
    ans.push_back(v);
}
void topological_sort()
{
    visited.assign(n, false);
    ans.clear();
    for (int i = 0; i < n; ++i) if (!visited[i]) dfs(i);
    reverse(ans.begin(), ans.end());
}