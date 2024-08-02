#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define lOO 0x3f3f3f3f3f3f3f3f
int  n , m ;
///////////////////////////////////////////////////////////


// Bellman&Retrieving Path 
struct edge{
    int a, b, cost;
};
const int INF = 1000000000;
int n, m, v, t;// v start node , t target node
vector<edge> e;
void solve(){
    vector<int> d(n, INF);
    d[v] = 0;
    vector<int> p(n, -1);

    for (;;)
    {
        bool any = false;
        for (int j = 0; j < m; ++j)
            if (d[e[j].a] < INF)
                if (d[e[j].b] > d[e[j].a] + e[j].cost)
                {
                    d[e[j].b] = d[e[j].a] + e[j].cost;
                    p[e[j].b] = e[j].a;
                    any = true;
                }
        if (!any)  break;
    }

    if (d[t] == INF)
        cout << "No path from " << v << " to " << t << ".";
    else
    {
        vector<int> path;
        for (int cur = t; cur != -1; cur = p[cur])
            path.push_back(cur);
        reverse(path.begin(), path.end());

        cout << "Path from " << v << " to " << t << ": ";
        for (size_t i = 0; i < path.size(); ++i)
            cout << path[i] << ' ';
    }
}