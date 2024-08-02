#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define mem(arr, value) memset(arr, value, sizeof(arr))
#define oo 0x3f3f3f3f3f3f3f3f
///////////////////////////////////////////////////////////

struct edge{
    int to,w,from;
    edge(int from,int to,int w):from(from),to(to),w(w) {}
    bool operator < (const edge&e) const {
        return w>e.w;
    }

};

vector<vector<edge>>adj(26);
int dijkstra(int s,int d)
{
    vector<int>dis(26,oo);
    dis[s]=0;
    priority_queue<edge>q;
    q.push(edge(-1,s,0));
    while(!q.empty()){
        edge par=q.top();
        q.pop();
        if(par.w>dis[par.to])continue;
        for(auto it:adj[par.to])
        {
            if(dis[it.to]>dis[it.from]+it.w)
            {
                it.w=dis[it.to]=dis[it.from]+it.w;
                q.push(it);
            }
        }
    }
    return dis[d];
}