
#include<bits/stdc++.h>
using namespace std;
///////////////////////////////////////////////////////////////////

const int V  = 1e6 + 9 ;
struct node{
    int to, weight;
};
// vector to store edges
vector <node> edges[V];
// Prints shortest distance from given source to
// every other vertex
void zeroOneBFS(int src){
    // Initialize distances from given source
    int dist[V];
    for (int i=0; i<V; i++)dist[i] = INT_MAX;
    // double ende queue to do BFS.
    deque<int> Q;
    dist[src] = 0;
    Q.push_back(src);
    while (!Q.empty()){
        int v = Q.front();
        Q.pop_front();
        for (int i=0; i<edges[v].size(); i++){
            // checking for the optimal distance
            if (dist[edges[v][i].to] > dist[v] + edges[v][i].weight){
                dist[edges[v][i].to] = dist[v] + edges[v][i].weight;
                // Put 0 weight edges to front and 1 weight
                // edges to back so that vertices are processed
                // in increasing order of weights.
                if (edges[v][i].weight == 0)
                    Q.push_front(edges[v][i].to);
                else
                    Q.push_back(edges[v][i].to);
            }
        }
    }
}