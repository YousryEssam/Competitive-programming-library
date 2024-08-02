#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(x) (int)x.size()
#define lOO 0x3f3f3f3f3f3f3f3f
///////////////////////////////////////////////////////////
int n, m, source, target;
vector<vector<pair<int, int >>>edge;
long long Dijkstra()
{
    vector<ll>distant(n + 1, lOO);// distant with initial value INF 
   priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>q;
    distant[source] = 0;
    q.push({ distant[source],source });
    ll ans = 0;
    while (!q.empty())
    {
        int v = q.top().second;
        int c = q.top().first;
        q.pop();
        if (v == target) 
            return distant[v];
        if (distant[v] != c) 
            continue;
        for (auto I : edge[v])
        {
            int u = I.second, uc = I.first;
            if (distant[u] > distant[v] + uc)
            {
                distant[u] = distant[v] + uc;
                q.push({ distant[u],u });
            }
        }
    }
    return -1; // if source can't reaches to target 
}