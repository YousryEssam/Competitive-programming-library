#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define lOO 0x3f3f3f3f3f3f3f3f
int  n , m ;
///////////////////////////////////////////////////////////

// Minimum spanning tree (MST)
vector<int>parent;
vector<pair<int, pair<int, int>>>edge;
int get_parent(int u)
{
    if (parent[u] == u) return u;
    return parent[u] = get_parent(parent[u]);
}
void join(int a, int b)
{
    a = get_parent(a);
    b = get_parent(b);
    if (a != b) parent[a] = b;
}
ll MST()
{
    ll ans = 0;
    iota(all(parent), 0);
    sort(all(edge));
    for (int i = 0; i < m; i++)
    {
        int a = edge[i].second.first;
        int b = edge[i].second.second;
        int c = edge[i].first;
        if (get_parent(a) != get_parent(b))
        {
            join(a, b);
            ans += c;
        }
    }
    return ans;
}