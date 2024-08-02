#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define lOO 0x3f3f3f3f3f3f3f3f
int  n , m ;
///////////////////////////////////////////////////////////

// Bellman & negative cycle
struct edge
{
    int a, b, cost;
};
const int INF = 1000000000;
int n, m, v, t;// v strat node , t target node
vector<edge> e;
void solve()
{
    vector<int> d(n, INF);
    d[v] = 0;
    vector<int> p(n, -1);
    int x;
    for (int i = 0; i < n; ++i)
    {
        x = -1;
        for (int j = 0; j < m; ++j)
            if (d[e[j].a] < INF)
                if (d[e[j].b] > d[e[j].a] + e[j].cost)
                {
                    d[e[j].b] = max(-INF, d[e[j].a] + e[j].cost);
                    p[e[j].b] = e[j].a;
                    x = e[j].b;
                }
    }
    if (x == -1) cout << "No negative cycle from " << v;
    else
    {
        int y = x;
        for (int i = 0; i < n; ++i)
            y = p[y];

        vector<int> path;
        for (int cur = y; ; cur = p[cur])
        {
            path.push_back(cur);
            if (cur == y && path.size() > 1)
                break;
        }
        reverse(path.begin(), path.end());

        cout << "Negative cycle: ";
        for (size_t i = 0; i < path.size(); ++i)
            cout << path[i] << ' ';
    }
}